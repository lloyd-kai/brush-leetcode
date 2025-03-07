#pragma once
#include <iostream>
#include <cstring>
#include <string>
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
	struct Node
	{
		E val;
		Node* next;

		Node(E value) :val(value), next(nullptr) {}
	};

	//这里的头节点是虚拟头节点
	Node* head;
	//实际的尾部节点引用
	Node* tail;
	int size_;

public:
	//构造函数
	MyLinkedList2()
	{
		head = new Node(E());
		tail = head;
		size_ = 0;
	}


	//头部添加节点
	void addFirst(E e)
	{
		Node* newNode = new Node(e);
		newNode->next = head->next;
		head->next = newNode;
		if (size_ == 0)
		{
			tail = newNode;
		}
		size_++;
	}

	//尾部添加节点
	void addLast(E e)
	{
		Node* newNode = new Node(e);
		tail->next = newNode;
		tail = newNode;
		size_++;
	}

	//在链表中间添加节点
	void add(int index, E e)
	{
		checkPositionIndex(index);

		if (index == size_)
		{
			addLast(e);
		}

		Node* prev = head;
		for (int i = 0; i < index; i++)
		{
			prev = prev->next;
		}
		Node* newNode = new Node(e);
		newNode->next = prev->next;
		prev->next = newNode;
		size_++;
	}

	E removeFirst()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements to remove");
		}

		Node* first = head->next;
		head->next = first->next;
		if (size_ == 1)
		{
			tail = head;
		}
		size_--;
		E val = first->val;
		delete first;
		return val;
	}

	E removeLast()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements to remove");
		}

		Node* prev = head->next;
		//这里虽然能直接找到最后一个元素,也就是tail所指向的指针，但是需要返回被删除的元素，也就是还需要重新遍历一次
		while (prev->next != tail)
		{
			prev = prev->next;
		}

		E val = tail->val;
		delete tail;
		prev->next = nullptr;
		tail = prev;
		size_--;
		return val;
	}

	//删除链表中间的元素
	E remove(int index)
	{
		checkElementIndex(index);

		Node* prev = head;
		for (int i = 0; i < index; i++)
		{
			prev = prev->next;
		}

		Node* nodeToRemove = prev->next;
		prev->next = nodeToRemove->next;
		//删除的是最后一个元素
		if (index == size_ - 1)
		{
			tail = prev;
		}
		size_--;
		E val = nodeToRemove->val;
		delete nodeToRemove;
		return val;
	}

	//查找
	E getFirst()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements in the list");
		}
		return head->next->val;
	}

	//获取最后一个元素
	E getLast()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements in the list");
		}

		return head->next->val;
	}

	//查找某一个位置的元素
	E get(int index)
	{
		checkElementIndex(index);
		Node* p = getNode(index);
		return p->val;
	}

	//修改元素
	E set(int index, E element)
	{
		checkElementIndex(index);
		Node* p = getNode(index);

		E oldVal = p->val;
		p->val = element;

		return oldVal;
	}

	//其他工具函数
	int size()
	{
		return size_;
	}

	bool isEmpty()
	{
		return size_ == 0;
	}

private:
	bool isElementIndex(int index)
	{
		return index >= 0 && index < size_;
	}

	bool isPositionIndex(int index)
	{
		return index >= 0 && index <= size_;
	}

	//检查index索引位置是否可以存在元素
	void checkElementIndex(int index)
	{
		if (!isElementIndex(index))
		{
			throw std::out_of_range("Index: " + std::to_string(index) + ",size_: " + std::to_string(size_));
		}

	}

	//检查index索引位置是否可以插入元素
	void checkPositionIndex(int index)
	{
		if (!isPositionIndex(index))
		{
			throw std::out_of_range("Index: " + std::to_string(index) + ",size_:" + std::to_string(size_));
		}
	}


	//返回index对应的节点
	//注意要确保输入的index是合法的
	Node* getNode(int index)
	{
		Node* p = head->next;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p;
	}

};


void Test_MyLinkedList2(void)
{
	MyLinkedList2<int> list;
	list.addFirst(1);
	list.addFirst(2);
	list.addLast(3);
	list.addLast(4);
	list.add(2, 5);

	cout << list.removeFirst() << endl; 
	cout << list.removeLast() << endl; 
	cout << list.remove(1) << endl; 

	cout << list.getFirst() << endl; 
	cout << list.getLast() << endl; 
	cout << list.get(1) << endl; 
}