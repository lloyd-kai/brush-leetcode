#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
using namespace std;

//力扣上的单链表节点定义如下
/*
class ListNode
{
public:
	int val;//节点的数据域，相当于data
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {} //显式初始化函数

//实际常用的链表节点
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

//单链表的数据结构
class ListNode
{
public:
	int val;//节点的数据域，相当于data
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {} //显式初始化函数
};

//输入一个数组，转换为一个单链表
ListNode* createLinkedList(vector<int> arr)
{
	//如果数组为空
	if (arr.empty())
	{
		return nullptr;//注意这里要返回的是空指针而不是单纯的null
	}

	ListNode* head = new ListNode(arr[0]);//创建一个头节点(这里的头节点不为空)
	ListNode* cur = head;
	for (int i = 1; i < arr.size(); i++)//往尾部添加链表节点
	{
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}

	return head;
}

void Test_LinkList(void)
{
	//创建一条链表
	ListNode* head = createLinkedList({ 1,2,3,4,5 });


	//------------------------------------
	//在单链表的头部插入一个新节点 也就是头插法
	//C++相对于C的好处在于用一个new就将内存分配和初始化的步骤同时结合在一起，封装了不必要的细节
	/*
	ListNode* newHead = new ListNode(0);
	newHead->next = head;
	head = newHead;
	*/

	//------------------------------------
	//在单链表尾部插入元素
	/*
	ListNode* p = head;
	//先遍历走到链表的最后一个节点
	while (p->next != nullptr)
	{
		p = p->next;
	}

	//现在p就是最后一个节点
	//然后在p节点后面插入一个节点
	p->next = new ListNode(6);
	*/

	//--------------------------
	//在单链表的中间插入节点 步骤和数据结构一样，先连后再连前
	//在第三个节点后面插入节点，首先要找到第三个节点
	/*
	ListNode* p = head;
	for (int i = 0; i < 2; i++)//用while也可以
	{
		p = p->next;
	}

	//此时p指向第三个节点
	ListNode* newNode = new ListNode(66);
	newNode->next = p->next;

	//插入新节点
	p->next = newNode;
	*/

	
	//------------------------------
	//链表中间删除节点
	/*
	ListNode* p = head;
	//删除第四个节点，首先找到第四个节点的前驱结点
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//然后将第四个节点从链表中删除
	//需要一个临时指针记录第四个节点(因为C++不具有内存回收的机制，需要手动释放)
	ListNode* temp = p->next;
	p->next = p->next->next;
	free(temp);
	*/

	
	//------------------------------
	//链表尾部删除元素
	/*
	ListNode* p = head;
	//同理需要遍历到最后一个节点的前驱节点
	while (p->next->next != nullptr)
	{
		p = p->next;
	}

	//此时p指向倒数第二个节点
	ListNode* temp = p->next;
	p->next = nullptr;
	free(temp);//此处可以打断点，测试内存是否已经释放
	*/

	
	//----------------------------
	//在单链表头部删除元素
	ListNode* temp = head;
	head = head->next;
	free(temp);

	//遍历整个链表
	for (ListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << endl;
	}
}


//单链表的模拟实现
template<typename E>
class MyLinkedList2
{
private:
	//节点结构

};