#pragma once
#include <iostream>
#include <vector>
using namespace std;

//堆排序的实现
//实质是借用了二叉堆的数据结构思想

//相关的工具函数
//父节点的索引
int parent(int node)
{
	return (node - 1) / 2;
}

//左孩子的索引
int left(int node)
{
	return node * 2 + 1;
}

//右孩子的索引
int right(int node)
{
	return node * 2 + 2;
}

//交换数组中两个元素的位置
void swap(vector<int>& heap, int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

//小顶堆的上浮操作，时间复杂度是树高O(logN)
void minHeapSwim(vector<int>& heap, int node)
{
	while (node > 0 && heap[parent(node)] > heap[node])
	{
		swap(heap, parent(node), node);
		node = parent(node);
	}
}

//小顶堆的下沉操作
void minHeapSink(vector<int>& heap, int node, int size)
{
	while (left(node) < size || right(node) < size)
	{
		int min = node;
		if (left(node) < size && heap[left(node)] < heap[min])
		{
			min = left(node);
		}
		if (right(node) < size && heap[right(node)] < heap[min])
		{
			min = right(node);
		}
		if (min == node)
		{
			break;
		}
		//如果左右节点有比自己小的就交换
		swap(heap, node, min);
		node = min;
	}
}


//大顶堆的下沉操作
void maxHeapSink(vector<int>& heap, int node, int size)
{
	while (left(node) < size || right(node) < size)
	{
		//比较自己和左右端点谁最大
		//和小顶堆的逻辑相反
		int max = node;
		if (left(node) <size && heap[left(node)] >heap[max])
		{
			max = left(node);
		}
		if (right(node) < size && heap[right(node)] > heap[max])
		{
			max = right(node);
		}

		if (max == node)
		{
			break;
		}
		swap(heap, node, max);
		node = max;
	}
}

//将输入的数组元素从小到大排序
void sort(vector<int>& nums)
{
	//第一步，原地建立堆，
	//从左往右对每一个元素调用swi方法，就可以原地建堆
	for (int i = 0; i < nums.size(); i++)
	{
		minHeapSwim(nums, i);
	}

	//第二步，开始排序，
	int heapSize = nums.size();
	while (heapSize > 0)
	{
		//从堆顶部删除元素，放在堆的后面,这样就每次都确定一个最终位置的元素
		//这样返回的是从小到大的序列
		swap(nums, 0, heapSize - 1);
		heapSize--;
		//恢复堆的性质
		maxHeapSink(nums, 0, heapSize);
		// 现在 nums[0..heapSize) 是一个大顶堆，nums[heapSize..) 是有序元素
	}
}


//堆排序优化
void HeapSortImprove(vector<int>& nums)
{
	//同样的第一步，不同的是从最后一个非叶子节点开始，依次下沉直到所有的子树都是一个二叉堆。
	//因为之前的算法都是只保证根节点而无法保证子树的"有序性"
	//优化之后能一定程度上提高效率
	int n = nums.size();
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		maxHeapSink(nums, i, n);
	}

	//合并完成，现在整个数组已经是一个大顶堆
	int heapSize = n;
	while (heapSize > 0)
	{
		// 从堆顶删除元素，放到堆的后面
		swap(nums, 0, heapSize - 1);
		heapSize--;
		// 恢复堆的性质
		maxHeapSink(nums, 0, heapSize);
		// 现在 nums[0..heapSize) 是一个大顶堆，nums[heapSize..) 是有序元素
	}
}


//堆排序测试
void testHeapSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };
	HeapSortImprove(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}