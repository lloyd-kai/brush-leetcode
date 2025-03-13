#pragma once
#include <iostream>
#include <queue>

//�����Ķ������ڵ����ݽṹ
//����leetcode�ϵĶ���
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};


//�������ĵݹ�������
//���������������ĵݹ�ʹ��������Ⱥ�˳��ֻҪ��������ʵ��ǰ�к������
void traverse(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	//ǰ�������λ�ã����ݽṹʵ�־�ϲ��������дһ��printf(e) ����eΪ�ڵ��ֵ
	traverse(root->left);
	//�������
	traverse(root->right);
	//�������
}


//�������������д��
//����1���������е�����
void levelOrderTraverse1(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::queue<TreeNode*>q;
	q.push(root);
	while (!q.empty())//�����в�Ϊ��ʱ
	{
		//�������е�Ԫ��һһ���ӣ���ӡ�������ӽڵ����
		TreeNode* cur = q.front();
		q.pop();

		//���ʽڵ�
		std::cout << cur->val << std::endl;

		//��cur���ӽڵ����
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

//�����������˼�¼��ǰ���ʽڵ�Ĳ���
void levelOrderTraverse2(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::queue<TreeNode*>q;
	q.push(root);

	//��¼��ǰ�������Ĳ���,���и��ڵ���Ϊ1��
	int depth = 1;
	while (!q.empty())
	{
		//������Ҫÿ�ν�һ��������depth+1,��Ҫ���ȼ�¼��ǰq��size��������������ʱ�����С��仯��
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			TreeNode* cur = q.front();
			q.pop();

			//����cur�ڵ㣬ͬʱֱ�������ڵĲ���
			std::cout << "depth = " << depth << ",val = " << cur->val << std::endl;

			//��cur�����ҽڵ�������
			if (cur->left != nullptr)
			{
				q.push(cur->left);
			}
			if (cur->right != nullptr)
			{
				q.push(cur->right);
			}
		}
		//ÿ������һ���+1
		depth++;
	}
}


//����3:�߽ױ�����������Ȩ�غ�
//���Ȩ�ص����ڵ����ݽṹ
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
	//���ڵ��·��Ȩ�غ���1
	q.push(State(root, 1));

	while (!q.empty())
	{
		State cur = q.front();
		q.pop();
		//����cur�ڵ㣬ͬʱ֪������·��Ȩ�غ�
		std::cout << "depth = " << cur.depth << " ,val = " << cur.node->val << std::endl;

		//��cur�����ҽڵ�������
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