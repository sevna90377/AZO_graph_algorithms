#pragma once

#include <iostream>
#include "Edge.h"

struct Edge;

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
	void push(Edge e);
	Edge pop();

private:
	Edge* rootPointer;

	int heap_length;

	void heapifyUp(int i);
	void heapifyDown(int i);
	void display(std::string sp, std::string sn, int from);
};