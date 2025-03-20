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