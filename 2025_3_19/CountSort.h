#pragma once
#include <iostream>
#include <vector>
using namespace std;


//计数排序的实现
void countSort(vector<int>& nums)
{
	//先找到最小元素和最大元素
	//计算索引的偏移量和count数组大小
	int min = -1000000,max = 1000000;//根据实际情况适当选择合适的值,最好不要设置成某一数据类型的最值，很有可能会溢出
	for (int i = 0; i < nums.size(); i++)
	{
		min = std::min(min, nums[i]);
		max = std::max(max, nums[i]);
	}

	//根据最小值和最大值，将元素映射到0开始的索引值
	//和hash有点像，但这里的映射逻辑是将其映射为索引，所以是非负数
	int offset = -min;
	vector<int> count(max - min + 1);

	//第一次遍历先统计每一个元素出现的次数
	for (int num : nums)
	{
		count[num + offset]++;
	}

	//累加count数组中每一个元素，得到的是nums[i]在排序后数组的结束位置
	//比如count[1,5] 索引为1时元素为5，表明索引区间[1,5)都是某一个值相同的元素
	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	//根据每个元素排序后的索引位置，完成排序
	//要从后往前遍历，保证排序的稳定性
	vector<int> sorted(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		//借用sorted数组排序
		sorted[count[nums[i] + offset] - 1] = nums[i];
		count[nums[i] + offset]--; 
	}

	//把排序结构复制回原数组
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = sorted[i];
	}
}


//测试计数排序
void testCountSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };
	countSort(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}