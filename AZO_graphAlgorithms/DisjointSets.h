#pragma once
class DisjointSets
{
public:
	DisjointSets(int n) {
		set_size = n;
		parent = new int[set_size];
		rank = new int[set_size];

		for (int i = 0; i < set_size; i++) {
			makeOwnSet(i);
		}
	};

	~DisjointSets() {
		delete[] parent;
		delete[] rank;
	};

	bool isOneSet(int x, int y);
	void unionSets(int x, int y);

private:
	//zbiory rozpoznawane s� przez wierzcho�ek, od kt�rego si� zacz�� dany zbi�r (root)
	int* parent;	//zbi�r do kt�rego nale�y wierzcho�ek
	int* rank;		//wielko�� zbioru w kt�rym si� znajduje wierzcho�ek
	int set_size;

	void makeOwnSet(int x);
	int findSetRoot(int x);
};

