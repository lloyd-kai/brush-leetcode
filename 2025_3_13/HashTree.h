#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//�������

//����HashTree����˵�й�ϣ��������˵���ǿ���ʹ�ù�ϣ��Ľṹ��ʾ������
//ʾ������
void createHashTree(void)
{
	//�ü���Ϊ���ڵ��ID,ֵ�洢�ӽڵ�id���б�
	unordered_map<int, vector<int>> tree;
	tree[1] = { 2,3 };
	tree[2] = { 4 };
	tree[3] = { 5,6 };

	//����tree
	for (auto node : tree)
	{
		for (int i = 0; i < node.second.size(); i++)
		{
			cout << node.first << "�ĺ��ӽڵ�Ϊ:" << node.second[i] << endl;
		}
	}
}