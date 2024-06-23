#pragma once

#include "Heap.h"
#include "Edge.h"

class List{
public:
	struct ListElement {
		Edge* edge;
		ListElement* next;
		ListElement* previous;
	};

	List() {
		headPointer = nullptr;
		tailPointer = nullptr;
	}
	~List() {
		
	}

	void push(Edge* e);
	Edge* get();
	void deleteAll();
	void display(int option);	// 1 - macierz 2 - lista

private:
	ListElement* headPointer;
	ListElement* tailPointer;
	ListElement* iterator;
};