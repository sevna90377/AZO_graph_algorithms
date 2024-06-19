#pragma once
#include <iostream>
#include <fstream>

class AdjacencyMatrix
{
public:

	AdjacencyMatrix() {
		graph_order = 0;
		matrix = nullptr;
	};

	~AdjacencyMatrix() {
		deallocate();
	};

	void display();
	int loadFromFile(std::string filename, bool directed);
	void generateRandom(int node_size, int density, bool directed);

	void mst_kruskal();
	void mst_prim();

private:
	int** matrix;
	int graph_order;


	void allocate(int size);
	void deallocate();
	void addEdge(int v1, int v2, int weight, bool directed);
};

