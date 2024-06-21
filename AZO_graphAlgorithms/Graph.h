#pragma once
#include "AdjacencyMatrix.h"
#include <iostream>
#include <fstream>

class Graph
{
public:
	struct Edge {
		int v1, v2, weight;
	};

	const int MAX_WEIGHT = 99;

	std::string filename;
	void generateRandomGraph(int graph_order, int graph_density);
	void loadFromFile(std::string filename);
	int minDensity(int graph_order, bool directed);

private:

	int size;
	int order;

	Edge** graph;

	int add_edge(int pos, int v1, int v2, int weight);

	AdjacencyMatrix* am;


};

