#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//˫�����ʵ��
//˫��������ݽṹ
class DoublyListNode
{
public:
	int val;
	DoublyListNode* next, * prev;
	DoublyListNode(int x) :val(x), next(NULL), prev(NULL) {}
};

//��Ȼ����Խ��ڵ��ָ������ΪDoublyLinkList
//typedef DoublyListNode* DoublyLinkList;


//����һ��˫����
DoublyListNode* creaDoublyLinkList(vector<int>& arr)
{
	//�ж������Ƿ�Ϊ��
	if (arr.empty())
	{
		return nullptr;
	}
	//����һ��ͷ�ڵ�
	DoublyListNode* head = new DoublyListNode(arr[0]);
	DoublyListNode* cur = head;
	//forѭ������˫���� ÿ�δ����ڵ��Ҫ��prev��nextָ����������
	for (int i = 1; i < arr.size(); i++)
	{
		DoublyListNode* newNode = new DoublyListNode(arr[i]);
		cur->next = newNode;
		newNode->prev = cur;
		cur = cur->next;
	}

	return head;
	
}


void Test_DoublyLinkList(void)
{
	//����һ��˫����
	vector<int> arr = { 1,2,3,4,5 };
	DoublyListNode* head = creaDoublyLinkList(arr);
	DoublyListNode* tail = nullptr;//βָ���ÿ�,һ����Ҫ����һ�βſ����ҵ���Ӧ��β�ڵ����ڵ�λ��


	//---------------------------------
	/*
	//��ͷ�ڵ㿪ʼ��������ڵ�
	for (DoublyListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << endl;
		tail = p;//βָ���ƶ�
	}
	cout << endl;
	//��β�ڵ㿪ʼ��ǰ�����ڵ�
	for (DoublyListNode* p = tail; p!= nullptr; p = p->prev)
	{
		cout << p->val << endl;
	}
	*/


	//-----------------------------
	//��˫����β������Ԫ��
	/*
	tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}

	//������Ԫ��
	DoublyListNode* newNode = new DoublyListNode(6);
	tail->next = newNode;
	newNode->prev = tail;
	//����β�ڵ�����
	tail = newNode;
	*/

	
	//-----------------------------
	//��˫�����м����Ԫ��
	/*
	//��Ҫ���뵽����3(���ĸ��ڵ�)��λ��,�����ǲ���ԭ��Ԫ��֮ǰ��λ��
	//���ҵ�����3
	DoublyListNode* p = head;
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//�����½ڵ�
	DoublyListNode* newNode = new DoublyListNode(66);
	//һ����Ҫ����2*2��ָ�룬ĳЩָ�����ӵ��Ⱥ�˳��
	newNode->next = p->next;
	newNode->prev = p;

	//�����½ڵ�
	p->next->prev = newNode;
	p->next = newNode;
	*/


	//-----------------------------------
	//��˫������ɾ��һ���ڵ�
	//ɾ�����ĸ��ڵ㣬���ҵ��������ڵ�
	/*
	DoublyListNode* p = head;
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//����pָ��������ڵ�
	DoublyListNode* toDelete = p->next;

	//��Ҫɾ���Ľڵ��������ɾ��
	p->next = toDelete->next;
	toDelete->next->prev = p;

	//��Ҫɾ���Ľڵ��ǰ��ָ����Ϊnullptr,����ֱ�ӽ���free��
	free(toDelete);
	*/


	//---------------------------------
	//��˫����ͷ��ɾ��Ԫ��
	/*
	DoublyListNode* toDelete = head;
	head = head->next;
	head->prev = nullptr;

	free(toDelete);
	*/


	//---------------------------------
	//��˫����β��ɾ��Ԫ��
	DoublyListNode* p = head;
	//�����ҵ�β�ڵ㣬���tail�Ѿ�ָ��β�ڵ���Ժ�����һ��
	while (p->next != nullptr)
	{
		p = p->next;
	}

	//��β�ڵ��������ɾ��
	p->prev->next = nullptr;
	free(p);

	//����˫����
	for (DoublyListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << " ";
	}
}