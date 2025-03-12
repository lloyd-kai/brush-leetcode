#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename K, typename V>
class MyLinearProbingHashMap2 {
    // ��ֵ�Խڵ�
    struct KVNode {
        K key;
        V val;

        KVNode(K key, V val) : key(key), val(val) {
        }
    };


    //��ͬ���ǽ���ɾ���ĵط��滻Ϊռλ����һ���ú궨�������ö�����ʹ���,
    KVNode* DUMMY = new KVNode(K(), V());

    // �����洢��ֵ�Ե� table ����
    std::vector<KVNode*> table;
    // HashMap �еļ�ֵ�Ը���
    int size;
    // Ĭ�ϵĳ�ʼ������
    static const int INIT_CAP = 4;

public:
    MyLinearProbingHashMap2() :MyLinearProbingHashMap2(INIT_CAP)
    {

    }

    MyLinearProbingHashMap2(int cap) :size(0), table(cap, nullptr)
    {

    }

    //��ӻ����޸ļ�ֵ��
    void put(K key, V val)
    {
        if (key == K())
        {
            throw std::invalid_argument("Key is null");
        }

        // ��������Ĭ����Ϊ 0.75������������
        if (size >= table.size() * 0.75) {
            resize(table.size() * 2);
        }

        int index = getKeyIndex(key);
        if (index != -1) {
            // key �Ѵ��ڣ��޸Ķ�Ӧ�� val
            table[index]->val = val;
            return;
        }

        // key ������
        KVNode* x = new KVNode(key, val);
        // �� table �������һ����λ����ռλ��������
        index = hash(key);
        while (table[index] != nullptr && table[index] != DUMMY) {
            index = (index + 1) % table.size();
        }
        table[index] = x;
        size++;
    }


    //ɾ����ֵ��
    //�����ֵ�Բ����ھͷ���null
    void remove(K key)
    {
        if (key == K())
        {
            throw std::invalid_argument("Key is null");
        }

        //��С����
        if (size < table.size() / 8)
        {
            resize(table.size() / 2);
        }

        int index = getKeyIndex(key);
        if (index == -1)
        {
            //key������,����Ҫremove
            return;
        }

        //��ʼɾ����Ҳ���ǽ���ֱ���滻Ϊռλ��
        table[index] = DUMMY;
        size--;
    }

    //��
    // ���� key ��Ӧ�� val
    // ��� key �����ڣ��򷵻� null
    V get(K key) {
        if (key == K()) {
            throw std::invalid_argument("key is null");
        }

        int index = getKeyIndex(key);
        if (index == -1) {
            return V();
        }

        return table[index]->val;
    }

    //�ж��������Ƿ����key
    bool containsKey(K key) {
        return getKeyIndex(key) != -1;
    }


    //�������еļ�
    std::list<K> keys() {
        std::list<K> keys;
        for (auto entry : table) {
            if (entry != nullptr && entry != DUMMY) {
                keys.push_back(entry->key);
            }
        }
        return keys;
    }

    int getSize()
    {
        return size;
    }

private:
    //��key��������̽�飬����һ������
    //����keys[i] �Ƿ�Ϊnull�ж��Ƿ��ҵ���Ӧ��key
    int getKeyIndex(K key)
    {
        int step = 0;//��¼�ƶ��Ĳ�����һ����������Ĵ�С�ͷ���-1
        for (int i = hash(key); table[i] != nullptr; i = (i + 1) % table.size())
        {
            step++;
            //��ֹ��ѭ��
            if (step > table.size())
            {
                //������Դ���һ��resize,�Ѽ�¼Ϊɾ����ռλ��ɾ��
                resize(table.size());
                return -1;
            }
            
            KVNode* entry = table[i];
            //����ռλ��ֱ������
            if (entry == DUMMY)
            {
                continue;
            }
            if (entry->val == key)
            {
                return i;
            }
        }
        return -1;
    }

    //��ϣ����������ӳ�䵽table��������
    //[0,table.length-1]
    int hash(K key)
    {
        return std::hash<K>{}(key & 0x7fffffff) % table.size();
    }

    //���ݣ����ݺ���
    void resize(int cap)
    {
        MyLinearProbingHashMap2<K, V> newCap(cap);
        for (auto entry : table)
        {
            if (entry != nullptr && entry != DUMMY)
            {
                newCap.put(entry->key, entry->val);
            }
        }
        this->table = newCap.table;
    }
};

void Test_MyLinearProbingHashMap2(void)
{
    MyLinearProbingHashMap2<int, int> map;
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

    std::cout << map.containsKey(20) << std::endl; // 0 (false)
    std::cout << map.get(20) << std::endl; // 0 (null)
    std::cout << map.get(30) << std::endl; // 30
}