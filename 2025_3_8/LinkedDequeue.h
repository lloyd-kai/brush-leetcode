#pragma once
#include <iostream>
#include <list>
using namespace std;

template<typename E>
class MyListDeque
{
	list<E> list;
public:
	//�Ӷ�ͷ���Ԫ�أ�ʱ�临�Ӷ�ΪO(1)
	void addFirst(const E& e)
	{
		list.push_front(e);
	}

	//�Ӷ�β�����Ԫ�أ�ʱ�临�Ӷ�O(1)
	void addLast(const E& e)
	{
		list.push_back(e);
	}

	//�Ӷ�ͷɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
	E removeFirst(void)
	{
		E firstElement = list.front();
		list.pop_front();
		return firstElement;
	}

	//�Ӷ�βɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
	E removeLast(void)
	{
		E lastElement = list.back();
		list.pop_back();
		return lastElement;
	}

	//�鿴��ͷԪ�أ�ʱ�临�Ӷ�O(1)
	E peekFirst()
	{
		return list.front();
	}

	//�鿴��βԪ�أ�ʱ�临�Ӷ�O(1)
	E peekLast()
	{
		return list.back();
	}
};


void Test_MyDeQueue(void)
{
	MyListDeque<int> deque;
	deque.addFirst(1);
	deque.addFirst(2);
	deque.addLast(3);
	deque.addLast(4);

	cout << deque.removeFirst() << endl; // 2
	cout << deque.removeLast() << endl; // 4
	cout << deque.peekFirst() << endl; // 1
	cout << deque.peekLast() << endl; // 3
}