#pragma once
#include <iostream>
#include <vector>
using namespace std;

//��Ŀ���ӣ�https://leetcode.cn/problems/remove-element/
//�Ƴ�Ԫ��
//֪ʶ����״��
//���߼��ĽǶȲ��ѣ���������Ż����룬˭��˭����һ����Ҫ�߼��������������⡣


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //����˫ָ��ʵ��
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;

    }
};