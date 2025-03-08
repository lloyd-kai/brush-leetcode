#pragma once
#include <list>
#include <iostream>
using namespace std;

//ջ��ʵ��
//�ϸ���˵��������ײ��ʵ�֣�������ѧϰ�㷨��ѧϰ˼������Ǵ���
template<typename E>
class MyLinkedStack
{
private:
	std::list<E> list;

public:
	//��ջ������Ԫ��,ʱ�临�Ӷ�O(1)
	void push(const E& val)
	{
		list.push_back(val);
	}

	//��ջ������Ԫ��,ʱ�临�Ӷ�ΪO(1)
	E pop()
	{
		E value = list.back();
		list.pop_back();
		return value;
	}

	//�鿴ջ��Ԫ��,ʱ�临�Ӷ�ΪO(1)
	E peek() const
	{
		return list.back();
	}

	//����ջ��Ԫ�صĸ���,ʱ�临�Ӷ�ΪO(1)
	int size() const
	{
		return list.size();
	}
};


//����ʵ�ֵ�ջ
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