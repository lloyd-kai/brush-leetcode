#pragma once
#include <iostream>
#include <vector>
using namespace std;

//题目链接：https://leetcode.cn/problems/remove-element/
//移除元素
//知识点和易错点
//从逻辑的角度不难，但是如何优化代码，谁先谁后是一个需要逻辑推演能力的问题。


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //利用双指针实现
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