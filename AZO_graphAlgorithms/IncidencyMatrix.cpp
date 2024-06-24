#include "IncidencyMatrix.h"

#include "DisjointSets.h"
#include <string>

void IncidencyMatrix::display()
{
	std::cout << "Graf w reprezentacji macierzowej: \n";
	for (int i = 0; i < graph_order; i++) {
		std::cout << i;
		for (int j = 0; j < graph_size; j++) {
			std::cout << "  " << pad(std::to_string(incMatrix[i][j]));
		}
		std::cout << "\n";
	}
}
std::string IncidencyMatrix::pad(std::string string) {
	std::string padding = " ";
	std::string result = string;
	int size = 3 - string.length();
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

void IncidencyMatrix::allocate(int size, int order)
{
	deallocate();

	graph_size = size;
	graph_order = order;

	incMatrix = new int* [graph_order];
	for (int i = 0; i < graph_order; i++) {
		incMatrix[i] = new int[graph_size];
		for (int j = 0; j < graph_size; j++) {
			incMatrix[i][j] = 0;
		}
	}
}
void IncidencyMatrix::deallocate()
{
	for (int i = 0; i < graph_order; i++) {
		delete[] incMatrix[i];
	}
	delete[] incMatrix;
	
	graph_size = 0;
	graph_order = 0;
	last_edge = 0;
}

void IncidencyMatrix::addEdge(int v1, int v2, int weight, int directed)
{
	incMatrix[v1][last_edge] = weight;
	incMatrix[v2][last_edge++] = directed ? -weight : weight;
}

void IncidencyMatrix::mst_kruskal()
{
	List* result = new List();

	//utworzenie kolejki priorytetowej kraw�dzi
	Heap* minEdgeHeap = new Heap();
	Edge* e;
	bool first_added;	//flaga oznaczaj�ca, czy ju� zosta� dodany pierwszy wierzcho�ek
	for (int i = 0; i < graph_size; i++) {
		e = new Edge;
		first_added = false;
		for (int j = 0; j < graph_order; j++) {
			//je�li w danej kom�rce nie ma '0' to dodaj wierzcho�ek
			if (e->weight = incMatrix[j][i]) {
				if (first_added) {
					e->v2 = j;
					break;		//je�li zosta�y dodane oba wierzcho�ki mo�na przej�� do kolejnej kraw�dzi
				}
				e->v1 = j;
				first_added = true;
			}
		}
		minEdgeHeap->push(e);
	}
	minEdgeHeap->display();

	//zbi�r roz��czny do "kolorowania" odwiedzonych wierzcho�k�w
	DisjointSets* sets = new DisjointSets(graph_order);


	while (minEdgeHeap->heap_length > 0) {
		e = minEdgeHeap->pop();
		if (!sets->isOneSet(e->v1, e->v2)) {
			result->push(e);
			sets->unionSets(e->v1, e->v2);
		}
	}

	result->display(1);
}

