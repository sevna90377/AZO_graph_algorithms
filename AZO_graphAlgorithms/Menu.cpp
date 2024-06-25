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
		std::cout << "\t4. Algorytm Prima\n";
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
	int vp = 0;
	int vk = 1;

	do {
		std::cout << "\n=== Problem Najkrotszej Drogi ===\n";
		std::cout << "1. Wczytaj z pliku\n";
		std::cout << "2. Wygeneruj losowo\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "\t4. Algorytm Dijkstry\n";
		std::cout << "\t5. Algorytm Forda-Bellmana\n";
		std::cout << "\t6. Wybor wierzcholka poczatkowego i koncowego\n";
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

			break;

		case '4':

			graph->spp_dijkstra(vp, vk);

			break;

		case '6':
			std::cout << "\nWierzcholek poczatkowy: > ";
			std::cin >> vp;
			std::cout << "\nWierzcholek koncowy: > ";
			std::cin >> vk;

			break;

		default:

			break;
		}

	} while (opt != '0');
}
int main(void) {
	Menu* menu = new Menu;
	return menu->main();
}