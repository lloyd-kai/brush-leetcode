#pragma once
#include <list>
#include <iostream>
using namespace std;

template<typename E>
class MyLinkedQueue
{
private:
	list<E> list;

public:
	//向队尾插入元素，时间复杂度为O(1)
	void push(const E& e)
	{
		list.push_back(e);
	}

	//从队头删除元素,时间复杂度为O(1)
	E pop()
	{
		E front = list.front();
		list.pop_front();
		return front;
	}

	//查看队头元素，时间复杂度为O(1)
	E peek()
	{
		return list.front();
	}

	//返回队列中元素的个数，时间复杂度O(1)
	int size()
	{
		return list.size();
	}

};

void Test_LinkedQueue(void)
{
	MyLinkedQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	cout << queue.peek() << endl; // 1
	cout << queue.pop() << endl; // 1
	cout << queue.pop() << endl; // 2
	cout << queue.peek() << endl; // 3

}