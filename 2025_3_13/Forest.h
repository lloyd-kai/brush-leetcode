#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
};


//N�����ı���
//���Ƕ����������죬����ÿһ���ڵ�ĺ��ӽڵ㼴��
void traverseForest(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    //��ʼ����
    //����N������˵��ǰ�к���ʧȥ�����壬������������е���
    for (Node* child : root->children)
    {
        traverseForest(child);
    }
}

//N�����Ĳ������
//����1 ��������
void levelOrderTraverse1(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        //����cur�ڵ�
        std::cout << cur->val << std::endl;

        //��cur�����ӽڵ�������
        for (Node* child : cur->children)
        {
            q.push(child);
        }
    }
}


//����2 ��¼�ڵ����
void levelOrderTraverse(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    int depth = 1;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node* cur = q.front();
            q.pop();

            //����cur�ڵ㣬ͬʱ֪�������ڵĲ���
            cout << "depth = " << depth << ", val = " << cur->val << endl;

            for (Node* child : cur->children)
            {
                q.push(child);
            }
        }
    }
}


//����3 ��¼Ȩ��
//��Ȩ�ص����ڵ�
class State
{
public:
    Node* node;
    int depth;

    State(Node* node, int dept) :node(node), depth(depth) {};
};


void levelOrderTraverse3(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<State>q;
    q.push(State(root,1));

    while (!q.empty())
    {
        State state = q.front();
        q.pop();

        Node* cur = state.node;
        int depth = state.depth;

        //���ʽڵ�
        cout << "depth = " << depth << ", val = " << cur->val << endl;

        //�����ӽڵ㣬ע�����+1
        for (Node* child : cur->children)
        {
            q.push(State(child,depth+1));
        }
    }
}