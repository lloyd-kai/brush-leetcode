#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename K,typename V>
//�ڵ�����ݽṹ
struct Node
{
	K key;
	V val;
	Node* next;//��nextָ��ʵ�ֹ�ϣ��ı���˳�����(Ҳ���ǰ��ղ���˳�����)
	Node* prev;//prev����ǰ�潲����������ָ�룬����ָ�����������ͻ����һ����ֵ

	Node(K key, V val) :key(key), val(val), next(nullptr), prev(nullptr) {};
};

template<typename K,typename V>
class MyLinkedHashMap
{
public:
	MyLinkedHashMap()
	{
		head = new Node<K, V>(K(), V());
		tail = new Node<K, V>(K(), V());
		head->next = tail;
		tail->prev = head;
	}

	//��ȡ������Ӧ��ֵ
	V get(K key)
	{
		//���û���ҵ���ֵ�����ؿ�
		if (map.find(key) == map.end())
		{
			return V();
		}
		return map[key]->val;
	}

	//�����ֵ��
	void put(K key, V val)
	{
		//���Ϊ�²���Ľڵ㣬��ͬʱ���������map
		if (map.find(key) == map.end())
		{
			//�����µ�node
			Node<K, V>* node = new Node<K, V>(key, val);
			addLastNode(node);
			map[key] = node;
			return;
		}

		//������ڣ����滻֮ǰ��val
		map[key]->val = val;
	}

	//ɾ����ֵ��
	void remove(K key)
	{
		//���key�����ڣ���ֱ�ӷ���
		if (map.find(key) == map.end())
		{
			return;
		}

		//���key���ڣ�����Ҫͬʱ�ڹ�ϣ���к�������ɾ����
		//�˻����ǽ��ڵ��˫������ɾ��
		Node<K,V>* node = map[key];
		map.erase(key);
		removeNode(node);
	}

	//�жϹ�ϣ�����Ƿ����key
	bool containsKey(K key)
	{
		return map.find(key) != map.end();
	}


	//�������еļ�
	vector<K> keys()
	{
		vector<K> keyList;
		for (Node<K, V>* p = head->next; p != tail; p = p->next)
		{
			keyList.push_back(p->key);
		}
		return keyList;
	}

private:
	Node<K, V>* head;
	Node<K, V>* tail;
	unordered_map < K, Node<K, V>*>map;

	void addLastNode(Node<K, V>* x)
	{
		Node<K, V>* temp = tail->prev;
		x->next = tail;
		x->prev = temp;

		temp->next = x;
		tail->prev = x;
	}

	void removeNode(Node<K, V>* x)
	{
		Node<K, V>* prev = x->prev;
		Node<K, V>* next = x->next;

		prev->next = next;
		next->prev = prev;

		x->next = x->prev = nullptr;
	}


};


void Test_LinkedHashMap(void)
{
	MyLinkedHashMap<string, int> map;
	map.put("a", 1);
	map.put("b", 2);
	map.put("c", 3);
	map.put("d", 4);
	map.put("e", 5);

	// output: a b c d e
	for (const auto& key : map.keys()) {
		cout << key << " ";
	}
	cout << endl;

	map.remove("c");

	// output: a b d e
	for (const auto& key : map.keys()) {
		cout << key << " ";
	}
	cout << endl;

}