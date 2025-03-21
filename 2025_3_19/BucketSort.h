#pragma once
#include <iostream>
#include <vector>
#include "sort.h"
#include <algorithm>
#include <climits>
using namespace std;


//ʹ�ò��������Ͱ����
//�Ϳ���������鲢������񣬶����ȷֱ�����Ȼ��ϲ���һ��������
void bucketSort1(vector<int>& nums, int bucketCount)
{
	//���ҵ�������СԪ��
	//���ڼ�������ƫ�����ͳ���
	int min = -1000000, max = 1000000;//��������ݸ���ʵ���������
	for (int num : nums)
	{
		min = std::min(min, num);
		max = std::max(max, num);
	}

	int offset = -min;

	//����������ÿһ��Ͱ��Ҫװ��Ԫ�ظ���
	int bucketSize = (max - min) / bucketCount + 1;

	//��ʼ��һ����Ͱ����ÿһ��Ԫ�ض���һ��СͰ
	vector<vector<int>> buckets(bucketCount);
	for (int i = 0; i < bucketCount; i++)
	{
		buckets[i] = vector<int>();
	}

	//��Ԫ�ط��䵽��Ӧ��Ͱ��
	for (int num : nums)
	{
		//�ó�������ȡ���ķ�ʽ����Ͱ������
		int index = (num + offset) / bucketSize;
		buckets[index].push_back(num);
	}

	//��ÿһ��Ͱ�е�Ԫ�ؽ�������
	for (int i = 0; i < bucketCount; i++)
	{
		insertSort(buckets[i]);//ÿһ��СͰ������������ʹ�ò�������
	}

	//�ϲ�����Ͱ
	int index = 0;
	for (int i = 0; i < bucketCount; i++)
	{
		for (int num : buckets[i])
		{
			nums[index++] = num;
		}
	}
}


//ʹ�õݹ��Ͱ�����㷨
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

    // һ��ʼ�ж�����Ԫ���Ƿ�����
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

    // ���ҵ�������СԪ��
    int min = nums[0], max = nums[0];
    for (int num : nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    // ����������ÿһ��Ͱ��Ҫװ��Ԫ�ظ���
    int bucketSize = (max - min + 1) / bucketCount;
    if ((max - min + 1) % bucketCount != 0) {
        bucketSize++;
    }

    // ��ʼ��һ����Ͱ����ÿһ��Ԫ�ض���һ��СͰ
    std::vector<std::vector<int>> buckets(bucketCount);

    // ��Ԫ�ط��䵽��Ӧ��Ͱ��
    for (int num : nums) {
        int index = (num - min) / bucketSize;
        if (index >= bucketCount) {
            index = bucketCount - 1;
        }
        buckets[index].push_back(num);
    }

    // ��ÿһ��Ͱ�е�Ԫ�ؽ�������
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].size() <= 10) { // ����10��һ����ֵ
            insertionSort(buckets[i]);
        }
        else {
            bucketSort2(buckets[i], bucketCount);
        }
    }

    // �ϲ�����Ͱ
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int num : buckets[i]) {
            if (index < nums.size()) {
                nums[index++] = num;
            }
        }
    }
}


//����Ͱ����
void testBucketSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };

	//ʹ�ò��������Ͱ����,����ֳ��ĸ�Ͱ
	//Ͱ������Խ�࣬�㷨��ʱ�临�Ӷ�Խ��
	bucketSort2(test,4);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}