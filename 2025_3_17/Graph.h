#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

//ͼ�����ݽṹ
//��ʵ�����������죬�������ж�������ڵ㡱
class Vertex
{
public:
	int id;
	std::vector<Vertex*> neighbors;
};


//��Ȩ����ͼ��ʵ��-ͨ���ڽӱ�
class WeightedDigraph1
{
public:
	//�洢���ڽڵ�ͱߵ�Ȩ��
	struct Edge
	{
		int to;//�����to���ڽӱ����ǽڵ��id����ά�������������ͬ�Ľڵ㣬Ԫ�������ڽӱ�ڵ������
		int weight;

		Edge(int to, int weight)
		{
			this->to = to;
			this->weight = weight;
		}
	};

private:
	//�ڽӱ� ����graph[v]�洢�ڵ�v�������ھӽڵ㼰��ӦȨ��
	vector<vector<Edge>> graph;

public:
	WeightedDigraph1(int n)
	{
		//�����������ͼ���ʱ��Ҫ����ڵ����
		graph = vector<vector<Edge>>(n);
	}

	//����Ԫ�أ����һ����Ȩ�ص�����ߣ����Ӷ�O(1)
	//from��Դ�ڵ㣬to��Ŀ��ڵ㣬��fromָ��to
	void addEdge(int from, int to, int weight)
	{
		graph[from].emplace_back(to, weight);
	}

	//ɾ��Ԫ�أ�ɾ��һ����Ȩ�ص�����ߣ����Ӷ�O(V)
	void removeEdge(int from, int to)
	{
		for (auto it = graph[from].begin(); it != graph[from].end(); it++)
		{
			//�����ýڵ���ڽڵ㣬����ҵ���ɾ��
			if (it->to == to)
			{
				graph[from].erase(it);
				break;
			}
		}
	}

	//����Ԫ�أ��ж������ڵ��Ƿ���ȣ����Ӷ�O(v)
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

	//���ң�����һ���ߵ�Ȩ�أ����Ӷ�O(V)
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

	//�飬����ĳ���ڵ�������ڽӽڵ�
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


//��Ȩ����ͼ��ʵ��-ͨ���ڽӾ���
class WeightedDigraph2
{
public:
	//�洢���ڽڵ㼰�ߵ�Ȩ��
	struct Edge
	{
		int to;
		int weight;

		Edge(int to, int weight) :to(to), weight(weight) {};
	};

	WeightedDigraph2(int n)
	{
		//�ȳ�ʼ����Ϊ0��Ҳ�е�ʵ���ǽ����ʼ��Ϊ�������
		matrix = vector<vector<int>>(n, vector<int>(n, 0));
	}

	//�������һ����Ȩ�ص�����ߣ�ʱ�临�Ӷ�O(1)
	void addEdge(int from, int to, int weight)
	{
		matrix[from][to] = weight;
	}


	//ɾ��ɾ��һ����Ȩ�ص�����ߣ�ʱ�临�Ӷ�O(1)
	void removeEdge(int from, int to)
	{
		matrix[from][to] = 0;//
	}

	//���ң��ж������ڵ��Ƿ����ڣ����Ӷ�ΪO(1)
	bool hasEdge(int from, int to)
	{
		return matrix[from][to]!=0;
	}

	//���ң�����һ���ߵ�Ȩ�أ����Ӷ�O(1)
	int weight(int from, int to)
	{
		return matrix[from][to];
	}

	//���ң����ؽڵ�������ڽӽ��
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
	//�ڽӾ���matrix[from][to] �洢��from���ڵ�to��Ⱥ��
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

//������Ȩͼ
//��ʵ����˫�������ͼ�������һ���ߵ�ʱ��ͬʱ������Ҳ���һ����
class WeightedUndigraph
{
private:
	WeightedDigraph1 graph;//ֱ�Ӹ���ǰ��ʵ�ֵĴ�Ȩ����ͼ
public:
	WeightedUndigraph(int n) :graph(n) {};

	//ֱ�ӽ�����API
	//���ӣ� ���һ����Ȩ�ص������
	void addEdge(int from, int to, int weight)
	{
		graph.addEdge(from, to, weight);
		graph.addEdge(to, from, weight);
	}

	//ɾ����ɾ��һ����Ȩ�ص������
	void removeEdge(int from, int to)
	{
		graph.removeEdge(from, to);
		graph.removeEdge(to, from);
	}

	//���ң��ж������ڵ��Ƿ�����
	bool hasEdge(int from, int to)
	{
		return graph.hasEdge(from, to);
	}

	// �飬����һ���ߵ�Ȩ��
	int weight(int from, int to) {
		return graph.weight(from, to);
	}

	
	// �飬����ĳ���ڵ�������ھӽڵ�
	/*
	const vector<WeightedDigraph1::Edge>& neighbors(int v) const {
		return graph.neighbors(v);
	}
	*/
};


//��������