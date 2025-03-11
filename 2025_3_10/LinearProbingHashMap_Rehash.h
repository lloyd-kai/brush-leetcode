#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename K,typename V>
class MyLinearProbingHashMap1
{
private:
	//节点的成员属性分别为key与value
	struct KVNode
	{
		K key;
		V val;

		KVNode(K key, V val) :key(key), val(val) {};
	};

	std::vector<KVNode*>table;//存放节点的数组
	int size_;//元素数量
	static const int INIT_CAP = 4;//初始化容量

public:
	MyLinearProbingHashMap1() :MyLinearProbingHashMap1(INIT_CAP)
	{

	}

	//带参数的构造函数
	MyLinearProbingHashMap1(int initCapacity) :size_(0)
	{
		table.resize(initCapacity, nullptr);
	}

	//添加键值对或者是修改键值对
	void put(K key, V val)
	{
		//将负载因子设置为0.75,超过就扩容
		if (size_ >= table.size() * 0.75)
		{
			resize(table.size() * 2);
		}

		int index = getKeyIndex(key);
		//如果key存在的话，就修改对应的val
		if (table[index] != nullptr)
		{
			table[index]->val = val;
			return;
		}

		//如果key不存在的话就添加
		table[index] = new KVNode(key, val);
		size_++;
	}

	//删除键值对
	void remove(K key)
	{
		//缩容，当负载因子小于0.125的时候就缩容
		if (size_ < table.size() / 8)
		{
			resize(table.size() / 4);
		}

		//获取要删除键值对的索引
		int index = getKeyIndex(key);
		//如果键值对不存在就不需要删除
		if (table[index] == nullptr)
		{
			return;
		}

		//开始删除————重点部分
		delete table[index];
		table[index] = nullptr;//释放任何一个节点的内存建议都需要将其置空，否则会导致无法预测的事情发生。
		size_--;

		//保持元素的连续性，进行rehash
		//首先将与此索引冲突的键值对一个个前移
		index = (index + 1) % table.size();
		while (table[index] != nullptr)//持续遍历直到为nullptr
		{
			KVNode* entry = table[index];
			//将此节点记录下来,然后置空
			table[index] = nullptr;
			size_--;

			//再次将此节点插入到table中，此时就会插入到之前被删除的那个索引处
			//变向实现了向前移动的操作
			put(entry->key, entry->val);
			delete entry;//将所记录的节点删除
			index = (index + 1) % table.size();//继续寻找下一个冲突的键值对
		}
	}

	//查询键值对
	//一般是返回key所对应的value，如果不存在就返回null
	V get(K key)
	{
		int index = getKeyIndex(key);
		if (table[index] == nullptr)
		{
			return V();//返回默认值
		}
		return table[index]->val;
	}


	//返回所有的key
	std::list<K>keys()
	{
		std::list<K> keys;
		//先一个个遍历，然后将key放在一个容器里面，最后把这个容器返回即可
		for (KVNode* entry : table)
		{
			if (entry != nullptr)
			{
				keys.push_back(entry->key);
			}
		}
		return keys;
	}

	//其他的工具函数
	int size() const
	{
		return size_;
	}

private:
	//哈希函数，将映射到对应table的索引
	int hash(K key)
	{
		return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
	}

	//对key进行线性探测，也就是根据key返回一个索引
	int getKeyIndex(K key)
	{
		int index = -1;//如果没有找到就返回负值
		//用hash函数计算出的索引寻找，没找到就往后一位找
		for (index = hash(key); table[index] != nullptr; index = (index + 1) % table.size())
		{
			if (table[index]->key == key)
			{
				return index;
			}
		}
		return index;
	}

	//扩容缩容函数
	void resize(int newCap)
	{
		MyLinearProbingHashMap1<K, V> newMap(newCap);
		for (KVNode* entry : table)
		{
			if (entry != nullptr)
			{
				newMap.put(entry->key, entry->val);
			}
		}
		//将对应的旧数据迁移到新table中
		table = std::move(newMap.table);
	}


};

void Test_MyLinearProbingHashMap1(void)
{
	MyLinearProbingHashMap1<int, int> map;
	map.put(1, 1);
	map.put(2, 2);
	map.put(10, 10);
	map.put(20, 20);
	map.put(30, 30);
	map.put(3, 3);
	std::cout << map.get(1) << std::endl; // 1
	std::cout << map.get(2) << std::endl; // 2
	std::cout << map.get(20) << std::endl; // 20

	map.put(1, 100);
	std::cout << map.get(1) << std::endl; // 100

	map.remove(20);
	std::cout << map.get(20) << std::endl; // 0 (null)
	std::cout << map.get(30) << std::endl; // 30

}