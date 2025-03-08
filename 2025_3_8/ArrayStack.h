#pragma once
#include <vector>
#include <iostream>
using namespace std;

//用数组实现栈
template<typename E>
class MyArrayStack
{
private:
	vector<E> list;

public:
	//向栈顶加入元素,时间复杂度为O(1)
	void push(const E& val)
	{
		list.push_back(val);
	}

	//栈顶弹出元素,时间复杂度为O(1)
	void pop()
	{
		E topElement = list.front();
		list.pop_back();
		return topElement;
	}

	//查看栈顶元素
	E peek() const
	{
		return list.back();
	}

	//返回栈中的元素个数
	int size() const
	{
		return list.size();
	}
};