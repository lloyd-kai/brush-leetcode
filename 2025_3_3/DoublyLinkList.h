#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//双链表的实现
//双链表的数据结构
class DoublyListNode
{
public:
	int val;
	DoublyListNode* next, * prev;
	DoublyListNode(int x) :val(x), next(NULL), prev(NULL) {}
};

//当然你可以将节点的指针命名为DoublyLinkList
//typedef DoublyListNode* DoublyLinkList;


//创建一个双链表
DoublyListNode* creaDoublyLinkList(vector<int>& arr)
{
	//判断数组是否为空
	if (arr.empty())
	{
		return nullptr;
	}
	//创建一个头节点
	DoublyListNode* head = new DoublyListNode(arr[0]);
	DoublyListNode* cur = head;
	//for循环迭代双链表 每次创建节点就要将prev和next指针链接起来
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
	//创建一条双链表
	vector<int> arr = { 1,2,3,4,5 };
	DoublyListNode* head = creaDoublyLinkList(arr);
	DoublyListNode* tail = nullptr;//尾指针置空,一般需要遍历一次才可以找到对应的尾节点所在的位置


	//---------------------------------
	/*
	//从头节点开始往后遍历节点
	for (DoublyListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << endl;
		tail = p;//尾指针移动
	}
	cout << endl;
	//从尾节点开始向前遍历节点
	for (DoublyListNode* p = tail; p!= nullptr; p = p->prev)
	{
		cout << p->val << endl;
	}
	*/


	//-----------------------------
	//在双链表尾部插入元素
	/*
	tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}

	//插入新元素
	DoublyListNode* newNode = new DoublyListNode(6);
	tail->next = newNode;
	newNode->prev = tail;
	//更新尾节点引用
	tail = newNode;
	*/

	
	//-----------------------------
	//在双链表中间插入元素
	/*
	//想要插入到索引3(第四个节点)的位置,这里是插入原来元素之前的位置
	//先找到索引3
	DoublyListNode* p = head;
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//创建新节点
	DoublyListNode* newNode = new DoublyListNode(66);
	//一共需要链接2*2个指针，某些指针链接的先后顺序
	newNode->next = p->next;
	newNode->prev = p;

	//插入新节点
	p->next->prev = newNode;
	p->next = newNode;
	*/


	//-----------------------------------
	//在双链表中删除一个节点
	//删除第四个节点，先找到第三个节点
	/*
	DoublyListNode* p = head;
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}

	//现在p指向第三个节点
	DoublyListNode* toDelete = p->next;

	//把要删除的节点从链表中删除
	p->next = toDelete->next;
	toDelete->next->prev = p;

	//把要删除的节点的前后指针置为nullptr,或者直接将其free掉
	free(toDelete);
	*/


	//---------------------------------
	//在双链表头部删除元素
	/*
	DoublyListNode* toDelete = head;
	head = head->next;
	head->prev = nullptr;

	free(toDelete);
	*/


	//---------------------------------
	//在双链表尾部删除元素
	DoublyListNode* p = head;
	//首先找到尾节点，如果tail已经指向尾节点可以忽略这一步
	while (p->next != nullptr)
	{
		p = p->next;
	}

	//把尾节点从链表中删除
	p->prev->next = nullptr;
	free(p);

	//遍历双链表
	for (DoublyListNode* p = head; p != nullptr; p = p->next)
	{
		cout << p->val << " ";
	}
}