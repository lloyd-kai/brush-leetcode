#pragma once
#include <list>
#include <iostream>
using namespace std;

//栈的实现
//严格来说都不是最底层的实现，但我们学习算法是学习思想而不是代码
template<typename E>
class MyLinkedStack
{
private:
	std::list<E> list;

public:
	//向栈顶加入元素,时间复杂度O(1)
	void push(const E& val)
	{
		list.push_back(val);
	}

	//从栈顶弹出元素,时间复杂度为O(1)
	E pop()
	{
		E value = list.back();
		list.pop_back();
		return value;
	}

	//查看栈顶元素,时间复杂度为O(1)
	E peek() const
	{
		return list.back();
	}

	//返回栈的元素的个数,时间复杂度为O(1)
	int size() const
	{
		return list.size();
	}
};


//测试实现的栈
void Test_LinkedStack(void)
{
	MyLinkedStack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	while (stack.size() > 0) {
		cout << stack.pop() << endl;
	}
}