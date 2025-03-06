#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <string>
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


//˫�����ģ��ʵ��
template<typename E>
class MyLinkedList
{
	//�鹹ͷβ�ڵ�
	struct Node
	{
		E val;
		Node* next;
		Node* prev;

		Node(E value) :val(value), next(nullptr), prev(nullptr) {}
	};

	//��Ա����
	Node* head;
	Node* tail;
	int size;

public:
	//���캯����ʼ������ͷβ�ڵ�
	MyLinkedList()
	{
		head = new Node(E());
		tail = new Node(E());
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	//���Ԫ��
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

	//��ͷ�����Ԫ��
	void addFirst(E e)
	{
		Node* x = new Node(e);
		Node* temp = head->next;

		temp->prev = x;
		x->next = temp;

		head->next = x;
		x->prev = head;

	}

	//��ָ��λ�����Ԫ��
	void add(int index, E element)
	{
		checkPositionIndex(index);
		//�����β�����Ԫ��
		if (index == size)
		{
			addLast(element);
			return;
		}

		//�ҵ�index ��Ӧ��Node
		Node* p = getNode(index);
		Node* temp = p->prev;

		//��Ҫ�����Node
		Node* x = new Node(element);

		p->prev = x;
		temp->next = x;

		x->prev = temp;
		x->next = p;

		size++;
	}


	//ɾ����һ���ڵ�
	E removeFirst()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements to remove");
		}

		//����ڵ�Ĵ��ڿ��������ǲ��ÿ��ǿ�ָ�������
		//����ͳһ������ɾ���Ĳ���
		Node* x = head->next;
		Node* temp = x->next;

		head->next = temp;
		temp->prev = head;

		//��C++�н���ʹ��delete������free��free�ʺ���C����
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
		//�ҵ�index��Ӧ��Node
		Node* x = getNode(index);
		Node* prev = x->prev;
		Node* next = x->next;

		prev->next = next;
		next->prev = prev;

		delete x;
		size--;

		
		return next->val;
	}

	//����Ԫ��
	E get(int index)
	{
		checkElementIndex(index);
		//�ҵ�index��Ӧ��Node
		Node* p = getNode(index);

		return p->val;
	}

	//���ҵ�һ��Ԫ��
	E getFirst()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements in the list");
		}

		return head->next->val;
	}


	//�������һ��Ԫ��
	E getLast()
	{
		if (size < 1)
		{
			throw std::out_of_range("No elements in the list");
		}

		return tail->prev->val;
	}

	//�޸�Ԫ��
	E set(int index, E val)
	{
		checkElementIndex(index);
		//�ҵ�index��Ӧ��Node
		Node* p = getNode(index);

		E oldVal = p->val;
		p->val = val;

		return oldVal;
	}


	//���������ĺ���
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
		//���Խ�һ���Ż���ͨ��index�жϴ�ǰ����������ǴӺ���ǰ����
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

	//���index����λ���Ƿ���Դ���Ԫ��
	void checkElementIndex(int index) const
	{
		if (!isElementIndex(index))
		{
			throw out_of_range("Index: " + std::to_string(index) + ",size: " + std::to_string(size));
		}
	}

	//���index����λ���Ƿ���Դ���Ԫ��
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