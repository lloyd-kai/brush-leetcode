#pragma once
#include <iostream>
#include <vector>

using namespace std;

//选择排序的实现
//时间复杂度为O(n^2)
void sort1(vector<int>& nums)
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
void sort2(vector<int>& nums)
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

//对选择排序的再一次优化，在找最小值的同时交换，避免多余的for循环
//这种排序有另外的名字，没错，就是冒泡排序
//数据结构中的冒泡排序是两个for，不过思想是一样的
void bubbleSort1(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//寻找nums[sortedIndex...]中的最小值
		//同时将最小值同步移动到nums[sortedIndex]的位置
		for (int i = n - 1; i > sortedIndex; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
		}
		sortedIndex++;
	}
}


//优化后的冒泡排序，在有序的情况下提前终止程序，减少比较的次数
void bubbleSort2(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		//寻找nums[sortedIndex...]中的最小值
		//同时将最小值同步移动到nums[sortedIndex]的位置
		//添加一个bool变量，用于记录一趟中是否交换过一次
		bool swapped = false;
		for (int i = n - 1; i > sortedIndex; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
				swapped = true;//交换过就置为真
			}
		}
		//如果一趟中一次都没有交换过，说明已经有序
		if (!swapped)
		{
			break;
		}

		sortedIndex++;
	}

}


//对选择排序的优化，向左侧已经有序的位置中插入元素
//也就是插入排序
void insertSort(vector<int>& nums)
{
	int n = nums.size();
	int sortedIndex = 0;
	while (sortedIndex < n)
	{
		for (int i = sortedIndex; i > 0; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
			else
			{
				break;
			}
		}
		sortedIndex++;
	}
}


//希尔排序，对h有序数组进行插入排序
//逐渐缩小h，最后h=1的时候，完成整个数组的排序
//这里使用算法导论中的h，也就是间隔为3的k-1次方数，在大多数情况下效率更高
void shellSort(vector<int>& nums)
{
	int n = nums.size();
	//我们使用的生成函数是3^(k-1)
	int h = 3;
	while (h < n / 3)
	{
		h = 3 * h;
	}

	//改动一，AB插入排序的主要逻辑套入h的while循环汇总
	while (h >= 1)
	{
		//将sortedIndex初始化为h而不是1
		int sortedIndex = h;
		while (sortedIndex < n)
		{
			//交换的步长改为h而不是1
			for (int i = sortedIndex; i >= h; i -= h)
			{
				if (nums[i] < nums[i - h])
				{
					int temp = nums[i];
					nums[i] = nums[i - h];
					nums[i - h] = temp;
				}
				else
				{
					break;
				}
			}
			sortedIndex++;
		}
		h /= 3;
	}
}







//测试排序算法
void test(void)
{
	vector<int>data;
	for (int i = 10; i > 0; i--)
	{
		data.push_back(i);
	}

	//测试冒泡排序
	//bubbleSort1(test);

	//测试优化后的冒泡排序
	//bubbleSort2(test);

	//测试插入排序
	//insertSort(data);

	//测试希尔排序
	shellSort(data);


	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " \n"[i == data.size() - 1];
	}

}