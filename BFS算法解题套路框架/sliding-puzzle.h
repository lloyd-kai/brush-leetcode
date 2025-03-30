#pragma once
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

//经典算法——BFS
//常用于找最短路径


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";

        //先初始化一开始的字符串
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                start = start + to_string(board[i][j]);
            }
        }

        //BFS的核心框架——第二种实现方法
        //1. 辅助队列
        queue<string> q;
        //2. visited数组，防止死循环
        unordered_set<string> visited;
        //3. 根先加入队列,然后将visited置为true
        q.push(start);
        visited.insert(start);

        //记录步数
        int step = 0;
        //当队列中元素不为空时继续
        while (!q.empty())
        {
            int sz = q.size();
            //开始层序遍历
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                //判断是否已经到达局面
                if (target == cur)
                {
                    return step;
                }

                //如果没有达到，将数字0与其邻居交换位置
                for (string neighborBoard : getNeighbors(cur))
                {
                    //防止走回头路
                    if (!visited.count(neighborBoard))
                    {
                        q.push(neighborBoard);
                        visited.insert(neighborBoard);
                    }
                }

            }
            step++;

        }

        return -1;
    }

    vector<string> getNeighbors(string board)
    {
        // 记录一维字符串的相邻索引
        //由于此题比较特殊，可以直接写，但是要掌握原理
        vector<vector<int>> mapping = {
            //行索引代表的是给的位置,比如0代表第一行第一个元素，依次类推
            //一维数组的元素代表其邻居元素的位置
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };

        int idx = board.find('0');
        vector<string> neighbors;
        //将所有可能交换的结果加入到队列中
        for (int adj : mapping[idx])
        {
            string new_board = swap(board, idx, adj);
            neighbors.push_back(new_board);
        }
        return neighbors;
    }

    //交换函数实现
    string swap(string board, int i, int j)
    {
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
        return board;
    }
};