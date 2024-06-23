#pragma once

#include <iostream>
#include "Edge.h"

class Heap{
public:

	Heap() {
		heap_length = 0;
		rootPointer = nullptr;
	};
	~Heap() {
		delete[] rootPointer;
	};

	void display();
	void push(Edge* e);
	Edge* pop();

	int heap_length;

private:
	Edge** rootPointer;

	void heapifyUp(int i);
	void heapifyDown(int i);
	void display(std::string sp, std::string sn, int from);
};