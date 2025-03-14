#pragma once
//��Ŀ���� https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
const int INT_MAX = 1e5 + 9;
#include "Traverse.h"
#include <iostream>
#include <queue>

//���������·������
//����1 DFS
//ֻ��Ҫ���ձ����Ļ������д���У�ʣ�µľͱȴ�С����depth����

class Solution1
{
private:
	//��¼��С���(���ڵ㵽�����Ҷ�ӽڵ�֮��ľ���)
	int minDepthValue = INT_MAX;
	//��¼��ǰ�������Ľڵ����
	int currentDepth = 0;

public:
	//ʹ��leetcode�г��õ����ڵ�Ķ���
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		//�Ӹ��ڵ㿪ʼ����
		traverse(root);
		return minDepthValue;
	}

	//��������
	void traverse(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		//ǰ��λ�ý���ڵ��ʱ�����ӵ�ǰ���
		currentDepth++;

		//�����ǰ�ڵ���Ҷ�ӽڵ㣬�ͳ��Ը�����С���
		if (root->left == nullptr && root->right == nullptr)
		{
			minDepthValue = std::min(minDepthValue, currentDepth);
		}

		//�����Ļ������
		traverse(root->left);
		traverse(root->right);

		//����λ���뿪�ڵ��ʱ����ٵ�ǰ���
		currentDepth--;
	}
};


//BFSʵ��
class Solution2
{
public:
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		//���ݽṹ��BFS��������Ҫ�������е�
		std::queue<TreeNode*> q;
		q.push(root);

		//root�������һ�㣬���Գ�ʼ��Ϊ1
		int depth = 1;

		while (!q.empty())
		{
			int sz = q.size();

			//������ǰ�Ľڵ�
			for (int i = 0; i < sz; i++)
			{
				TreeNode* cur = q.front();
				q.pop();

				//�ж��Ƿ񵽴��ӽڵ�
				if (cur->left == nullptr && cur->right == nullptr)
				{
					return depth;
				}

				//���ڵ����
				if (cur->left != nullptr)
				{
					q.push(cur->left);
				}

				if (cur->right != nullptr)
				{
					q.push(cur->right);
				}
			}
			//ÿһ���������Ⱦ�+1
			depth++;
		}
		return depth;
	}
};