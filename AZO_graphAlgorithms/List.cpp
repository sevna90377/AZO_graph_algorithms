#include "List.h"

void List::push(Edge* e){

	ListElement* newElement = new ListElement;
		newElement->edge = e;
		newElement->next = nullptr;

	if (headPointer == nullptr) {	//gdy lista jest pusta
		headPointer = newElement;
		headPointer->previous = nullptr;
		tailPointer = headPointer;
	}
	else {
		//przypisanie wskaŸników i przeniesienie tailPointer na dodany element
		tailPointer->next = newElement;
		newElement->previous = tailPointer;
		tailPointer = newElement;
	}
}

Edge* List::get() {		//zwraca jeszcze nie zwrócony element nie usuwaj¹c go z listy

	if (iterator = nullptr) {		//przejœcie ca³ej listy powoduje zwrócenie nullptr
		iterator = headPointer;		//wówczas iterator zaczyna od nowa
	}
	else {
		iterator = iterator->next;
	}
	return iterator->edge;
}

void List::deleteAll() {

	if (headPointer != nullptr) {

		ListElement* holder;

		while(headPointer->next != nullptr) {
			holder = headPointer->next;
			delete headPointer;
			headPointer = holder;
		}
		delete headPointer;
	}
}

void List::display(int option) {

	if (headPointer != nullptr) {
		std::cout << "Drzewo rozpinajace bedace wynikiem algorytmu dzia³aj¹cego na reprezentacji";
		if (option == 1) {
			std::cout << " macierzowej:\n";
		}
		else {
			std::cout << " listowej:\n";
		}

		ListElement* holder = headPointer;

		while (holder->next != nullptr) {
			std::cout << " [" << holder->edge->v1 << ";" << holder->edge->v2 << "] " << holder->edge->weight << " ,";
			holder = holder->next;
		}

		std::cout << std::endl;

		int mst_weight = 0;
		holder = headPointer;
		while (holder->next != nullptr) {
			mst_weight += holder->edge->weight;
			holder = holder->next;
		}

		std::cout << "Calkowita waga MST: " << mst_weight << std::endl;
	}
}