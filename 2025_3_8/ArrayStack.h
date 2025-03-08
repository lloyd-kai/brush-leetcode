#pragma once
#include <vector>
#include <iostream>
using namespace std;

//������ʵ��ջ
template<typename E>
class MyArrayStack
{
private:
	vector<E> list;

public:
	//��ջ������Ԫ��,ʱ�临�Ӷ�ΪO(1)
	void push(const E& val)
	{
		list.push_back(val);
	}

	//ջ������Ԫ��,ʱ�临�Ӷ�ΪO(1)
	void pop()
	{
		E topElement = list.front();
		list.pop_back();
		return topElement;
	}

	//�鿴ջ��Ԫ��
	E peek() const
	{
		return list.back();
	}

	//����ջ�е�Ԫ�ظ���
	int size() const
	{
		return list.size();
	}
};