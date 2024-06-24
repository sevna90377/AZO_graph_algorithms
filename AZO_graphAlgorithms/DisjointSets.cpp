#include "DisjointSets.h"

void DisjointSets::makeOwnSet(int x)
{
	parent[x] = x;
	rank[x] = 1;
}

int DisjointSets::findSetRoot(int x)
{
	//gdy zbi�r nie pochodzi od tego wiercho�ka
	if (x != parent[x]) {
		//rekurencyjne wyszukanie rodzica
		parent[x] =  findSetRoot(parent[x]);	
		//przypisuje rodzica zbioru wierzcho�kom od x w kolejno�ci odwrotnej do do��czania
		//wierzcho�ki do��czone do x maj� pa rent[] = x, dlatego przy ka�dej operacji nale�y wywo�a� t� funkcj�
	}
	return parent[x];
}

void DisjointSets::unionSets(int x, int y) 
{
	int setX = findSetRoot(x);	//x
	int setY = findSetRoot(y);	//x

	if(setX == setY) {	//elementy nale�� do jednego zbioru
		return;
	}

	if (rank[setX] > rank[setY]) {	//wyb�r wi�kszego zbioru
		parent[setY] = setX;	//przepisanie ca�ego zbioru X do zbioru Y, poprzez zmian� rodzica wierzcho�ka od kt�rego pochodzi zbi�r
		rank[setX]++;
		rank[setY] = 0;
	}
	else {
		parent[setX] = setY;
		rank[setY]++;
		rank[setX] = 0;
	}
}

bool DisjointSets::isOneSet(int x, int y)
{
	return findSetRoot(x) == findSetRoot(y);
}


