#pragma once
#include <iostream>
#include <vector>
using namespace std;

//基数排序
//就是对多位数的排序，从最低位比较，直到最高位
//基数排序分为从高位到低位（Most Significant Digit first，简称 MSD）
//从低位到高位（Least Significant Digit first，简称 LSD）两种。
//常用的就是MSD，主要应用就是字典序
//这里先写LSD，后续会写MSD


//基数排序中使用计数排序的排序算法，和一般的计数排序不同
//首先要确保nums中的元素都是非负数
//k是当前需要排序的位数
void countSort(vector<int>& nums, int k)
{
	//基数排序中每一位十进制数的取值范围是0-9
	vector<int> count(10, 0);

	//对每一个元素的第k位进行计数
	for (int num : nums)
	{
		int digit = (num / static_cast<int>(pow(10, k))) % 10;
		count[digit]++;
	}

	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	//按照第k位的值 对元素进行排序
	vector<int> sorted(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int digit = (nums[i] / static_cast<int>(pow(10, k))) % 10;
		sorted[count[digit] - 1] = nums[i];
		count[digit]--;
	}

	//把排序结果复制回源数组
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = sorted[i];
	}
}

void radixSortLSD(vector<int>& nums)
{
	int min = INT_MAX;
	for (int num : nums)
	{
		min = std::min(min, num);
	}

	//根据最小元素，将所有元素转化为从0开始的非负数
	int offset = -min;
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] += offset;
	}

	int max = INT_MAX;
	for (int num : nums)
	{
		max = std::max(max, num);
	}

	//计算最大元素的位数
	int maxLen = 0;
	while (max > 0)
	{
		max /= 10;
		maxLen++;
	}

	//从低位到高位，依次对每一位进行计数排序
	for (int k = 0; k < maxLen; k++)
	{
		countSort(nums, k);
	}

	//将所有元素转化回原来的值
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] -= offset;
	}
}



//测试基数排序
void testRadixSort(void)
{
	vector<int>test = { 200,312,145,0,22,27,-40,-123,374,235,235 };

	//测试基数排序
	radixSortLSD(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}