#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
using namespace std;

//�����ϵĵ�����ڵ㶨������
/*
class ListNode
{
public:
	int val;//�ڵ���������൱��data
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {} //��ʽ��ʼ������

//ʵ�ʳ��õ�����ڵ�
private:
	template<typename E>
	class Node
	{
	public:
		E val;
		Node* next;
		Node* prev;

		Node(Node* prev, E element, Node* next)
		{
			this->val = element;
			this->next = next;
			this->prev = prev;
		}
	};
};
*/

//����������ݽṹ
class ListNode
{
public:
	int val;//�ڵ���������൱��data
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {} //��ʽ��ʼ������
};

//����һ�����飬ת��Ϊһ��������
ListNode* createLinkedList(vector<int> arr)
{
	//�������Ϊ��
	if (arr.empty())
	{
		return nullptr;//ע������Ҫ���ص��ǿ�ָ������ǵ�����null
	}

	ListNode* head = new ListNode(arr[0]);//����һ��ͷ�ڵ�(�����ͷ�ڵ㲻Ϊ��)
	ListNode* cur = head;
	for (int i = 1; i < arr.size(); i++)//��β���������ڵ�
	{
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}

	return head;
}

void Test_LinkList(void)
{
	//����һ������
	ListNode* head = createLinkedList({ 1,2,3,4,5 });


	//------------------------------------
	//�ڵ������ͷ������һ���½ڵ� Ҳ����ͷ�巨
	//C++�����C�ĺô�������һ��new�ͽ��ڴ����ͳ�ʼ���Ĳ���ͬʱ�����һ�𣬷�װ�˲���Ҫ��ϸ��
	/*
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	head = newHead;
	*/

	//------------------------------------
	//�ڵ�����β������Ԫ��
	/*
	ListNode* p = head;
	//�ȱ����ߵ���������һ���ڵ�
	while (p->next != nullptr)
	{
		p = p->next;
	}

	//����p�������һ���ڵ�
	//Ȼ����p�ڵ�������һ���ڵ�
	p->next = new ListNode(6);
	*/

	//--------------------------
	//�ڵ�������м����ڵ� ��������ݽṹһ��������������ǰ
	//�ڵ������ڵ�������ڵ㣬����Ҫ�ҵ��������ڵ�
	/*
	ListNode* p = head;
	for (int i = 0; i < 2; i++)//��whileҲ����
	{
		p = p->next;
	}

	//��ʱpָ��������ڵ�
	ListNode* newNode = new ListNode(66);
	newNode->next = p->next;

	//�����½ڵ�
	p->next = newNode;
	*/

	
	//------------------------------
	//�����м�ɾ���ڵ�
	/*
	ListNode* p = head;
	//ɾ�����ĸ��ڵ㣬�����ҵ����ĸ��ڵ��ǰ�����
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//Ȼ�󽫵��ĸ��ڵ��������ɾ��
	//��Ҫһ����ʱָ���¼���ĸ��ڵ�(��ΪC++�������ڴ���յĻ��ƣ���Ҫ�ֶ��ͷ�)
	ListNode* temp = p->next;
	p->next = p->next->next;
	free(temp);
	*/

	
	//------------------------------
	//����β��ɾ��Ԫ��
	/*
	ListNode* p = head;
	//ͬ����Ҫ���������һ���ڵ��ǰ���ڵ�
	while (p->next->next != nullptr)
	{
		p = p->next;
	}

	//��ʱpָ�����ڶ����ڵ�
	ListNode* temp = p->next;
	p->next = nullptr;
	free(temp);//�˴����Դ�ϵ㣬�����ڴ��Ƿ��Ѿ��ͷ�
	*/

	
	//----------------------------
	//�ڵ�����ͷ��ɾ��Ԫ��
	ListNode* temp = head;
	head = head->next;
	free(temp);

	//������������
	for (ListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << endl;
	}
}


//�������ģ��ʵ��
template<typename E>
class MyLinkedList2
{
private:
	//�ڵ�ṹ

};