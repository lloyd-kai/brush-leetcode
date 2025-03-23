#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "ListNode.h"
using namespace std;


//��Ŀ���ӣ�https://leetcode.cn/problems/merge-k-sorted-lists/
//�������ĺϲ�


//���˼·��ʹ�����ȼ�����,С���ѣ�ÿ�δ���ȡ����Сֵ��Ȼ�����������
//֪ʶ����״��
//1. ���ȼ����е��﷨
//2. �Զ���ȽϺ������﷨
//3. �״���������ȼ����д�ŵ���list��ÿһ��Ԫ��(����)�е�һ���ڵ㣬����ÿ���������ȡ������Ҫ������һ���ڵ���ӵ�������


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);//Ҫ���صĽڵ�
        //ʹ�����ȼ�����
        //���Զ���ȽϺ�����ʵ��С�Ľڵ���ڶѶ�
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq;
        //��Ԫ��(������ָÿһ�������ͷָ��)�������ȼ�������
        for (auto& head : lists)
        {
            if (head != nullptr)
            {
                pq.push(head);
            }
        }
        ListNode* p = &dummy;
        //��ʼ���ڵ�ϲ�
        while (!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            p->next = temp;
            if (temp->next != nullptr)
            {
                pq.push(temp->next);
            }
            p = p->next;
        }

        return dummy.next;

    }
};