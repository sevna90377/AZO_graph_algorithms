#include "Graph.h"
#include <cmath>

#include "List.h"

void Graph::add_edge(int pos, int v1, int v2, int weight)
{
	graph[pos]->v1 = v1;
	graph[pos]->v2 = v2;;
	graph[pos]->weight = weight;
}

void Graph::heaptest()
{
	Heap* heap = new Heap();
	
	Edge* e = new Edge;
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 1;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 5;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 8;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 7;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 2;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 0;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 3;
	heap->push(e);
	e->v1 = 1;
	e->v2 = 3;
	e->weight = 1;
	heap->push(e);

	heap->display();
}

void Graph::display()
{
	list_rep->display();
	matrix_rep->display();
}

void Graph::generateRandomGraph(int graph_order, int graph_density, bool directed)
{
	for (int i = 0; i < size; i++) {
		delete graph[i];
	}
	delete[] graph;

	order = graph_order;

	int minEdges = order - 1;	//min l. krawêdzi dla grafu spójnego

	size = ceil((float)graph_density * order * minEdges / 100);
	if (!directed) {
		size /= 2;
	}
	
	graph = new Edge* [size];	//alokacja
	for (int i = 0; i < size; i++) {
		graph[i] = new Edge;
	}

	//przygotowanie tablicy odwiedzonych wierzcho³ków
	int* visited = new int [order];
	for (int i = 0; i < order; i++) {
		visited[i] = 0;
	}

	//tworzenie losowej listy krawêdzi na wzór pliku
	srand(time(NULL));
	int next, previous, weight;

	//utworzenie MST
	previous = rand() % order;
	visited[previous] = 1;
	for (int i = 1; i < minEdges + 1; i++) {
		do {
			next = rand() % order;
		} while (visited[next] == 1);
		weight = rand() % MAX_WEIGHT + 1;

		add_edge(i - 1, previous, next, weight);
		previous = next;
		visited[next] = 1;
	}

	//dope³nienie grafu do zadanej gêstoœci
	bool already_connected;
	for (int i = minEdges; i < size; i++) {
		already_connected = true;
		while (already_connected) {
			already_connected = false;

			previous = rand() % order;
			next = rand() % order;

			if (next == previous) {
				already_connected = true;
				break;
			}

			for (int j = 0; j < i; j++) {
				if (graph[j]->v1 == previous && graph[j]->v2 == next) {
					already_connected = true;
					break;
				}
				else if (!directed && graph[j]->v1 == next && graph[j]->v2 == previous) {
					already_connected = true;
					break;
				}
			}
		}
		weight = rand() % MAX_WEIGHT + 1;
		add_edge(i, previous, next, weight);
	}
}

void Graph::init(bool directed)
{
	list_rep->allocate(order);
	matrix_rep->allocate(size, order);
	for (int i = 0; i < size; i++) {
		list_rep->addEdge(graph[i]->v1, graph[i]->v2, graph[i]->weight, directed);
		matrix_rep->addEdge(graph[i]->v1, graph[i]->v2, graph[i]->weight, directed);
	}
}

void Graph::loadFromFile(std::string filename) {
	std::ifstream myFile;
	int v1, v2, weight;

	myFile.open(filename);

	if (myFile.is_open())
	{
		//usuniêcie poprzedniego grafu
		for (int i = 0; i < size; i++) {
			delete graph[i];
		}
		delete graph;

		//pobranie iloœci wartoœci do odczytania z pierwszej linijki pliku
		myFile >> size >> order;	//size - krawêdzie, order - wierzcho³ki

		//alokacja 
		graph = new Edge * [size];
		for (int i = 0; i < size; i++) {
			graph[i] = new Edge;
		}

		//wczytywanie krawêdzi
		for (int i = 0; i < size; i++) {
			myFile >> v1 >> v2 >> weight;
			add_edge(i, v1, v2, weight);
		}

		myFile.close();
	}
}

int Graph::minDensity(int graph_order, bool directed)
{	
	if (directed) {
		return ceil((float)1 / graph_order * 100);
	}
	else {
		return ceil((float)2 / graph_order * 100);
	}
}

void Graph::mst_kruskal()
{
	matrix_rep->mst_kruskal();
	list_rep->mst_kruskal();
}

