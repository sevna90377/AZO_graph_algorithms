#include "Menu.h"


int Menu::main()
{
	char opt;
	do {
		std::cout << "\n=== MENU ===\n";
		std::cout << "1. MST\n";
		std::cout << "2. NAJKROTSZA SCIEZKA\n";
		//std::cout << "3. MAKSYMALNY PRZEPLYW\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':
			menuMST();
			break;

		case '2':
			menuSPP();
			break;

		case '3':

			break;

		case 's':		//w³asny case do przeprowadzania testów
			graph->heaptest();
			break;

		default:

			break;
		}

	} while (opt != '0');
	return 0;
}

void Menu::menuMST()
{
	char opt;
	std::string filename;
	int order, density;
	int min_density;

	do {
		std::cout << "\n=== MST ===\n";
		std::cout << "1. Wczytaj z pliku\n";
		std::cout << "2. Wygeneruj losowo\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "\t4. Algorytm Prima X\n";
		std::cout << "\t5. Algorytm Kruskala\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':	//wczytywanie z pliku

			std::cout << "Nazwa pliku > ";
			std::cin >> filename;
			graph->loadFromFile(filename);
			graph->init(false);
			break;
			
		case '2':	//generowanie losowego

			char directed;
			std::cout << "Liczba wierzcholkow > ";
			std::cin >> order;
			
			min_density = graph->minDensity(order, false);
			std::cout << "\nGestosc (minimalnie " << min_density << ") % > ";
			std::cin >> density;
			if (density >= min_density) {
				graph->generateRandomGraph(order, density, false);
				graph->init(false);
			}
			
			break;

		case '3':
			graph->display();

			break;

		case '4':
			graph->mst_prim();

			break;

		case '5':
			graph->mst_kruskal();

			break;

		default:
			break;
		}

	} while (opt != '0');
}

void Menu::menuSPP()
{
	
	char opt;
	std::string filename;
	int order, density;
	int min_density;

	do {
		std::cout << "\n=== Problem Najkrotszej Drogi ===\n";
		std::cout << "1. Wczytaj z pliku\n";
		std::cout << "2. Wygeneruj losowo X\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "\t4. Algorytm Dijkstry X\n";
		std::cout << "\t5. Algorytm Forda-Bellmana X\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':	//wczytywanie z pliku

			std::cout << "Nazwa pliku > ";
			std::cin >> filename;
			graph->loadFromFile(filename);
			graph->init(true);
			break;

		case '2':	//generowanie losowego

			char directed;
			std::cout << "Liczba wierzcholkow > ";
			std::cin >> order;

			min_density = graph->minDensity(order, true);
			std::cout << "\nGestosc (minimalnie " << min_density << ") % > ";
			std::cin >> density;
			if (density >= min_density) {
				graph->generateRandomGraph(order, density, true);
				graph->init(true);
			}

			break;

		case '3':

			graph->display();

		default:
			break;
		}

	} while (opt != '0');
}
int main(void) {
	Menu* menu = new Menu;
	return menu->main();
}