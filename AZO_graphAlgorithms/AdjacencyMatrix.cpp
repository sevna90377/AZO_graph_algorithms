#include "AdjacencyMatrix.h"

void AdjacencyMatrix::display() {
	std::cout << "Graf w reprezentacji macierzowej: \n ";
	for (int i = 0; i < graph_order; i++) {
		std::cout << " " << i;
	}
	std::cout << "\n";
	for (int i = 0; i < graph_order; i++) {
		std::cout << i;
		for (int j = 0; j < graph_order; j++) {
			std::cout << " " << matrix[i][j];
		}
		std::cout << "\n";
	}
}

void AdjacencyMatrix::allocate(int size) {
	deallocate();		//delokacja ewentualnie obecnej macierzy

	matrix = new int* [size];
	graph_order = size;

	for (int i = 0; i < graph_order; i++) {
		matrix[i] = new int[graph_order];
		for (int j = 0; j < graph_order; j++) {
			matrix[i][j] = 0;	//zero oznacza brak krawêdzi w grafie
		}
	}
}

void AdjacencyMatrix::deallocate() {
	while (graph_order > 0) {
		delete[] matrix[graph_order - 1];	//delokacja kolejnych wierszy
		graph_order--;
	}
	delete[] matrix;						//delokacja tablicy
}

void AdjacencyMatrix::addEdge(int v1, int v2, int weight, bool directed) {
	matrix[v1][v2] = weight;
	if (!directed) matrix[v2][v1] = weight;	//w grafie nieskierowanym dodawana jest ta sama krawêdŸ w "drug¹ stronê"
}

int AdjacencyMatrix::loadFromFile(std::string filename, bool directed) {
	std::ifstream myFile;
	int graph_size, graph_order;
	int v1, v2, weight;

	myFile.open(filename);

	if (myFile.is_open())
	{
		//usuniêcie poprzedniego grafu
		deallocate();

		//pobranie iloœci wartoœci do odczytania z pierwszej linijki pliku
		myFile >> graph_size >> graph_order;

		//alokacja macierzy s¹siedztwa
		allocate(graph_order);

		for (int i = 0; i < graph_size; i++) {
			myFile >> v1 >> v2 >> weight;
			addEdge(v1, v2, weight, directed);
		}

		myFile.close();

		return 0;
	}
	else {
		return 1;
	}
}