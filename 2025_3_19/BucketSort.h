#pragma once
#include <iostream>
#include <vector>
#include "sort.h"
#include <algorithm>
#include <climits>
using namespace std;


//使用插入排序的桶排序
//和快速排序与归并排序很像，都是先分别排序，然后合并在一起再排序
void bucketSort1(vector<int>& nums, int bucketCount)
{
	//先找到最大和最小元素
	//用于计算索引偏移量和除数
	int min = -1000000, max = 1000000;//具体的数据根据实际情况调整
	for (int num : nums)
	{
		min = std::min(min, num);
		max = std::max(max, num);
	}

	int offset = -min;

	//计算理论上每一个桶需要装的元素个数
	int bucketSize = (max - min) / bucketCount + 1;

	//初始化一个大桶，其每一个元素都是一个小桶
	vector<vector<int>> buckets(bucketCount);
	for (int i = 0; i < bucketCount; i++)
	{
		buckets[i] = vector<int>();
	}

	//将元素分配到对应的桶中
	for (int num : nums)
	{
		//用除法向下取整的方式计算桶的索引
		int index = (num + offset) / bucketSize;
		buckets[index].push_back(num);
	}

	//对每一个桶中的元素进行排序
	for (int i = 0; i < bucketCount; i++)
	{
		insertSort(buckets[i]);//每一个小桶具体的排序可以使用插入排序
	}

	//合并有序桶
	int index = 0;
	for (int i = 0; i < bucketCount; i++)
	{
		for (int num : buckets[i])
		{
			nums[index++] = num;
		}
	}
}


//使用递归的桶排序算法
void insertionSort(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void bucketSort2(std::vector<int>& nums, int bucketCount) {
    if (nums.empty() || nums.size() <= 1) {
        return;
    }

    // 一开始判断所有元素是否有序
    bool sorted = true;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        return;
    }

    // 先找到最大和最小元素
    int min = nums[0], max = nums[0];
    for (int num : nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    // 计算理论上每一个桶需要装的元素个数
    int bucketSize = (max - min + 1) / bucketCount;
    if ((max - min + 1) % bucketCount != 0) {
        bucketSize++;
    }

    // 初始化一个大桶，其每一个元素都是一个小桶
    std::vector<std::vector<int>> buckets(bucketCount);

    // 将元素分配到对应的桶中
    for (int num : nums) {
        int index = (num - min) / bucketSize;
        if (index >= bucketCount) {
            index = bucketCount - 1;
        }
        buckets[index].push_back(num);
    }

    // 对每一个桶中的元素进行排序
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].size() <= 10) { // 假设10是一个阈值
            insertionSort(buckets[i]);
        }
        else {
            bucketSort2(buckets[i], bucketCount);
        }
    }

    // 合并有序桶
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int num : buckets[i]) {
            if (index < nums.size()) {
                nums[index++] = num;
            }
        }
    }
}


//测试桶排序
void testBucketSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };

	//使用插入排序的桶排序,这里分成四个桶
	//桶的数量越多，算法的时间复杂度越低
	bucketSort2(test,4);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}