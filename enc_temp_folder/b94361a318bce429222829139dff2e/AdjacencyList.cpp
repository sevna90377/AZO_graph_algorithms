#include "AdjacencyList.h"

#include<string>

void AdjacencyList::display() {

	std::cout << std::endl << "Graf w reprezentacji listowej: " << std::endl;

	for (int i = 0; i < graph_order; i++) {
		std::cout << i;
		ListNode* holder = adjList[i]->next;
		while (holder != nullptr) {
			std::cout << " -> " << pad(std::to_string(holder->node), 2) << ":" << pad(std::to_string(holder->weight), 3);
			holder = holder->next;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::string AdjacencyList::pad(std::string string, int length) {
	std::string padding = " ";
	std::string result = string;
	int size = length - string.length();
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

void AdjacencyList::allocate(int order)
{
	deallocate();

	graph_order = order;

	adjList = new ListNode*[graph_order];

	for (int i = 0; i < graph_order; i++) {
		adjList[i] = new ListNode;
		adjList[i]->node = i;
		adjList[i]->weight = 0;
		adjList[i]->next = nullptr;
	}
}

void AdjacencyList::deallocate()
{
	ListNode* holder, * next_holder;
	for (int i = 0; i < graph_order; i++) {		//delokacja list kolejnych wierzcho³ków
		holder = adjList[i];
		while (holder->next != nullptr) {
			next_holder = holder->next;
			delete[] holder;
			holder = next_holder;
		}
		delete[] holder;
	}
	delete[] adjList;						//delokacja tablicy

	graph_order = 0;
}

void AdjacencyList::addEdge(int v1, int v2, int value, bool directed) {

	//dla grafu skierowanego
	ListNode* holder = adjList[v1];
	while (holder->next != nullptr) {	//przejœcie do koñca listy danego v1
		holder = holder->next;
	}
	holder->next = new ListNode;	//przypisanie nowego elementu na koñcu
	holder = holder->next;
	holder->node = v2;				//ustawienie wartoœci dla nowego elementu
	holder->weight = value;
	holder->next = nullptr;

	//analogicznie dla grafu nieskierowanego
	if (!directed) {
		holder = adjList[v2];
		while (holder->next != nullptr) {
			holder = holder->next;
		}
		holder->next = new ListNode;	
		holder = holder->next;
		holder->node = v1;		
		holder->weight = value;
		holder->next = nullptr;
	}
}

/*
void AdjacencyList::mst_kruskal() {

	List resultList;

	//utworzenie kolejek priorytetowych zawieraj¹cych krawêdzie grafu
	Edge e;

	Heap priorityHeap;
	ListNode* holder;
	for (int i = 0; i < graph_order; i++) {
		holder = adjList[i];
		while (holder->next != nullptr) {
			holder = holder->next;
			if (holder->node > i) {
				e.v1 = i;
				e.v2 = holder->node;
				e.weight = holder->weight;
				priorityHeap.push(e);
			}
		}
	}

	DisjointSet disjointSet(graph_order);
	while (priorityHeap.heap_length > 0) {
		e = priorityHeap.pop();
		if (!disjointSet.isOneSet(e.v1, e.v2)) {
			resultList.addValue(e);
			disjointSet.unionSets(e.v1, e.v2);
		}
	}

	resultList.display(0);
}
void AdjacencyList::mst_prim() {

	Heap heap;
	Edge edge;
	bool* visited = new bool[graph_order];
	for (int i = 1; i < graph_order; i++) {
		visited[i] = false;
	}
	List resultList;

	ListNode* holder;
	int currentNode = 0;

	visited[currentNode] = true;

	for (int i = 0; i < graph_order - 1; i++) {
		holder = &adjList[currentNode];
		while (holder->next != nullptr) {
			holder = holder->next;
			if (!visited[holder->node]) {
				edge.v1 = currentNode;
				edge.v2 = holder->node;
				edge.weight = holder->weight;
				heap.push(edge);
			}
		}

		do {
			edge = heap.pop();
		} while (visited[edge.v2]);

		resultList.addValue(edge);
		visited[edge.v2] = true;
		currentNode = edge.v2;
	}

	resultList.display(0);
}
*/