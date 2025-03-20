#pragma once
#include <iostream>
#include <vector>
using namespace std;

//�������ʵ��
//ʵ���ǽ����˶���ѵ����ݽṹ˼��

//��صĹ��ߺ���
//���ڵ������
int parent(int node)
{
	return (node - 1) / 2;
}

//���ӵ�����
int left(int node)
{
	return node * 2 + 1;
}

//�Һ��ӵ�����
int right(int node)
{
	return node * 2 + 2;
}

//��������������Ԫ�ص�λ��
void swap(vector<int>& heap, int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

//С���ѵ��ϸ�������ʱ�临�Ӷ�������O(logN)
void minHeapSwim(vector<int>& heap, int node)
{
	while (node > 0 && heap[parent(node)] > heap[node])
	{
		swap(heap, parent(node), node);
		node = parent(node);
	}
}

//С���ѵ��³�����
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
		//������ҽڵ��б��Լ�С�ľͽ���
		swap(heap, node, min);
		node = min;
	}
}