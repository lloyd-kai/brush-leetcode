#pragma once
#include <iostream>
#include "Traverse.h"

//�ֵ���
//���������ԣ��ǳ��ʺ�valΪ�ַ���������
//����������ƥ�䣬�ַ���ȫ�ȷ������൱�㷺��Ӧ��

template<typename V>
struct TrieNode
{
	V val = NULL;
	TRieNode<v>* children[256] = { NULL };//��������������е�һ���ַ������Ա����ظ��洢��ͬ��ǰ׺��
	//��Ҳ���ֵ�������Ϊǰ׺����ԭ��
};


//������API
//�󲿷������ֻ��Ҫ���þ����ˣ�һ�㲻��Ҫ�Եײ�Դ���������
/*
template <typename V>
class TrieMap {
public:
    // �� Map ����� key
    void put(string key, V val);

    // ɾ���� key �Լ���Ӧ��ֵ
    void remove(string key);

    // ���� key ��Ӧ��ֵ���������򷵻� null
    // get("the") -> 4
    // get("tha") -> null
    V get(string key);

    // �ж� key �Ƿ������ Map ��
    // containsKey("tea") -> false
    // containsKey("team") -> true
    bool containsKey(string key);

    // �� Map �����м������� query �����ǰ׺
    // shortestPrefixOf("themxyz") -> "the"
    string shortestPrefixOf(string query);

    // �� Map �����м������� query ���ǰ׺
    // longestPrefixOf("themxyz") -> "them"
    string longestPrefixOf(string query);

    // ��������ǰ׺Ϊ prefix �ļ�
    // keysWithPrefix("th") -> ["that", "the", "them"]
    vector<string> keysWithPrefix(string prefix);

    // �ж��Ǻͷ����ǰ׺Ϊ prefix �ļ�
    // hasKeyWithPrefix("tha") -> true
    // hasKeyWithPrefix("apple") -> false
    bool hasKeyWithPrefix(string prefix);

    // ͨ��� . ƥ�������ַ�����������ƥ��ļ�
    // keysWithPattern("t.a.") -> ["team", "that"]
    vector<string> keysWithPattern(string pattern);

    // ͨ��� . ƥ�������ַ����ж��Ƿ����ƥ��ļ�
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    bool hasKeyWithPattern(string pattern);

    // ���� Map �м�ֵ�Ե�����
    int size();
};
*/