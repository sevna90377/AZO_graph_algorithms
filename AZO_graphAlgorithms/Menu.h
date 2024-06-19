#pragma once
#include <iostream>
#include <conio.h>
#include "AdjacencyMatrix.h"

class Menu
{
public:
	
	Menu() {};
	~Menu() {};

	int main();

private:

	void menuMST();
	void menuSPP();
	void menuMFP();

	AdjacencyMatrix am;


	int BIG_WEIGHT = 100;
};

