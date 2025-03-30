#pragma once
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

//�����㷨����BFS
//�����������·��


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";

        //�ȳ�ʼ��һ��ʼ���ַ���
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                start = start + to_string(board[i][j]);
            }
        }

        //BFS�ĺ��Ŀ�ܡ����ڶ���ʵ�ַ���
        //1. ��������
        queue<string> q;
        //2. visited���飬��ֹ��ѭ��
        unordered_set<string> visited;
        //3. ���ȼ������,Ȼ��visited��Ϊtrue
        q.push(start);
        visited.insert(start);

        //��¼����
        int step = 0;
        //��������Ԫ�ز�Ϊ��ʱ����
        while (!q.empty())
        {
            int sz = q.size();
            //��ʼ�������
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                //�ж��Ƿ��Ѿ��������
                if (target == cur)
                {
                    return step;
                }

                //���û�дﵽ��������0�����ھӽ���λ��
                for (string neighborBoard : getNeighbors(cur))
                {
                    //��ֹ�߻�ͷ·
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
        // ��¼һά�ַ�������������
        //���ڴ���Ƚ����⣬����ֱ��д������Ҫ����ԭ��
        vector<vector<int>> mapping = {
            //������������Ǹ���λ��,����0�����һ�е�һ��Ԫ�أ���������
            //һά�����Ԫ�ش������ھ�Ԫ�ص�λ��
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };

        int idx = board.find('0');
        vector<string> neighbors;
        //�����п��ܽ����Ľ�����뵽������
        for (int adj : mapping[idx])
        {
            string new_board = swap(board, idx, adj);
            neighbors.push_back(new_board);
        }
        return neighbors;
    }

    //��������ʵ��
    string swap(string board, int i, int j)
    {
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
        return board;
    }
};