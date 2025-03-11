#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename K,typename V>
class MyLinearProbingHashMap1
{
private:
	//�ڵ�ĳ�Ա���Էֱ�Ϊkey��value
	struct KVNode
	{
		K key;
		V val;

		KVNode(K key, V val) :key(key), val(val) {};
	};

	std::vector<KVNode*>table;//��Žڵ������
	int size_;//Ԫ������
	static const int INIT_CAP = 4;//��ʼ������

public:
	MyLinearProbingHashMap1() :MyLinearProbingHashMap1(INIT_CAP)
	{

	}

	//�������Ĺ��캯��
	MyLinearProbingHashMap1(int initCapacity) :size_(0)
	{
		table.resize(initCapacity, nullptr);
	}

	//��Ӽ�ֵ�Ի������޸ļ�ֵ��
	void put(K key, V val)
	{
		//��������������Ϊ0.75,����������
		if (size_ >= table.size() * 0.75)
		{
			resize(table.size() * 2);
		}

		int index = getKeyIndex(key);
		//���key���ڵĻ������޸Ķ�Ӧ��val
		if (table[index] != nullptr)
		{
			table[index]->val = val;
			return;
		}

		//���key�����ڵĻ������
		table[index] = new KVNode(key, val);
		size_++;
	}

	//ɾ����ֵ��
	void remove(K key)
	{
		//���ݣ�����������С��0.125��ʱ�������
		if (size_ < table.size() / 8)
		{
			resize(table.size() / 4);
		}

		//��ȡҪɾ����ֵ�Ե�����
		int index = getKeyIndex(key);
		//�����ֵ�Բ����ھͲ���Ҫɾ��
		if (table[index] == nullptr)
		{
			return;
		}

		//��ʼɾ�����������ص㲿��
		delete table[index];
		table[index] = nullptr;//�ͷ��κ�һ���ڵ���ڴ潨�鶼��Ҫ�����ÿգ�����ᵼ���޷�Ԥ������鷢����
		size_--;

		//����Ԫ�ص������ԣ�����rehash
		//���Ƚ����������ͻ�ļ�ֵ��һ����ǰ��
		index = (index + 1) % table.size();
		while (table[index] != nullptr)//��������ֱ��Ϊnullptr
		{
			KVNode* entry = table[index];
			//���˽ڵ��¼����,Ȼ���ÿ�
			table[index] = nullptr;
			size_--;

			//�ٴν��˽ڵ���뵽table�У���ʱ�ͻ���뵽֮ǰ��ɾ�����Ǹ�������
			//����ʵ������ǰ�ƶ��Ĳ���
			put(entry->key, entry->val);
			delete entry;//������¼�Ľڵ�ɾ��
			index = (index + 1) % table.size();//����Ѱ����һ����ͻ�ļ�ֵ��
		}
	}

	//��ѯ��ֵ��
	//һ���Ƿ���key����Ӧ��value����������ھͷ���null
	V get(K key)
	{
		int index = getKeyIndex(key);
		if (table[index] == nullptr)
		{
			return V();//����Ĭ��ֵ
		}
		return table[index]->val;
	}


	//�������е�key
	std::list<K>keys()
	{
		std::list<K> keys;
		//��һ����������Ȼ��key����һ���������棬��������������ؼ���
		for (KVNode* entry : table)
		{
			if (entry != nullptr)
			{
				keys.push_back(entry->key);
			}
		}
		return keys;
	}

	//�����Ĺ��ߺ���
	int size() const
	{
		return size_;
	}

private:
	//��ϣ��������ӳ�䵽��Ӧtable������
	int hash(K key)
	{
		return (std::hash<K>{}(key) & 0x7fffffff) % table.size();
	}

	//��key��������̽�⣬Ҳ���Ǹ���key����һ������
	int getKeyIndex(K key)
	{
		int index = -1;//���û���ҵ��ͷ��ظ�ֵ
		//��hash���������������Ѱ�ң�û�ҵ�������һλ��
		for (index = hash(key); table[index] != nullptr; index = (index + 1) % table.size())
		{
			if (table[index]->key == key)
			{
				return index;
			}
		}
		return index;
	}

	//�������ݺ���
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
		//����Ӧ�ľ�����Ǩ�Ƶ���table��
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