#pragma once
#include <vector>
#include <iostream>
#include "CycleArray.h"
using namespace std;

//������ʵ�ֶ���
//ʹ��ѭ�������APIʵ�֣�������ArrayStack��˼·ʵ��Ҳ�ǿ��Ե�
template<typename E>
class MyArrayQueue
{
private:
	CycleArray<E> arr;
public:
	MyArrayQueue()
	{
		arr = CycleArray<E>();
	}

	//ѹ��Ԫ��
	void push(E t)
	{
		arr.addLast();
	}

	//������ͷԪ��
	E pop(E t)
	{
		return arr.removeFirst();
	}

	//���Ҷ�ͷԪ��
	E peek()
	{
		return arr.getFirst();
	}

	//���ض���Ԫ�ظ���
	int getSize()
	{
		return arr.getSize();
	}
};

