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
	//���β����Ԫ�أ�ʱ�临�Ӷ�ΪO(1)
	void push(const E& e)
	{
		list.push_back(e);
	}

	//�Ӷ�ͷɾ��Ԫ��,ʱ�临�Ӷ�ΪO(1)
	E pop()
	{
		E front = list.front();
		list.pop_front();
		return front;
	}

	//�鿴��ͷԪ�أ�ʱ�临�Ӷ�ΪO(1)
	E peek()
	{
		return list.front();
	}

	//���ض�����Ԫ�صĸ�����ʱ�临�Ӷ�O(1)
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