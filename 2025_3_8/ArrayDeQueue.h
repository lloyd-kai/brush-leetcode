#pragma once
#include <iostream>
#include <list>
#include "CycleArray.h" //借用循环队列的API
using namespace std;


template<typename E>
class MyArrayDeQueue
{
private:
	CycleArray<E> arr;

public:
	//从队头插入元素,时间复杂度为O(1)
	void addFirst(E e)
	{
		arr.addFirst(e);
	}

	//从队尾插入元素，时间复杂度O(1)
	void addLast(E e)
	{
		arr.addLast(e);
	}

	//从队头删除元素，时间复杂度O(1)
	void removeFirst()
	{
		arr.removeFirst();
	}

	//从队尾删除元素，时间复杂度O(1)
	void removeLast()
	{
		arr.removeLast();
	}

	//查看队头元素，时间复杂度O(1)
	E peekFirst(void)
	{
		return arr.getFirst();
	}

	//查看队尾元素，时间复杂度O(1)
	E peekLast(void)
	{
		return arr.getLast();
	}


};

void Test_MyArrayDeQueue(void)
{
	MyArrayDeQueue<int> deque;
	deque.addFirst(1);
	deque.addFirst(2);
	deque.addLast(3);
	deque.addLast(4);

	cout << deque.peekFirst() << endl; // 2
	cout << deque.peekLast() << endl; // 4
}