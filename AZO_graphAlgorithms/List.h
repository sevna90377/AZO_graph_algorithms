#pragma once

#include "Heap.h"

class List{
public:
	struct ListElement {
		Edge edge;
		ListElement* next;
		ListElement* previous;
	};

	List() {
		headPointer = nullptr;
		tailPointer = nullptr;
		length = 0;
	}
	~List() {
		ListElement* holder;
		
		for (int i = 0; i < length; i++) {
			holder = headPointer->next;
			delete headPointer;
			headPointer = holder;
		}
	}

	void push(Edge e);

private:
	ListElement* headPointer;
	ListElement* tailPointer;
	int length;
};