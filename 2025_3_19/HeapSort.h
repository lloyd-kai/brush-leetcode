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


//�󶥶ѵ��³�����
void maxHeapSink(vector<int>& heap, int node, int size)
{
	while (left(node) < size || right(node) < size)
	{
		//�Ƚ��Լ������Ҷ˵�˭���
		//��С���ѵ��߼��෴
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

//�����������Ԫ�ش�С��������
void sort(vector<int>& nums)
{
	//��һ����ԭ�ؽ����ѣ�
	//�������Ҷ�ÿһ��Ԫ�ص���swi�������Ϳ���ԭ�ؽ���
	for (int i = 0; i < nums.size(); i++)
	{
		minHeapSwim(nums, i);
	}

	//�ڶ�������ʼ����
	int heapSize = nums.size();
	while (heapSize > 0)
	{
		//�ӶѶ���ɾ��Ԫ�أ����ڶѵĺ���,������ÿ�ζ�ȷ��һ������λ�õ�Ԫ��
		//�������ص��Ǵ�С���������
		swap(nums, 0, heapSize - 1);
		heapSize--;
		//�ָ��ѵ�����
		maxHeapSink(nums, 0, heapSize);
		// ���� nums[0..heapSize) ��һ���󶥶ѣ�nums[heapSize..) ������Ԫ��
	}
}


//�������Ż�
void HeapSortImprove(vector<int>& nums)
{
	//ͬ���ĵ�һ������ͬ���Ǵ����һ����Ҷ�ӽڵ㿪ʼ�������³�ֱ�����е���������һ������ѡ�
	//��Ϊ֮ǰ���㷨����ֻ��֤���ڵ���޷���֤������"������"
	//�Ż�֮����һ���̶������Ч��
	int n = nums.size();
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		maxHeapSink(nums, i, n);
	}

	//�ϲ���ɣ��������������Ѿ���һ���󶥶�
	int heapSize = n;
	while (heapSize > 0)
	{
		// �ӶѶ�ɾ��Ԫ�أ��ŵ��ѵĺ���
		swap(nums, 0, heapSize - 1);
		heapSize--;
		// �ָ��ѵ�����
		maxHeapSink(nums, 0, heapSize);
		// ���� nums[0..heapSize) ��һ���󶥶ѣ�nums[heapSize..) ������Ԫ��
	}
}


//���������
void testHeapSort(void)
{
	vector<int>test = { 2,3,1,0,2,2,-4,-1,3,0 };
	HeapSortImprove(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " \n"[i == test.size() - 1];
	}
}