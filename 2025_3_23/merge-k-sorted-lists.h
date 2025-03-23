#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "ListNode.h"
using namespace std;


//题目链接：https://leetcode.cn/problems/merge-k-sorted-lists/
//多个链表的合并


//解决思路，使用优先级队列,小顶堆，每次从中取出最小值，然后插入链表中
//知识点和易错点
//1. 优先级队列的语法
//2. 自定义比较函数的语法
//3. 易错：这里的优先级队列存放的是list中每一个元素(链表)中的一个节点，所以每次如果将其取出，就要将其下一个节点添加到队列中


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);//要返回的节点
        //使用优先级队列
        //先自定义比较函数，实现小的节点放在堆顶
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq;
        //将元素(这里是指每一个链表的头指针)放入优先级队列中
        for (auto& head : lists)
        {
            if (head != nullptr)
            {
                pq.push(head);
            }
        }
        ListNode* p = &dummy;
        //开始将节点合并
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