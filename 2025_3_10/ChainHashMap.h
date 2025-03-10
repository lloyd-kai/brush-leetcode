#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//������ʵ��hashmap

template<typename K, typename V>
class MyChainHashMap
{
	//������ʹ�õĵ�����ڵ㣬�洢key-value��
	struct KVNode
	{
		K key;
		V value;

		KVNode(K key, V val) :key(key), value(std::move(val)) {};
	};

	//��ϣ��ĵײ����飬ÿһ������Ԫ����һ������,������ÿһ���ڵ���KVNode�洢��ֵ��
	std::vector<std::list<KVNode>>table;

	//��ϣ���д����ֵ�Եĸ���
	int size_;
	//�ײ�����ĳ�ʼ����
	static constexpr int INIT_CAP = 4;

	//��ϣ����������ֵ��ӳ�䵽table������
	int hash(K key)
	{
		//���ͣ��Ȱ�λ�뽫��ת��Ϊ�Ǹ�����Ȼ��ȡģ��ֹ����Խ��
		return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
	}

	//��\���ݺ���
	void resize(int newCap)
	{
		//����Ҫ����һ���µ�HashMap
		
		//���⴫�������Ϊ0�����Ǹ�ֵ
		newCap = std::max(newCap, 1);
		MyChainHashMap<K, V>newMap(newCap);
		//ö�ٵ�ǰHashMap�����еļ�ֵ��
		for (auto& list : table)
		{
			for (auto& node : list)
			{
				//����ֵ��ת�Ƶ��µ�HashMap��
				newMap.put(node.key, node.value);
			}
		}

		//����ǰHashMap�ĵײ�table����
		this->table = newMap.table;
	}

public:
	MyChainHashMap() :MyChainHashMap(INIT_CAP)
	{

	}

	explicit MyChainHashMap(int initCapacity)
	{
		size_ = 0;
		//��֤�ײ��������������Ϊ1,��Ϊhash���������������㣬������ֳ���������
		//Ҳ���ǲ����Ϸ����ж�
		initCapacity = std::max(initCapacity, 1);
		table.resize(initCapacity);
	}


	//HashMap����ӻ���ɾ����ֵ��

	//��Ӽ�ֵ��
	//���key�Ѿ����ڣ���ֵ�޸�Ϊval
	void put(K key, V val)
	{
		auto& list = table[hash(key)];
		//���key֮ǰ���ڣ����޸Ķ�Ӧ��val
		for (auto& node : list)
		{
			if (node.key == key)
			{
				node.value = val;
				return;
			}
		}

		//���֮ǰ�����ڣ�����룬size++
		list.emplace_back(key, val);
		size_++;

		//���Ԫ�ص����������˸������ӣ���������
		//�������ø�������Ĭ��Ϊ0.75
		if (size_ >= table.size() * 0.75)
		{
			resize(table.size() * 2);
		}
	}

	//ɾ����ֵ��
	void remove(K key)
	{
		auto& list = table[hash(key)];
		//���key���ڣ���ɾ����size--
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (it->key == key)
			{
				list.erase(it);
				size_--;

				//���ݣ�����������С��0.125ʱ��
				if (size_ <= table.size() / 8)
				{
					resize(table.size() / 4);
				}
				return;
			}
		}
	}


	//���Ҽ����Ե�ֵ
	//���key�����ڣ�����nullptr
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

	//�������е�key
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


	//���������ĺ���
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
	// [1, 3]��˳����ܲ�ͬ��
	std::cout << std::endl;

	map.remove(1);
	map.remove(2);
	map.remove(3);
	std::cout << (map.get(1) == nullptr ? "null" : std::to_string(*map.get(1))) << std::endl; // null

}
