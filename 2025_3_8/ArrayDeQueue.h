#pragma once
#include <iostream>
#include <list>
#include "CycleArray.h" //����ѭ�����е�API
using namespace std;


template<typename E>
class MyArrayDeQueue
{
private:
	CycleArray<E> arr;

public:
	//�Ӷ�ͷ����Ԫ��,ʱ�临�Ӷ�ΪO(1)
	void addFirst(E e)
	{
		arr.addFirst(e);
	}

	//�Ӷ�β����Ԫ�أ�ʱ�临�Ӷ�O(1)
	void addLast(E e)
	{
		arr.addLast(e);
	}

	//�Ӷ�ͷɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
	void removeFirst()
	{
		arr.removeFirst();
	}

	//�Ӷ�βɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
	void removeLast()
	{
		arr.removeLast();
	}

	//�鿴��ͷԪ�أ�ʱ�临�Ӷ�O(1)
	E peekFirst(void)
	{
		return arr.getFirst();
	}

	//�鿴��βԪ�أ�ʱ�临�Ӷ�O(1)
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