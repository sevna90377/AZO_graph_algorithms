#include "Graph.h"
#include <cmath>

int Graph::add_edge(int pos, int v1, int v2, int weight)
{
	graph[pos]->v1 = v1;
	graph[pos]->v2 = v2;;
	graph[pos]->weight = weight;
}

void Graph::generateRandomGraph(int graph_order, int graph_density)
{
	for (int i = 0; i < order; i++) {
		delete graph[i];
	}
	delete graph;

	int minEdges = order - 1;	//min l. krawêdzi dla grafu spójnego
	int maxEdges = (order - 1) * order / 2;		//l. krawêdzi grafu pe³nego

	order = graph_order;
	size = ceil(maxEdges * graph_density / 100);

	graph = new Edge* [2 * size];	//alokacja

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
		weight = rand() % MAX_WEIGHT;

		add_edge(i - 1, previous, next, weight);
		previous = next;
		visited[next] = 1;
	}

	//dope³nienie grafu do zadanej gêstoœci
	bool already_connected = true;
	for (int i = minEdges; i < order; i++) {
		while (already_connected) {
			already_connected = false;

			previous = rand() % order;
			next = rand() % order;

			for (int j = 0; j < i; j++) {
				if (next == previous) {
					already_connected = true;
					break;
				}
				else if (graph[j]->v1 == previous && graph[j]->v2 == next) {
					already_connected = true;
					break;
				}
				else if (graph[j]->v1 == next && graph[j]->v2 == previous) {
					already_connected = true;
					break;
				}
			}
		}
		weight = rand() % MAX_WEIGHT;
		add_edge(i, previous, next, weight);
	}
}
void Graph::loadFromFile(std::string filename) {
	std::ifstream myFile;
	int v1, v2, weight;

	myFile.open(filename);

	if (myFile.is_open())
	{
		//usuniêcie poprzedniego grafu
		for (int i = 0; i < order; i++) {
			delete graph[i];
		}
		delete graph;

		//pobranie iloœci wartoœci do odczytania z pierwszej linijki pliku
		myFile >> size >> order;	//size - krawêdzie, order - wierzcho³ki

		//alokacja 
		graph = new Edge * [2 * size];

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
	int minEdges = order - 1;	//min l. krawêdzi dla grafu spójnego
	int maxEdges = (order - 1) * order / 2;		//l. krawêdzi grafu pe³nego
	return ceil(minEdges / maxEdges * 100);
}

