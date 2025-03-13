#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//先序遍历

//这里HashTree不是说有哈希树，而是说我们可以使用哈希表的结构表示二叉树
//示例如下
void createHashTree(void)
{
	//让键作为父节点的ID,值存储子节点id的列表
	unordered_map<int, vector<int>> tree;
	tree[1] = { 2,3 };
	tree[2] = { 4 };
	tree[3] = { 5,6 };

	//遍历tree
	for (auto node : tree)
	{
		for (int i = 0; i < node.second.size(); i++)
		{
			cout << node.first << "的孩子节点为:" << node.second[i] << endl;
		}
	}
}