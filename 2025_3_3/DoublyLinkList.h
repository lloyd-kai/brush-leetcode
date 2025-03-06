#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <string>
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


//双链表的模板实现
template<typename E>
class MyLinkedList
{
	//虚构头尾节点
	struct Node
	{
		E val;
		Node* next;
		Node* prev;

		Node(E value) :val(value), next(nullptr), prev(nullptr) {}
	};

	//成员变量
	Node* head;
	Node* tail;
	int size;

public:
	//构造函数初始化虚拟头尾节点
	MyLinkedList()
	{
		head = new Node(E());
		tail = new Node(E());
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	//添加元素
	void addLast(E e)
	{
		Node* x = new Node(e);
		Node* temp = tail->prev;
		//
		temp->next = x;
		x->prev = temp;
		
		x->next = tail;
		tail->prev = x;

		size++;
	}

	//在头部添加元素
	void addFirst(E e)
	{
		Node* x = new Node(e);
		Node* temp = head->next;

		temp->prev = x;
		x->next = temp;

		head->next = x;
		x->prev = head;

	}

	//在指定位置添加元素
	void add(int index, E element)
	{
		checkPositionIndex(index);
		//如果是尾部添加元素
		if (index == size)
		{
			addLast(element);
			return;
		}

		//找到index 对应的Node
		Node* p = getNode(index);
		Node* temp = p->prev;

		//新要插入的Node
		Node* x = new Node(element);

		p->prev = x;
		temp->next = x;

		x->prev = temp;
		x->next = p;

		size++;
	}


	//删除第一个节点
	E removeFirst()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements to remove");
		}

		//虚拟节点的存在可以让我们不用考虑空指针的问题
		//可以统一插入与删除的操作
		Node* x = head->next;
		Node* temp = x->next;

		head->next = temp;
		temp->prev = head;

		//在C++中建议使用delete而不是free，free适合与C语言
		delete x;

		size--;
		return temp->val;

	}

	E removeLast()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements to remove");
		}

		Node* x = tail->prev;
		Node* temp = tail->prev->prev;

		tail->prev = temp;
		temp->next = tail;

		delete x;
		return temp->val;
	}

	E remove(int index)
	{
		checkElementIndex(index);
		//找到index对应的Node
		Node* x = getNode(index);
		Node* prev = x->prev;
		Node* next = x->next;

		prev->next = next;
		next->prev = prev;

		delete x;
		size--;

		
		return next->val;
	}

	//查找元素
	E get(int index)
	{
		checkElementIndex(index);
		//找到index对应的Node
		Node* p = getNode(index);

		return p->val;
	}

	//查找第一个元素
	E getFirst()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements in the list");
		}

		return head->next->val;
	}


	//查找最后一个元素
	E getLast()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements in the list");
		}

		return tail->prev->val;
	}

	//修改元素
	E set(int index, E val)
	{
		checkElementIndex(index);
		//找到index对应的Node
		Node* p = getNode(index);

		E oldVal = p->val;
		p->val = val;

		return oldVal;
	}


	//其他常见的函数
	int getSize() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

private:
	Node* getNode(int index)
	{
		checkElementIndex(index);
		Node* p = head->next;
		//可以进一步优化，通过index判断从前往后遍历还是从后往前遍历
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p;
	}

	bool isElementIndex(int index) const
	{
		return index >= 0 && index < size;
	}

	bool isPositionIndex(int index) const
	{
		return index >= 0 && index <= size;
	}

	//检查index索引位置是否可以存在元素
	void checkElementIndex(int index) const
	{
		if (!isElementIndex(index))
		{
			throw out_of_range("Index: " + std::to_string(index) + ",size: " + std::to_string(size));
		}
	}

	//检查index索引位置是否可以存在元素
	void checkPositionIndex(int index) const
	{
		if (!isPositionIndex(index))
		{
			throw out_of_range("Index: " + std::to_string(index) + ",size: " + std::to_string(size));
		}
	}

public:
	void display()
	{
		cout << "size = " << size << endl;
		for (Node* p = head->next; p != tail; p = p->next)
		{
			cout << p->val << "<->";
		}
		cout << "null" << endl;
		cout << endl;
	}

	~MyLinkedList()
	{
		while (size > 0)
		{
			removeFirst();
		}
		delete head;
		delete tail;
	}

};

void Test_MyLinkedList(void)
{
	MyLinkedList<int> list;
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addFirst(0);
	list.add(2,100);

	list.display();
}