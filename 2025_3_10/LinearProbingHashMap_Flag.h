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


    //删除键值对
    //如果键值对不存在就返回null
    void remove(K key)
    {
        if (key == K())
        {
            throw std::invalid_argument("Key is null");
        }

        //缩小容量
        if (size < table.size() / 8)
        {
            resize(table.size() / 2);
        }

        int index = getKeyIndex(key);
        if (index == -1)
        {
            //key不存在,不需要remove
            return;
        }

        //开始删除，也就是将其直接替换为占位符
        table[index] = DUMMY;
        size--;
    }

    //查
    // 返回 key 对应的 val
    // 如果 key 不存在，则返回 null
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

    //判断数组中是否包含key
    bool containsKey(K key) {
        return getKeyIndex(key) != -1;
    }


    //返回所有的键
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
    //对key进行线性探查，返回一个索引
    //根据keys[i] 是否为null判断是否找到对应的key
    int getKeyIndex(K key)
    {
        int step = 0;//记录移动的步数，一旦超过数组的大小就返回-1
        for (int i = hash(key); table[i] != nullptr; i = (i + 1) % table.size())
        {
            step++;
            //防止死循环
            if (step > table.size())
            {
                //这里可以触发一次resize,把记录为删除的占位符删除
                resize(table.size());
                return -1;
            }
            
            KVNode* entry = table[i];
            //遇到占位符直接跳过
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

    //哈希函数，将键映射到table的索引中
    //[0,table.length-1]
    int hash(K key)
    {
        return std::hash<K>{}(key & 0x7fffffff) % table.size();
    }

    //扩容，缩容函数
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