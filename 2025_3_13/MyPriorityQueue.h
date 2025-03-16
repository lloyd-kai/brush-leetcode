#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
#include <iostream>
using namespace std;

//优先级队列的实现-用数组的存储结构，和树的逻辑结构实现
//前提是完全二叉树，因为完全二叉树元素是连续的，可以用数组连续的排放
template <typename T>
class MyPriorityQueue
{
private:
	//堆数组
	std::vector<T>heap;

	//堆中元素的数量
	int size;

	//元素比较器
	std::function<bool(const T&, const T&)> comparator;

	//父节点的索引
	//规律和二叉树的一样，这里索引从0开始
	//自己列一个数组然后推理就行，和数据结构中左右孩子节点求法还是不一样的
	int parent(int node)
	{
		return (node - 1) / 2;
	}

	//左孩子节点的索引
	int left(int node)
	{
		return node * 2 + 1;
	}

	//右孩子节点的索引
	int right(int node)
	{
		return node * 2 + 2;
	}

	//交换数组的两个元素
	void swap(int i, int j)
	{
		std::swap(heap[i], heap[j]);
	}

	//调整堆的大小
	void resize(int capacity)
	{
		if (capacity > size)
		{
			heap.resize(capacity);
		}
	}


	//上浮操作，时间复杂度是树高O(logn)
	//持续追踪一个节点，直到其上浮到合适的位置
	void swim(int node)
	{
		//如果节点比父节点值要小
		while (node > 0 && comparator(heap[parent(node)], heap[node]))
		{
			swap(parent(node), node);
			node = parent(node);
		}
	}

	//下沉操作，时间复杂度为树高O(logN)
	void sink(int node)
	{
		while (left(node) < size || right(node) < size)
		{
			//比较自己的左右子节点，找最小值
			int min = node;
			if (left(node) < size && comparator(heap[min], heap[left(node)]))
			{
				min = left(node);
			}
			if (right(node) < size && comparator(heap[min], heap[right(node)]))
			{
				min = right(node);
			}
			//如果当前节点比子节点都小
			if (min == node)
			{
				break;
			}

			//与最小值交换
			swap(node, min);
			//继续下沉
			node = min;
		}
	}
public:
	//构造函数
	MyPriorityQueue(int capacity, std::function<bool(const T&, const T&)>compator)
		:heap(capacity), size(0), comparator(std::move(compator)) {};

	//返回堆的大小
	int getSize() const
	{
		return size;
	}

	//判断堆是否为空
	bool isEmpty() const
	{
		return size == 0;
	}

	//查找元素,返回堆顶的元素，其时间复杂度是O(1)
	const T& peek() const
	{
		if (isEmpty())
		{
			throw std::underflow_error("Priority queue underflow");
		}
		return heap[0];
	}

	//向堆中插入一个元素，时间复杂度为O(logN)
	void push(const T& x)
	{
		//扩容
		if (size == heap.size())
		{
			resize(2 * heap.size());
		}
		//把新元素追加到最后
		heap[size] = x;
		//然后上浮,传入的参数为数组的索引
		swim(size);
		size++;
	}

	//删除堆顶元素，时间复杂度为O(logN)
	T pop()
	{
		if (isEmpty())
		{
			throw std::underflow_error("PriorityQueue underflow");
		}
		T res = heap[0];
		//把堆底元素放在堆顶
		swap(0, size - 1);
		size--;
		//然后下沉到正确的位置
		sink(0);
		//缩容
		if (size > 0 && size == heap.size() / 4)
		{
			resize(heap.size() / 2);
		}
		return res;
	}
};


void Test_PriorityQueue(void)
{
	// 使用lambda表达式来传递比较器
	// 小顶堆
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
