#pragma once
#include <iostream>
#include <string>
using namespace std;


//��Ŀ���ӣ�https://leetcode.cn/problems/longest-palindromic-substring/
//������Ӵ�
//�ܽ��֪ʶ��
//1. �ؼ��Ǳ���ÿһ��Ԫ�أ������Ԫ��Ϊ���ģ�����������Ļ��Ĵ�
//2. �״�ĵط���û�п��ǵ��ַ�������Ϊ������Ϊż���������


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        //��ʼ����
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = Palidrome(s, i, i);
            string s2 = Palidrome(s, i, i + 1);
            //�Ƚ��ҵ����Ļ����Ӵ�
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

    //������i��rΪ���ĵ�������Ӵ�
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