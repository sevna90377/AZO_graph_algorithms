#include "Menu.h"


int Menu::main()
{
	char opt;
	do {
		std::cout << "\n=== MENU ===\n";
		std::cout << "1. MST\n";
		//std::cout << "2. NAJKROTSZA SCIEZKA\n";
		//std::cout << "3. MAKSYMALNY PRZEPLYW\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':
			menuMST();
			break;

		case '2':

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

	do {
		std::cout << "\n=== MST ===\n";
		std::cout << "1. Wczytaj z pliku\n";
		std::cout << "2. Wygeneruj losowo X\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "\t4. Algorytm Prima X\n";
		std::cout << "\t5. Algorytm Kruskala X\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':	//wczytywanie z pliku
			std::cout << "Nazwa pliku > ";
			std::cin >> graph->filename;
			//graph->loadFromFile(filename, 0);
			//graph->display();
			break;

		case '2':	//generowanie losowego
			int order, density, directed;
			std::cout << "Liczba wierzcholkow > ";
			std::cin >> order;
			std::cout << "Graf skierowany? t/n > ";
			std::cin >> directed;
			bool d = directed == 116 ? true : false;
			int min_density = graph->minDensity(order, directed);
			do {
				std::cout << "Minimalna gestosc " << min_density << "% > ";
				std::cin >> density;
			} while (density < min_density && density != 0);

			graph->generateRandomGraph(order, density, d);
			break;

		default:
			break;
		}

	} while (opt != '0');
}

void Menu::menuSPP()
{
}

void Menu::menuMFP()
{
}




int main(void) {
	Menu* menu = new Menu;
	return menu->main();
}

