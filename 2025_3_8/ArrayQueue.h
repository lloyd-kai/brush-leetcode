#pragma once
#include <vector>
#include <iostream>
#include "CycleArray.h"
using namespace std;

//用数组实现队列
//使用循环数组的API实现，或者用ArrayStack的思路实现也是可以的
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

	//压入元素
	void push(E t)
	{
		arr.addLast();
	}

	//弹出队头元素
	E pop(E t)
	{
		return arr.removeFirst();
	}

	//查找队头元素
	E peek()
	{
		return arr.getFirst();
	}

	//返回队列元素个数
	int getSize()
	{
		return arr.getSize();
	}
};

