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


//N叉树的遍历
//就是二叉树的延伸，遍历每一个节点的孩子节点即可
void traverseForest(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    //开始遍历
    //对于N叉树来说，前中后序失去了意义，而层序遍历还有点用
    for (Node* child : root->children)
    {
        traverseForest(child);
    }
}

//N叉树的层序遍历
//方法1 借助队列
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
        //访问cur节点
        std::cout << cur->val << std::endl;

        //把cur所有子节点加入队列
        for (Node* child : cur->children)
        {
            q.push(child);
        }
    }
}


//方法2 记录节点深度
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

            //访问cur节点，同时知道他所在的层数
            cout << "depth = " << depth << ", val = " << cur->val << endl;

            for (Node* child : cur->children)
            {
                q.push(child);
            }
        }
    }
}


//方法3 记录权重
//带权重的树节点
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

        //访问节点
        cout << "depth = " << depth << ", val = " << cur->val << endl;

        //进入子节点，注意深度+1
        for (Node* child : cur->children)
        {
            q.push(State(child,depth+1));
        }
    }
}