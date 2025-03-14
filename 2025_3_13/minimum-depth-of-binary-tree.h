#pragma once
//题目链接 https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
const int INT_MAX = 1e5 + 9;
#include "Traverse.h"
#include <iostream>
#include <queue>

//求树的最短路径长度
//方法1 DFS
//只需要按照遍历的基本框架写就行，剩下的就比大小更新depth就行

class Solution1
{
private:
	//记录最小深度(根节点到最近的叶子节点之间的距离)
	int minDepthValue = INT_MAX;
	//记录当前遍历到的节点深度
	int currentDepth = 0;

public:
	//使用leetcode中常用的树节点的定义
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		//从根节点开始遍历
		traverse(root);
		return minDepthValue;
	}

	//遍历函数
	void traverse(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		//前序位置进入节点的时候增加当前深度
		currentDepth++;

		//如果当前节点是叶子节点，就尝试更新最小深度
		if (root->left == nullptr && root->right == nullptr)
		{
			minDepthValue = std::min(minDepthValue, currentDepth);
		}

		//遍历的基本框架
		traverse(root->left);
		traverse(root->right);

		//后序位置离开节点的时候减少当前深度
		currentDepth--;
	}
};


//BFS实现
class Solution2
{
public:
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		//数据结构中BFS遍历是需要借助队列的
		std::queue<TreeNode*> q;
		q.push(root);

		//root本身就是一层，所以初始化为1
		int depth = 1;

		while (!q.empty())
		{
			int sz = q.size();

			//遍历当前的节点
			for (int i = 0; i < sz; i++)
			{
				TreeNode* cur = q.front();
				q.pop();

				//判断是否到达子节点
				if (cur->left == nullptr && cur->right == nullptr)
				{
					return depth;
				}

				//将节点入队
				if (cur->left != nullptr)
				{
					q.push(cur->left);
				}

				if (cur->right != nullptr)
				{
					q.push(cur->right);
				}
			}
			//每一层遍历完深度就+1
			depth++;
		}
		return depth;
	}
};