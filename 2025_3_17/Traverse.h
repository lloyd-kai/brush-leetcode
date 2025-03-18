#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;


//ͼ�ĳ����ı����㷨
//ͼ�ڵ�
class Vertex
{
public:
	int id;
	vector<Vertex*> neighbors;
};


//ͼ�ı�����ܣ�
//��Ҫһ��visited�����¼���������Ľڵ㣬�����������������ѭ��
void traverse(Vertex* s, vector<bool>& visited)
{
	//�ݹ�߽�
	if (s == nullptr)
	{
		return;
	}

	if (visited[s->id])
	{
		//����Ѿ�������
		return;
	}
	
	//ǰ��λ��
	visited[s->id] = true;
	cout << "visit " << s->id << endl;
	for (auto neighbor : s->neighbors)
	{
		traverse(neighbor,visited);
	}

	//����λ��

}

//���ͼ�����ڽӱ�������ڽӾ���洢�Ļ�������������д
// ����ͼ�����нڵ�
/* �ǵ�ʹ���Ѿ�ʵ�ֵ�graph��Ϊ��������
void traverse(const Graph& graph, int s, std::vector<bool>& visited) {
	// base case
	if (s < 0 || s >= graph.size()) {
		return;
	}
	if (visited[s]) {
		// ��ֹ��ѭ��
		return;
	}
	// ǰ��λ��
	visited[s] = true;
	std::cout << "visit " << s << std::endl;
	for (const Graph::Edge& e : graph.neighbors(s)) {
		traverse(graph, e.to, visited);
	}
	// ����λ��
}
*/


//����ͼ��˵����һ��������Ǳ������е�·��
//���ʱ�����Ҫ����onPath����
// ������ı�����ܣ�Ѱ�ҴӸ��ڵ㵽Ŀ��ڵ��·��

// ������㷨������Ա���ͼ������·����Ѱ�Ҵ� src �� dest ������·��

// onPath �� path ��¼��ǰ�ݹ�·���ϵĽڵ�
/*
vector<bool> onPath(graph.size());
list<int> path;

void traverse(Graph& graph, int src, int dest) {
	// base case
	if (src < 0 || src >= graph.size()) {
		return;
	}
	if (onPath[src]) {
		// ��ֹ��ѭ�����ɻ���
		return;
	}
	// ǰ��λ��
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
	// ����λ��
	path.pop_back();
	onPath[src] = false;
}
*/


//���������������
//�ܼ�¼����������д��
//�Ͷ�����ı������һ��
void bfs(const Graph& graph, int s)
{
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(s);
	visited[s] = true;

	//��¼��s��ʼ�ߵ���ǰ�ڵ�Ĳ���
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