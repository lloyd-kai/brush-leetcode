#pragma once
#include <iostream>
#include <cstring>
#include <string>
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
	struct Node
	{
		E val;
		Node* next;

		Node(E value) :val(value), next(nullptr) {}
	};

	//�����ͷ�ڵ�������ͷ�ڵ�
	Node* head;
	//ʵ�ʵ�β���ڵ�����
	Node* tail;
	int size_;

public:
	//���캯��
	MyLinkedList2()
	{
		head = new Node(E());
		tail = head;
		size_ = 0;
	}


	//ͷ����ӽڵ�
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

	//β����ӽڵ�
	void addLast(E e)
	{
		Node* newNode = new Node(e);
		tail->next = newNode;
		tail = newNode;
		size_++;
	}

	//�������м���ӽڵ�
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
		//������Ȼ��ֱ���ҵ����һ��Ԫ��,Ҳ����tail��ָ���ָ�룬������Ҫ���ر�ɾ����Ԫ�أ�Ҳ���ǻ���Ҫ���±���һ��
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

	//ɾ�������м��Ԫ��
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
		//ɾ���������һ��Ԫ��
		if (index == size_ - 1)
		{
			tail = prev;
		}
		size_--;
		E val = nodeToRemove->val;
		delete nodeToRemove;
		return val;
	}

	//����
	E getFirst()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements in the list");
		}
		return head->next->val;
	}

	//��ȡ���һ��Ԫ��
	E getLast()
	{
		if (isEmpty())
		{
			throw std::out_of_range("No elements in the list");
		}

		return head->next->val;
	}

	//����ĳһ��λ�õ�Ԫ��
	E get(int index)
	{
		checkElementIndex(index);
		Node* p = getNode(index);
		return p->val;
	}

	//�޸�Ԫ��
	E set(int index, E element)
	{
		checkElementIndex(index);
		Node* p = getNode(index);

		E oldVal = p->val;
		p->val = element;

		return oldVal;
	}

	//�������ߺ���
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

	//���index����λ���Ƿ���Դ���Ԫ��
	void checkElementIndex(int index)
	{
		if (!isElementIndex(index))
		{
			throw std::out_of_range("Index: " + std::to_string(index) + ",size_: " + std::to_string(size_));
		}

	}

	//���index����λ���Ƿ���Բ���Ԫ��
	void checkPositionIndex(int index)
	{
		if (!isPositionIndex(index))
		{
			throw std::out_of_range("Index: " + std::to_string(index) + ",size_:" + std::to_string(size_));
		}
	}


	//����index��Ӧ�Ľڵ�
	//ע��Ҫȷ�������index�ǺϷ���
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