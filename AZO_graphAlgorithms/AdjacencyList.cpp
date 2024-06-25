#include "AdjacencyList.h"

void AdjacencyList::display() {

	std::cout << std::endl << "Graf w reprezentacji listowej: " << std::endl;

	for (int i = 0; i < graph_order; i++) {
		std::cout << i;
		ListNode* holder = adjList[i]->next;
		while (holder != nullptr) {
			std::cout << " ->" << pad(std::to_string(holder->node), 2) << ":" << pad(std::to_string(holder->weight), 3);
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

List* AdjacencyList::mst_kruskal() {

	List* result = new List();

	//utworzenie kolejki priorytetowej (kruskal, wiêc wszystkich) krawêdzi
	Heap* minEdgeHeap = new Heap();
	Edge* e;

	ListNode* holder;
	for (int i = 0; i < graph_order; i++) {
		holder = adjList[i];
		while (holder->next != nullptr) { 
			holder = holder->next;
			if (holder->node > i) {
				e = new Edge;
				e->v1 = i;
				e->v2 = holder->node;
				e->weight = holder->weight;
				minEdgeHeap->push(e);
			}
		}
	}

	DisjointSets* sets = new DisjointSets(graph_order);
	while (minEdgeHeap->heap_length > 0) {
		e = minEdgeHeap->pop();
		if (!sets->isOneSet(e->v1, e->v2)) {
			result->push(e);
			sets->unionSets(e->v1, e->v2);
		}
	}

	return result;
}

List* AdjacencyList::mst_prim() {

	List* result = new List();

	//tablica pamiêtaj¹ca odwiedzone wierzcho³ki;
	bool* visited = new bool[graph_order];
	for (int i = 0; i < graph_order; i++) {
		visited[i] = false;
	}

	int currentNode = 0;	//wierzcho³ek pocz¹tkowy 0 !

	Heap* minEdgeHeap = new Heap();
	Edge* e = new Edge(0,0,0);
	ListNode* holder;

	do {
		if (!visited[currentNode]) {	//jeœli wierzcho³ek ju¿ by³ odwiedzony zostaje odrzucony
			result->push(e);	//krawêdŸ wybrana w poprzednim przebiegu pêtli zostaje dodana do rozwi¹zania (krawêdzie o wadze 0 s¹ ignorowanê przez metodê List::push)
			holder = adjList[currentNode];
			while (holder->next != nullptr) {	//dodanie wszystkich krawêdzi odwiedzanego wierzcho³ka do kolejki
				holder = holder->next;
				e = new Edge;
				e->v1 = currentNode;
				e->v2 = holder->node;
				e->weight = holder->weight;
				minEdgeHeap->push(e);
			}
			visited[currentNode] = true;
		}

		e = minEdgeHeap->pop();	//wybór krawêdzi incydentnej z ju¿ odwiedzonymi wierzcho³kami o minimalnej wadze
		currentNode = e->v2;

	} while (minEdgeHeap->heap_length > 0);

	return result;
}