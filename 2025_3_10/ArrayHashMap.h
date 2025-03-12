#pragma once
#include <random>
#include <vector>
#include <unordered_map>
using namespace std;

//数组加强的哈希表
template<typename K,typename V>
class MyArrayHashMap
{
    struct Node {
        K key;
        V val;

        Node(K key, V val) : key(key), val(val) {
        }
    };

    //存储key和key在arr中的索引
    //也就是说用另一个哈希表实现相应的映射
    //也就是让英雄查英雄，让好汉查好汉:-）
    unordered_map<K, int> map;

    //真正存储key_value的数组
    vector<Node>arr;

    //随机数生成器
    default_random_engine e;

public:
    MyArrayHashMap()
    {
        e.seed(random_device()());//初始随机数种子
    }

    //获取键所对应的值
    V get(K key) {
        if (!map.count(key)) {
            return NULL;
        }
        //先通过哈希表找到对应的索引
        //再在数组中找到对应的值
        int index = map[key];
        return arr[index].val;
    }

    //添加键值对
    void put(K key, V val)
    {
        //如果存在键
        if (containsKey(key))
        {
            int i = map[key];
            arr[i].val = val;
            return;
        }

        //新增元素
        arr.push_back(Node(key, val));
        map[key] = arr.size() - 1;//每次都在数组尾部插入键值对
    }

    //删除键值对
    void remove(K key)
    {
        if (!map.count(key))
        {
            return;
        }

        int index = map[key];
        Node node = arr[index];

        //最后一个元素e和第index个元素node交换位置
        //也就是最后一个元素所在的位置就是要删除的地方
        Node e = arr.back();
        swap(arr[index], e);

        //修改map中e.key对应的索引
        map[e.key] = index;

        //在数组中删除最后一个元素
        arr.pop_back();

        //在map中删除node.key
        map.erase(node.key);
    }

    //随机弹出一个键
    K randomKey()
    {
        int n = arr.size();
        uniform_int_distribution<int> u(0, n - 1);
        int randomIndex = u(e);
        return arr[randomIndex].key;
    }

    bool containsKey(K key)
    {
        return map.count(key);
    }

    int size()
    {
        return map.size();
    }


};

void Test_ArrayHashMap(void)
{
    MyArrayHashMap<int, int> map;
    map.put(1, 1);
    map.put(2, 2);
    map.put(3, 3);
    map.put(4, 4);
    map.put(5, 5);

    cout << map.get(1) << endl; // 1
    cout << map.randomKey() << endl;

    map.remove(4);
    cout << map.randomKey() << endl;
    cout << map.randomKey() << endl;

}