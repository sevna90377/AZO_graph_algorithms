#pragma once


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
	void loadGraph();
	int loadFromFile(std::string filename, bool directed);
	void generateRandom(int graph_order, int density, bool directed);

	void mst_kruskal();
	void mst_prim();

private:
	int** matrix;
	int graph_order;	//liczba wierzcho³ków


	void allocate(int size);
	void deallocate();
	void addEdge(int v1, int v2, int weight, bool directed);
	std::string pad(std::string string);	//metoda wspomagaj¹ca wyœwietlanie
};

