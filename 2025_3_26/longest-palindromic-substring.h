#pragma once
#include <iostream>
#include <string>
using namespace std;


//题目链接：https://leetcode.cn/problems/longest-palindromic-substring/
//最长回文子串
//总结和知识点
//1. 关键是遍历每一个元素，以这个元素为中心，向两侧找最长的回文串
//2. 易错的地方是没有考虑到字符串长度为奇数和为偶数的情况。


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        //开始遍历
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = Palidrome(s, i, i);
            string s2 = Palidrome(s, i, i + 1);
            //比较找到最大的回文子串
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

    //返回以i到r为中心的最长回文子串
    string Palidrome(string s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[r] == s[l])
        {
            l--;
            r++;
        }

        return s.substr(l + 1, r - l - 1);
    }
};