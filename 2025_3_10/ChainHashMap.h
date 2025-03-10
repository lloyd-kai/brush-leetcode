#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//拉链法实现hashmap

template<typename K, typename V>
class MyChainHashMap
{
	//拉链法使用的单链表节点，存储key-value对
	struct KVNode
	{
		K key;
		V value;

		KVNode(K key, V val) :key(key), value(std::move(val)) {};
	};

	//哈希表的底层数组，每一个数组元素是一个链表,链表中每一个节点是KVNode存储键值对
	std::vector<std::list<KVNode>>table;

	//哈希表中存入键值对的个数
	int size_;
	//底层数组的初始容量
	static constexpr int INIT_CAP = 4;

	//哈希函数，将键值对映射到table的索引
	int hash(K key)
	{
		//解释：先按位与将其转化为非负数，然后取模防止索引越界
		return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
	}

	//扩\缩容函数
	void resize(int newCap)
	{
		//首先要构造一个新的HashMap
		
		//避免传入的容量为0或者是负值
		newCap = std::max(newCap, 1);
		MyChainHashMap<K, V>newMap(newCap);
		//枚举当前HashMap中所有的键值对
		for (auto& list : table)
		{
			for (auto& node : list)
			{
				//将键值对转移到新的HashMap中
				newMap.put(node.key, node.value);
			}
		}

		//将当前HashMap的底层table换掉
		this->table = newMap.table;
	}

public:
	MyChainHashMap() :MyChainHashMap(INIT_CAP)
	{

	}

	explicit MyChainHashMap(int initCapacity)
	{
		size_ = 0;
		//保证底层数组的容量至少为1,因为hash函数中有求余运算，避免出现除以零的情况
		//也就是参数合法性判断
		initCapacity = std::max(initCapacity, 1);
		table.resize(initCapacity);
	}


	//HashMap中添加或者删除键值对

	//添加键值对
	//如果key已经存在，则将值修改为val
	void put(K key, V val)
	{
		auto& list = table[hash(key)];
		//如果key之前存在，则修改对应的val
		for (auto& node : list)
		{
			if (node.key == key)
			{
				node.value = val;
				return;
			}
		}

		//如果之前不存在，则插入，size++
		list.emplace_back(key, val);
		size_++;

		//如果元素的数量超过了负载因子，进行扩容
		//这里设置负载因子默认为0.75
		if (size_ >= table.size() * 0.75)
		{
			resize(table.size() * 2);
		}
	}

	//删除键值对
	void remove(K key)
	{
		auto& list = table[hash(key)];
		//如果key存在，则删除，size--
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (it->key == key)
			{
				list.erase(it);
				size_--;

				//缩容，当负载因子小于0.125时，
				if (size_ <= table.size() / 8)
				{
					resize(table.size() / 4);
				}
				return;
			}
		}
	}


	//查找键所对的值
	//如果key不存在，返回nullptr
	V get(K key)
	{
		const auto& list = table[hash(key)];
		for (const auto& node : list)
		{
			if (node.key == key)
			{
				return node.value;
			}
		}
		return nullptr;
	}

	//返回所有的key
	std::list<K>keys()
	{
		std::list<K> keys;
		for (const auto& list : table)
		{
			for (const auto& node : list)
			{
				keys.push_back(node.key);
			}
		}
		return keys;
	}


	//其他常见的函数
	int size() const
	{
		return size_;
	}

};


void Test_ChainHashMap(void)
{
	MyChainHashMap<int, std::shared_ptr<int> > map;
	map.put(1, std::make_shared<int>(1));
	map.put(2, std::make_shared<int>(2));
	map.put(3, std::make_shared<int>(3));
	std::cout << *map.get(1) << std::endl; // 1
	std::cout << *map.get(2) << std::endl; // 2

	map.put(1, std::make_shared<int>(100));
	std::cout << *map.get(1) << std::endl; // 100

	map.remove(2);
	std::cout << (map.get(2) == nullptr ? "null" : std::to_string(*map.get(2))) << std::endl; // null

	for (const auto key : map.keys()) {
		std::cout << key << " ";
	}
	// [1, 3]（顺序可能不同）
	std::cout << std::endl;

	map.remove(1);
	map.remove(2);
	map.remove(3);
	std::cout << (map.get(1) == nullptr ? "null" : std::to_string(*map.get(1))) << std::endl; // null

}
