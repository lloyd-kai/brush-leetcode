#pragma once
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

//题目链接：https://leetcode.cn/problems/open-the-lock/
//不看具体的细节，看大体框架，是不是BFS？基本上都是在添加子节点的那段会有些不同
//简单的直接加子节点，复杂的需要根据实际情况穷举其所有可能的情况
//你看其本质又出来了,科学的穷举,然后将符合题意的添加到辅助队列中。
//对于非法的组合，在visited数组中一开始标记不就行了,如果还想着分类讨论和预判就是简单问题复杂化了
//至于那个plusOne,其实就是用来穷举的函数罢了,所以千万不要记代码，参悟其本质，无非就是这么回事:-)



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //利用BFS实现
        //记录需要跳过的死亡密码
        unordered_set<string> deads(deadends.begin(), deadends.end());
        //如果一开始还没转就结束了:-)
        if (deads.count("0000"))
        {
            return -1;
        }

        //记录已经穷举过的密码
        unordered_set<string> visited;
        queue<string> q;
        //开始遍历
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

                //判断是否到达终点
                if (cur == target)
                {
                    return step;
                }

                //没有到达终点，将下一个可能的密码组合加入队列
                for (string neighbor : getNeighbors(cur))
                {
                    if (!visited.count(neighbor) && !deads.count(neighbor))
                    {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            //遍历完一层就+1
            step++;
        }

        //如果到这里就说明穷举的答案无法满足题意
        return -1;
    }

    //密码上拨
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

    //密码下拨
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