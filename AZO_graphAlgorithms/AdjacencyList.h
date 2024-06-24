#pragma once

#include <iostream>
#include "Heap.h"
#include "List.h"
#include "DisjointSets.h"

class AdjacencyList
{
public:
	struct ListNode {
		int node;
		int weight;
		ListNode* next;
	};

	AdjacencyList() {
		graph_order = 0;
		adjList = nullptr;
	};

	~AdjacencyList() {
		deallocate();
	};

	void display();
	void allocate(int order);
	void addEdge(int v1, int v2, int weight, bool directed);

	void mst_kruskal();
	void mst_prim();

private:
	int graph_order;
	ListNode** adjList;

	void deallocate();

	std::string pad(std::string string, int length);
};

