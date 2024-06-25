#pragma once
#include "IncidencyMatrix.h"
#include "AdjacencyList.h"
#include "Heap.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include "Edge.h"

class Graph
{
public:

	void heaptest();

	Graph() {
		matrix_rep = new IncidencyMatrix();
		list_rep = new AdjacencyList();
		graph = nullptr;
		size = 0;
		order = 0;
	};
	~Graph() {
		delete matrix_rep;
		delete list_rep;

		for (int i = 0; i < order; i++) {
			delete graph[i];
		}
		delete graph;
	};

	const int MAX_WEIGHT = 99;

	void display();
	
	void generateRandomGraph(int graph_order, int graph_density, bool directed);
	void loadFromFile(std::string filename);
	void init(bool directed);
	int minDensity(int graph_order, bool directed);

	void mst_kruskal();
	void mst_prim();

private:

	int size;
	int order;

	Edge** graph;

	void add_edge(int pos, int v1, int v2, int weight);

	IncidencyMatrix* matrix_rep;
	AdjacencyList* list_rep;
};

