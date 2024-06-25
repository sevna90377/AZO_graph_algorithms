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

		case 't':		//w³asny case do przeprowadzania testów
			testList();
			testMacierzy();
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
		//std::cout << "\t5. Algorytm Forda-Bellmana\n";
		std::cout << "6. Wybor wierzcholka poczatkowego i koncowego\n";
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

void Menu::testList()
{
	resultFileName = "Listy.csv";
	resultFile.open(resultFileName);

	resultFile << ";;;kruskal;prim;dijkstra\n";
	int s = 100;
	for (int n = 8; n < 16; n *= 2) {
		if (n == 128) {
			s = 10;
		}
		std::cout << n << std::endl;

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->list_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "lista; " << n << "; 25; " << (double)suma / s << "; ";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->list_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->list_rep->spp_dijkstra(0, n-1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->list_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "lista; " << n << "; 50;" << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->list_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->list_rep->spp_dijkstra(0, n - 1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->list_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "lista; " << n << "; 99;" << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->list_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->list_rep->spp_dijkstra(0, n - 1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";
	}



	
	resultFile.close();
}

void Menu::testMacierzy()
{
	resultFileName = "Macierze.csv";
	resultFile.open(resultFileName);

	resultFile << ";;;kruskal;prim;dijkstra\n";
	int s = 100;
	for (int n = 8; n < 20; n *= 2) {
		if (n == 128) {
			s = 10;
		}
		std::cout << n << std::endl;

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->matrix_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "macierz; " << n << "; 25; " << (double)suma / s << "; ";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->matrix_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 25, false);
			timer_start();
			graph->matrix_rep->spp_dijkstra(0, n - 1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->matrix_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "macierz; " << n << "; 50;" << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->matrix_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 50, false);
			timer_start();
			graph->matrix_rep->spp_dijkstra(0, n - 1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->matrix_rep->mst_kruskal();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << "macierz; " << n << "; 99;" << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->matrix_rep->mst_prim();
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << ";";

		suma = 0;
		for (int i = 0; i < s; i++) {
			graph->generateRandomGraph(n, 99, false);
			timer_start();
			graph->matrix_rep->spp_dijkstra(0, n - 1);
			timer_stop();
			suma += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		}
		resultFile << (double)suma / s << "\n";
	}




	resultFile.close();
}

void Menu::timer_start()
{
	start_time = std::chrono::high_resolution_clock::now();
}
void Menu::timer_stop()
{
	end_time = std::chrono::high_resolution_clock::now();
}