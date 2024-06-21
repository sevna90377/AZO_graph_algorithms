#pragma once
#include <iostream>
#include <conio.h>
#include "Graph.h"

class Menu
{
public:
	
	Menu() {
		graph = new Graph();
	};
	~Menu() {
		delete graph;
	};

	int main();

private:

	void menuMST();
	void menuSPP();
	void menuMFP();

	Graph* graph;
};

