#pragma once
#include <random>
#include <vector>
#include <unordered_map>
using namespace std;

//�����ǿ�Ĺ�ϣ��
template<typename K,typename V>
class MyArrayHashMap
{
    struct Node {
        K key;
        V val;

        Node(K key, V val) : key(key), val(val) {
        }
    };

    //�洢key��key��arr�е�����
    //Ҳ����˵����һ����ϣ��ʵ����Ӧ��ӳ��
    //Ҳ������Ӣ�۲�Ӣ�ۣ��úú���ú�:-��
    unordered_map<K, int> map;

    //�����洢key_value������
    vector<Node>arr;

    //�����������
    default_random_engine e;

public:
    MyArrayHashMap()
    {
        e.seed(random_device()());//��ʼ���������
    }

    //��ȡ������Ӧ��ֵ
    V get(K key) {
        if (!map.count(key)) {
            return NULL;
        }
        //��ͨ����ϣ���ҵ���Ӧ������
        //�����������ҵ���Ӧ��ֵ
        int index = map[key];
        return arr[index].val;
    }

    //��Ӽ�ֵ��
    void put(K key, V val)
    {
        //������ڼ�
        if (containsKey(key))
        {
            int i = map[key];
            arr[i].val = val;
            return;
        }

        //����Ԫ��
        arr.push_back(Node(key, val));
        map[key] = arr.size() - 1;//ÿ�ζ�������β�������ֵ��
    }

    //ɾ����ֵ��
    void remove(K key)
    {
        if (!map.count(key))
        {
            return;
        }

        int index = map[key];
        Node node = arr[index];

        //���һ��Ԫ��e�͵�index��Ԫ��node����λ��
        //Ҳ�������һ��Ԫ�����ڵ�λ�þ���Ҫɾ���ĵط�
        Node e = arr.back();
        swap(arr[index], e);

        //�޸�map��e.key��Ӧ������
        map[e.key] = index;

        //��������ɾ�����һ��Ԫ��
        arr.pop_back();

        //��map��ɾ��node.key
        map.erase(node.key);
    }

    //�������һ����
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