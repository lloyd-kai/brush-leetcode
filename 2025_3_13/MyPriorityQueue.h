#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
#include <iostream>
using namespace std;

//���ȼ����е�ʵ��-������Ĵ洢�ṹ���������߼��ṹʵ��
//ǰ������ȫ����������Ϊ��ȫ������Ԫ���������ģ������������������ŷ�
template <typename T>
class MyPriorityQueue
{
private:
	//������
	std::vector<T>heap;

	//����Ԫ�ص�����
	int size;

	//Ԫ�رȽ���
	std::function<bool(const T&, const T&)> comparator;

	//���ڵ������
	//���ɺͶ�������һ��������������0��ʼ
	//�Լ���һ������Ȼ��������У������ݽṹ�����Һ��ӽڵ��󷨻��ǲ�һ����
	int parent(int node)
	{
		return (node - 1) / 2;
	}

	//���ӽڵ������
	int left(int node)
	{
		return node * 2 + 1;
	}

	//�Һ��ӽڵ������
	int right(int node)
	{
		return node * 2 + 2;
	}

	//�������������Ԫ��
	void swap(int i, int j)
	{
		std::swap(heap[i], heap[j]);
	}

	//�����ѵĴ�С
	void resize(int capacity)
	{
		if (capacity > size)
		{
			heap.resize(capacity);
		}
	}


	//�ϸ�������ʱ�临�Ӷ�������O(logn)
	//����׷��һ���ڵ㣬ֱ�����ϸ������ʵ�λ��
	void swim(int node)
	{
		//����ڵ�ȸ��ڵ�ֵҪС
		while (node > 0 && comparator(heap[parent(node)], heap[node]))
		{
			swap(parent(node), node);
			node = parent(node);
		}
	}

	//�³�������ʱ�临�Ӷ�Ϊ����O(logN)
	void sink(int node)
	{
		while (left(node) < size || right(node) < size)
		{
			//�Ƚ��Լ��������ӽڵ㣬����Сֵ
			int min = node;
			if (left(node) < size && comparator(heap[min], heap[left(node)]))
			{
				min = left(node);
			}
			if (right(node) < size && comparator(heap[min], heap[right(node)]))
			{
				min = right(node);
			}
			//�����ǰ�ڵ���ӽڵ㶼С
			if (min == node)
			{
				break;
			}

			//����Сֵ����
			swap(node, min);
			//�����³�
			node = min;
		}
	}
public:
	//���캯��
	MyPriorityQueue(int capacity, std::function<bool(const T&, const T&)>compator)
		:heap(capacity), size(0), comparator(std::move(compator)) {};

	//���ضѵĴ�С
	int getSize() const
	{
		return size;
	}

	//�ж϶��Ƿ�Ϊ��
	bool isEmpty() const
	{
		return size == 0;
	}

	//����Ԫ��,���ضѶ���Ԫ�أ���ʱ�临�Ӷ���O(1)
	const T& peek() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("Priority queue underflow");
		}
		return heap[0];
	}

	//����в���һ��Ԫ�أ�ʱ�临�Ӷ�ΪO(logN)
	void push(const T& x)
	{
		//����
		if (size == heap.size())
		{
			resize(2 * heap.size());
		}
		//����Ԫ��׷�ӵ����
		heap[size] = x;
		//Ȼ���ϸ�,����Ĳ���Ϊ���������
		swim(size);
		size++;
	}

	//ɾ���Ѷ�Ԫ�أ�ʱ�临�Ӷ�ΪO(logN)
	T pop()
	{
		if (isEmpty())
		{
			throw std::underflow_error("PriorityQueue underflow");
		}
		T res = heap[0];
		//�Ѷѵ�Ԫ�ط��ڶѶ�
		swap(0, size - 1);
		size--;
		//Ȼ���³�����ȷ��λ��
		sink(0);
		//����
		if (size > 0 && size == heap.size() / 4)
		{
			resize(heap.size() / 2);
		}
		return res;
	}
};


void Test_PriorityQueue(void)
{
	// ʹ��lambda���ʽ�����ݱȽ���
	// С����
	MyPriorityQueue<int> pq(3, [](const int& a, const int& b) { return a > b; });
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);

	// 1 1 3 4 5 9
	while (!pq.isEmpty()) {
		std::cout << pq.pop() << " ";
	}
	std::cout << std::endl;
}
