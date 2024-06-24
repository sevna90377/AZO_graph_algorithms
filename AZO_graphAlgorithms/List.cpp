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
		//przypisanie wska�nik�w i przeniesienie tailPointer na dodany element
		tailPointer->next = newElement;
		newElement->previous = tailPointer;
		tailPointer = newElement;
	}
}

Edge* List::get() {		//zwraca jeszcze nie zwr�cony element nie usuwaj�c go z listy

	if (iterator = nullptr) {		//przej�cie ca�ej listy powoduje zwr�cenie nullptr
		iterator = headPointer;		//w�wczas iterator zaczyna od nowa
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
		std::cout << "Wynik algorytmu dzialajacego na reprezentacji";
		if (option == 1) {
			std::cout << " macierzowej:\n";
		}
		else {
			std::cout << " listowej:\n";
		}

		ListElement* holder = headPointer;

		do {
			std::cout << " [" << holder->edge->v1 << ";" << holder->edge->v2 << "] " << holder->edge->weight << " ,";
			holder = holder->next;
		} while (holder != nullptr);

		std::cout << std::endl;

		int mst_weight = 0;
		holder = headPointer;
		do {
			mst_weight += holder->edge->weight;
			holder = holder->next;
		} while (holder != nullptr);

		std::cout << "Calkowita waga MST: " << mst_weight << std::endl;
	}
}