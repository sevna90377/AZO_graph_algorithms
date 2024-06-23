#pragma once

#include "Heap.h"
#include "List.h"

class IncidencyMatrix
{
public:
	IncidencyMatrix() {
		graph_order = 0;
		incMatrix = nullptr;
	};

	~IncidencyMatrix() {
		deallocate();
	};

	void display();
	void allocate(int size, int order);
	void addEdge(int v1, int v2, int weight, int directed);

	void mst_kruskal();
	void mst_prim();

private:
	int graph_order;
	int graph_size;

	int** incMatrix;

	int last_edge;

	void deallocate();

	std::string pad(std::string string);
};

