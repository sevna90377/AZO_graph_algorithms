#include "AdjacencyMatrix.h"
#include <string>
#include <iostream>

void AdjacencyMatrix::display() {
	std::cout << "Graf w reprezentacji macierzowej: \n ";
	for (int i = 0; i < graph_order; i++) {
		std::cout << "  " << pad(std::to_string(i));
	}
	std::cout << "\n";
	for (int i = 0; i < graph_order; i++) {
		std::cout << i;
		for (int j = 0; j < graph_order; j++) {
			std::cout << "  " << pad(std::to_string(matrix[i][j]));
		}
		std::cout << "\n";
	}
}

std::string AdjacencyMatrix::pad(std::string string) {
	std::string padding = " ";
	std::string result = string;
	int size = 2 - string.length();
	if (size < 0)
	{
		return "  ";
	}
	for (int i = 0; i < size; i++)
	{
		result = padding + result;
	}
	return result;
}

void AdjacencyMatrix::allocate(int size) {
	deallocate();		//delokacja ewentualnie obecnej macierzy

	matrix = new int* [size];	//alokacja pamiêci
	graph_order = size;			//przypisanie nowego rozmiaru

	//zape³nienie nowej macierzy
	for (int i = 0; i < graph_order; i++) {
		matrix[i] = new int [graph_order];
		for (int j = 0; j < graph_order; j++) {
			matrix[i][j] = 0;	//0 oznacza brak krawêdzi w grafie
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

void AdjacencyMatrix::generateRandom(int graph_order, int density, bool directed)
{

}
