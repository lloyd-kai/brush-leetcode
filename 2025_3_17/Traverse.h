#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;


//图的常见的遍历算法
//图节点
class Vertex
{
public:
	int id;
	vector<Vertex*> neighbors;
};


//图的遍历框架，
//需要一个visited数组记录被遍历过的节点，避免后续遍历陷入死循环
void traverse(Vertex* s, vector<bool>& visited)
{
	//递归边界
	if (s == nullptr)
	{
		return;
	}

	if (visited[s->id])
	{
		//如果已经遍历过
		return;
	}
	
	//前序位置
	visited[s->id] = true;
	cout << "visit " << s->id << endl;
	for (auto neighbor : s->neighbors)
	{
		traverse(neighbor,visited);
	}

	//后序位置

}

//如果图是用邻接表或者是邻接矩阵存储的话，还可以这样写
// 遍历图的所有节点
/* 记得使用已经实现的graph作为参数类型
void traverse(const Graph& graph, int s, std::vector<bool>& visited) {
	// base case
	if (s < 0 || s >= graph.size()) {
		return;
	}
	if (visited[s]) {
		// 防止死循环
		return;
	}
	// 前序位置
	visited[s] = true;
	std::cout << "visit " << s << std::endl;
	for (const Graph::Edge& e : graph.neighbors(s)) {
		traverse(graph, e.to, visited);
	}
	// 后序位置
}
*/


//对于图来说还有一种需求就是遍历所有的路径
//这个时候就需要借助onPath数组
// 多叉树的遍历框架，寻找从根节点到目标节点的路径

// 下面的算法代码可以遍历图的所有路径，寻找从 src 到 dest 的所有路径

// onPath 和 path 记录当前递归路径上的节点
/*
vector<bool> onPath(graph.size());
list<int> path;

void traverse(Graph& graph, int src, int dest) {
	// base case
	if (src < 0 || src >= graph.size()) {
		return;
	}
	if (onPath[src]) {
		// 防止死循环（成环）
		return;
	}
	// 前序位置
	onPath[src] = true;
	path.push_back(src);
	if (src == dest) {
		cout << "find path: ";
		for (int node : path) {
			cout << node << " ";
		}
		cout << endl;
	}
	for (const Edge& e : graph.neighbors(src)) {
		traverse(graph, e.to, dest);
	}
	// 后序位置
	path.pop_back();
	onPath[src] = false;
}
*/


//广度优先搜索遍历
//能记录遍历步数的写法
//和多叉树的遍历如出一辙
void bfs(const Graph& graph, int s)
{
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(s);
	visited[s] = true;

	//记录从s开始走到当前节点的步数
	int step = 0;
	while (!q.empty())
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			int cur = q.front();
			q.pop();
			cout << "visit " << cur << " at step" << step << endl;
			for (const Edge& e : graph.neighbors)
			{
				if (!visited[e.to])
				{
					q.push(e.to);
					visited[e.to] = true;
				}
			}
		}
	}
}