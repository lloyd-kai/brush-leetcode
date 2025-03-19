#pragma once
#include <iostream>
#include <vector>

using namespace std;

//选择排序的实现
//时间复杂度为O(n^2)
void sort(vector<int>& nums)
{
	int n = nums.size();
	//其中sortedIndex是一个分割线
	//索引 < sortedIndex的元素都是已经排序后的
	//索引 >= sortedIndex的元素都是未排序的
	int sortedIndex = 0;//初始化为所有元素都没有排序
	while (sortedIndex < n)
	{
		//先找到[sortedIndex,n)中的最小值
		int minIndex = sortedIndex;
		for (int i = sortedIndex + 1; i < n; i++)
		{
			if (nums[i] < nums[minIndex])
			{
				minIndex = i;
			}
		}
		//交换最小值和sortedIndex处的元素
		int temp = nums[sortedIndex];
		nums[sortedIndex] = nums[minIndex];
		nums[minIndex] = temp;

		sortedIndex++;
	}
}


//选择排序的优化-将其优化为稳定排序
void sort(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//先找到[sortedIndex,n)中的最小值
		int minIndex = sortedIndex;
		for (int i = sortedIndex + 1; i < n; i++)
		{
			if (nums[i] < nums[minIndex])
			{
				minIndex = i;
			}
		}

		//交换最小值和sortedIndex处的元素
		//优化
		//将nums[sortedIndex,minIndex]的元素整体向后移动一位
		int minVal = nums[minIndex];
		//数组迁移数据的操作
		for (int i = minIndex; i > sortedIndex; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[sortedIndex] = minVal;

		sortedIndex++;
	}
}