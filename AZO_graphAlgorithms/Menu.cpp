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
		std::cout << "2. Wygeneruj losowo\n";
		std::cout << "3. Wyswietl\n";
		std::cout << "\t4. Algorytm Prima X\n";
		std::cout << "\t5. Algorytm Kruskala\n";
		std::cout << "> ";
		opt = _getche();
		std::cout << "\n";

		switch (opt) {
		case '1':
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

