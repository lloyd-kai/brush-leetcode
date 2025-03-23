#pragma once
#include "ListNode.h"


//��Ŀ���ӣ�https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
//ɾ��������n���ڵ�


//֪ʶ����״��
//1. labuladong�������ǻ���������ͷ�ڵ��ǰ��ʵ�ֵģ����û������ͷ�ڵ����ַ���Խ������
//������p1������ͷ�ڵ��������k�� Ȼ��p1,p2ָ��ͬʱ�ƶ�
//p1�ߵ�����ĩβ�Ŀ�ָ��ʱǰ����n - k ����p2Ҳ��head��ʼǰ����n - k����ͣ���ڵ� n - k + 1 ���ڵ��ϣ�
//��ǡ��ͣ����ĵ����� k ���ڵ��ϣ���ʱ��������Ҫ�ҵĴ�
//2. �����ʹ������ͷ�ڵ㣬�����׳�������������member access within null pointer of type 'ListNode'����������Ϊ�˷�ֹ��ָ��

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //����˫ָ�뼼��
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* p1 = &dummy;
        ListNode* p2 = &dummy;
        for (int i = 0; i < n + 1; i++)
        {
            p1 = p1->next;
        }

        //Ȼ��ʼ�ƶ��ڶ���ָ��
        while (p1 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        //��ʱp2�ƶ���ָ��λ�õ���һ��λ�ã�����ɾ��
        p2->next = p2->next->next;

        return dummy.next;

    }
};