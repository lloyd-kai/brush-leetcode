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


    //to be continued....
};