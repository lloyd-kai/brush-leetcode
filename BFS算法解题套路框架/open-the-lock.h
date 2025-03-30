#pragma once
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

//��Ŀ���ӣ�https://leetcode.cn/problems/open-the-lock/
//���������ϸ�ڣ��������ܣ��ǲ���BFS�������϶���������ӽڵ���Ƕλ���Щ��ͬ
//�򵥵�ֱ�Ӽ��ӽڵ㣬���ӵ���Ҫ����ʵ�������������п��ܵ����
//�㿴�䱾���ֳ�����,��ѧ�����,Ȼ�󽫷����������ӵ����������С�
//���ڷǷ�����ϣ���visited������һ��ʼ��ǲ�������,��������ŷ������ۺ�Ԥ�о��Ǽ����⸴�ӻ���
//�����Ǹ�plusOne,��ʵ����������ٵĺ�������,����ǧ��Ҫ�Ǵ��룬�����䱾�ʣ��޷Ǿ�����ô����:-)



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //����BFSʵ��
        //��¼��Ҫ��������������
        unordered_set<string> deads(deadends.begin(), deadends.end());
        //���һ��ʼ��ûת�ͽ�����:-)
        if (deads.count("0000"))
        {
            return -1;
        }

        //��¼�Ѿ���ٹ�������
        unordered_set<string> visited;
        queue<string> q;
        //��ʼ����
        q.push("0000");
        int step = 0;
        visited.insert("0000");

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();

                //�ж��Ƿ񵽴��յ�
                if (cur == target)
                {
                    return step;
                }

                //û�е����յ㣬����һ�����ܵ�������ϼ������
                for (string neighbor : getNeighbors(cur))
                {
                    if (!visited.count(neighbor) && !deads.count(neighbor))
                    {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            //������һ���+1
            step++;
        }

        //����������˵����ٵĴ��޷���������
        return -1;
    }

    //�����ϲ�
    string plusOne(string s, int j)
    {
        if (s[j] == '9')
        {
            s[j] = '0';
        }
        else
        {
            s[j] += 1;
        }
        return s;
    }

    //�����²�
    string minusOne(string s, int j)
    {
        if (s[j] == '0')
        {
            s[j] = '9';
        }
        else {
            s[j] -= 1;
        }
        return s;
    }

    vector<string> getNeighbors(string s)
    {
        vector<string> neighbors;
        for (int i = 0; i < s.size(); i++)
        {
            neighbors.push_back(plusOne(s, i));
            neighbors.push_back(minusOne(s, i));
        }
        return neighbors;
    }
};