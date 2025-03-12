#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename K,typename V>
//节点的数据结构
struct Node
{
	K key;
	V val;
	Node* next;//用next指针实现哈希表的遍历顺序输出(也就是按照插入顺序输出)
	Node* prev;//prev就是前面讲的拉链法的指针，用于指向与此索引冲突的下一个键值

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

	//获取键所对应的值
	V get(K key)
	{
		//如果没有找到键值，返回空
		if (map.find(key) == map.end())
		{
			return V();
		}
		return map[key]->val;
	}

	//插入键值对
	void put(K key, V val)
	{
		//如果为新插入的节点，则同时插入链表和map
		if (map.find(key) == map.end())
		{
			//插入新的node
			Node<K, V>* node = new Node<K, V>(key, val);
			addLastNode(node);
			map[key] = node;
			return;
		}

		//如果存在，则替换之前的val
		map[key]->val = val;
	}

	//删除键值对
	void remove(K key)
	{
		//如果key不存在，就直接返回
		if (map.find(key) == map.end())
		{
			return;
		}

		//如果key存在，就需要同时在哈希表中和链表中删除，
		//人话就是将节点从双链表中删除
		Node<K,V>* node = map[key];
		map.erase(key);
		removeNode(node);
	}

	//判断哈希表中是否存在key
	bool containsKey(K key)
	{
		return map.find(key) != map.end();
	}


	//返回所有的键
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