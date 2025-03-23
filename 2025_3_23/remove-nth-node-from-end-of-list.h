#pragma once
#include "ListNode.h"


//题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
//删除倒数第n个节点


//知识点和易错点
//1. labuladong的推理是基于有虚拟头节点的前提实现的，如果没有虚拟头节点会出现访问越界的情况
//首先让p1从虚拟头节点出发，走k步 然后p1,p2指针同时移动
//p1走到链表末尾的空指针时前进了n - k 步，p2也从head开始前进了n - k步，停留在第 n - k + 1 个节点上，
//即恰好停链表的倒数第 k 个节点上，此时就是我们要找的答案
//2. 如果不使用虚拟头节点，很容易出现这样的问题member access within null pointer of type 'ListNode'，这样就是为了防止空指针

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //利用双指针技巧
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* p1 = &dummy;
        ListNode* p2 = &dummy;
        for (int i = 0; i < n + 1; i++)
        {
            p1 = p1->next;
        }

        //然后开始移动第二个指针
        while (p1 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        //此时p2移动到指定位置的上一个位置，方便删除
        p2->next = p2->next->next;

        return dummy.next;

    }
};