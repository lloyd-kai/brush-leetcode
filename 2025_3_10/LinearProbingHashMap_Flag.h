#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename K, typename V>
class MyLinearProbingHashMap2 {
    // 键值对节点
    struct KVNode {
        K key;
        V val;

        KVNode(K key, V val) : key(key), val(val) {
        }
    };


    //不同的是将被删除的地方替换为占位符，一般用宏定义或者是枚举类型代替,
    KVNode* DUMMY = new KVNode(K(), V());

    // 真正存储键值对的 table 数组
    std::vector<KVNode*> table;
    // HashMap 中的键值对个数
    int size;
    // 默认的初始化容量
    static const int INIT_CAP = 4;

public:
    MyLinearProbingHashMap2() :MyLinearProbingHashMap2(INIT_CAP)
    {

    }

    MyLinearProbingHashMap2(int cap) :size(0), table(cap, nullptr)
    {

    }

    //添加或者修改键值对
    void put(K key, V val)
    {
        if (key == K())
        {
            throw std::invalid_argument("Key is null");
        }

        // 负载因子默认设为 0.75，超过则扩容
        if (size >= table.size() * 0.75) {
            resize(table.size() * 2);
        }

        int index = getKeyIndex(key);
        if (index != -1) {
            // key 已存在，修改对应的 val
            table[index]->val = val;
            return;
        }

        // key 不存在
        KVNode* x = new KVNode(key, val);
        // 在 table 中向后找一个空位或者占位符，插入
        index = hash(key);
        while (table[index] != nullptr && table[index] != DUMMY) {
            index = (index + 1) % table.size();
        }
        table[index] = x;
        size++;
    }


    //to be continued....
};