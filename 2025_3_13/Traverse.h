#pragma once
#include <iostream>
#include <queue>

//基本的二叉树节点数据结构
//就是leetcode上的定义
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};


//二叉树的递归遍历框架
//核心是左右子树的递归和处理函数的先后顺序，只要调换就能实现前中后序遍历
void traverse(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	//前序遍历的位置，数据结构实现就喜欢在这里写一个printf(e) 其中e为节点的值
	traverse(root->left);
	//中序遍历
	traverse(root->right);
	//后序遍历
}


//层序遍历的三种写法
//方法1：借助队列的力量
void levelOrderTraverse1(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::queue<TreeNode*>q;
	q.push(root);
	while (!q.empty())//当队列不为空时
	{
		//将队列中的元素一一出队，打印并将其子节点入队
		TreeNode* cur = q.front();
		q.pop();

		//访问节点
		std::cout << cur->val << std::endl;

		//把cur的子节点入队
		if (cur->left != nullptr)
		{
			q.push(cur->left);
		}
		if(cur->right !=nullptr)
		{
			q.push(cur->right);
		}
	}
}

//方法二：多了记录当前访问节点的层数
void levelOrderTraverse2(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::queue<TreeNode*>q;
	q.push(root);

	//记录当前遍历到的层数,其中根节点视为1层
	int depth = 1;
	while (!q.empty())
	{
		//由于需要每次将一层遍历完后depth+1,需要事先记录当前q的size，否则后面遍历的时候其大小会变化。
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			TreeNode* cur = q.front();
			q.pop();

			//访问cur节点，同时直到它所在的层数
			std::cout << "depth = " << depth << ",val = " << cur->val << std::endl;

			//把cur的左右节点加入队列
			if (cur->left != nullptr)
			{
				q.push(cur->left);
			}
			if (cur->right != nullptr)
			{
				q.push(cur->right);
			}
		}
		//每遍历完一层就+1
		depth++;
	}
}


//方法3:高阶遍历，增加了权重和
//添加权重的树节点数据结构
class State
{
public:
	TreeNode* node;
	int depth;

	State(TreeNode* node, int depth) :node(node), depth(depth) {};
};

void levelOrderTraverse(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::queue<State>q;
	//根节点的路径权重和是1
	q.push(State(root, 1));

	while (!q.empty())
	{
		State cur = q.front();
		q.pop();
		//访问cur节点，同时知道它的路径权重和
		std::cout << "depth = " << cur.depth << " ,val = " << cur.node->val << std::endl;

		//把cur的左右节点加入队列
		if (cur.node->left != nullptr)
		{
			q.push(State(cur.node->left,cur.depth+1));
		}
		if (cur.node->right != nullptr)
		{
			q.push(State(cur.node->right, cur.depth + 1));
		}
	}
}