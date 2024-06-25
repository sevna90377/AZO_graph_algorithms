#pragma once
#include <iostream>
#include <conio.h>
#include "Graph.h"
#include <chrono>

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
	//void menuMFP();

	void testList();
	void testMacierzy();

	void timer_start();
	void timer_stop();

	Graph* graph;

	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;
	double suma;
	std::string resultFileName;
	std::ofstream resultFile;
};

