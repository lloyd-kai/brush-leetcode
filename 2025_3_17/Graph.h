#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

//图的数据结构
//其实就是树的延伸，允许其有多个“父节点”
class Vertex
{
public:
	int id;
	std::vector<Vertex*> neighbors;
};


//加权有向图的实现-通过邻接表
class WeightedDigraph1
{
public:
	//存储相邻节点和边的权重
	struct Edge
	{
		int to;//这里的to在邻接表中是节点的id，二维数组的索引代表不同的节点，元素是其邻接表节点的数组
		int weight;

		Edge(int to, int weight)
		{
			this->to = to;
			this->weight = weight;
		}
	};

private:
	//邻接表 其中graph[v]存储节点v的所有邻居节点及对应权重
	vector<vector<Edge>> graph;

public:
	WeightedDigraph1(int n)
	{
		//简单起见，建立图像的时候要传入节点个数
		graph = vector<vector<Edge>>(n);
	}

	//增加元素，添加一条带权重的有向边，复杂度O(1)
	//from是源节点，to是目标节点，由from指向to
	void addEdge(int from, int to, int weight)
	{
		graph[from].emplace_back(to, weight);
	}

	//删除元素，删除一条带权重的有向边，复杂度O(V)
	void removeEdge(int from, int to)
	{
		for (auto it = graph[from].begin(); it != graph[from].end(); it++)
		{
			//遍历该节点的邻节点，如果找到就删除
			if (it->to == to)
			{
				graph[from].erase(it);
				break;
			}
		}
	}

	//查找元素，判断两个节点是否相等，复杂度O(v)
	bool hasEdge(int from, int to)
	{
		for (const auto& e : graph[from])
		{
			if (e.to == to)
			{
				return true;
			}
		}
		return false;
	}

	//查找，返回一条边的权重，复杂度O(V)
	int weight(int from, int to)
	{
		for (const auto& e : graph[from])
		{
			if (e.to == to)
			{
				return e.weight;
			}
		}
		throw std::invalid_argument("No such edge");
	}

	//查，返回某个节点的所有邻接节点
	const vector<Edge>& neighbors(int v)
	{
		return graph[v];
	}
};


void Test_WeightedDigraph1(void)
{
	WeightedDigraph1 graph(3);
	graph.addEdge(0, 1, 1);
	graph.addEdge(1, 2, 2);
	graph.addEdge(2, 0, 3);
	graph.addEdge(2, 1, 4);

	cout << boolalpha << graph.hasEdge(0, 1) << endl; // true
	cout << boolalpha << graph.hasEdge(1, 0) << endl; // false

	for (const auto& edge : graph.neighbors(2)) {
		cout << "2 -> " << edge.to << ", wight: " << edge.weight << endl;
	}
	// 2 -> 0, wight: 3
	// 2 -> 1, wight: 4

	graph.removeEdge(0, 1);
	cout << boolalpha << graph.hasEdge(0, 1) << endl; // false

}


//加权有向图的实现-通过邻接矩阵
class WeightedDigraph2
{
public:
	//存储相邻节点及边的权重
	struct Edge
	{
		int to;
		int weight;

		Edge(int to, int weight) :to(to), weight(weight) {};
	};

	WeightedDigraph2(int n)
	{
		//先初始化均为0，也有的实现是将其初始化为无穷大数
		matrix = vector<vector<int>>(n, vector<int>(n, 0));
	}

	//增，添加一条带权重的有向边，时间复杂度O(1)
	void addEdge(int from, int to, int weight)
	{
		matrix[from][to] = weight;
	}


	//删，删除一条带权重的有向边，时间复杂度O(1)
	void removeEdge(int from, int to)
	{
		matrix[from][to] = 0;//
	}

	//查找，判断两个节点是否相邻，复杂度为O(1)
	bool hasEdge(int from, int to)
	{
		return matrix[from][to]!=0;
	}

	//查找，返回一条边的权重，复杂度O(1)
	int weight(int from, int to)
	{
		return matrix[from][to];
	}

	//查找，返回节点的所有邻接结点
	vector<Edge> neighbors(int v)
	{
		vector<Edge>res;
		for (int i = 0; i < matrix[v].size(); i++)
		{
			if (matrix[v][i] > 0)
			{
				res.push_back(Edge(i, matrix[v][i]));
			}
		}
		return res;
	}

private:
	//邻接矩阵，matrix[from][to] 存储从from到节点to的群众
	vector<vector<int>> matrix;
};

void Test_WeightedDigraph2(void)
{
	WeightedDigraph2 graph(3);
	graph.addEdge(0, 1, 1);
	graph.addEdge(1, 2, 2);
	graph.addEdge(2, 0, 3);
	graph.addEdge(2, 1, 4);

	std::cout << std::boolalpha;
	std::cout << graph.hasEdge(0, 1) << std::endl; // true
	std::cout << graph.hasEdge(1, 0) << std::endl; // false

	for (const auto& edge : graph.neighbors(2)) {
		std::cout << "2 -> " << edge.to << ", weight: " << edge.weight << std::endl;
	}
	// 2 -> 0, weight: 3
	// 2 -> 1, weight: 4

	graph.removeEdge(0, 1);
	std::cout << graph.hasEdge(0, 1) << std::endl; // false

}

//无向无权图
//其实就是双向的有向图，在添加一条边的时候同时反方向也添加一条边
class WeightedUndigraph
{
private:
	WeightedDigraph1 graph;//直接复用前面实现的带权有向图
public:
	WeightedUndigraph(int n) :graph(n) {};

	//直接借用其API
	//增加， 添加一条带权重的无向边
	void addEdge(int from, int to, int weight)
	{
		graph.addEdge(from, to, weight);
		graph.addEdge(to, from, weight);
	}

	//删除，删除一条带权重的无向边
	void removeEdge(int from, int to)
	{
		graph.removeEdge(from, to);
		graph.removeEdge(to, from);
	}

	//查找，判断两个节点是否相邻
	bool hasEdge(int from, int to)
	{
		return graph.hasEdge(from, to);
	}

	// 查，返回一条边的权重
	int weight(int from, int to) {
		return graph.weight(from, to);
	}

	
	// 查，返回某个节点的所有邻居节点
	/*
	const vector<WeightedDigraph1::Edge>& neighbors(int v) const {
		return graph.neighbors(v);
	}
	*/
};


//测试用例