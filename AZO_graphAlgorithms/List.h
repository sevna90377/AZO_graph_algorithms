#pragma once

#include "DataStructure.h"
#include "Heap.h"

class List : DataStructure{

private:
	struct ListElement {
		Edge edge;
		ListElement* next;
		ListElement* previous;
	};

public:

	List() {
		List::headPointer = nullptr;
		List::tailPointer = nullptr;
		List::length = 0;
	}
	~List() {
		ListElement* holder;
		
		for (int i = 0; i < length; i++) {
			holder = headPointer->next;
			delete headPointer;
			headPointer = holder;
		}
	}

private:

	ListElement* headPointer;
	ListElement* tailPointer;

};