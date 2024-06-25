#include "List.h"
#include <string>

void List::push(Edge* e){

	if (e->weight == 0) {	//waga 0 oznacza brak kraw�dzi
		return;
	}

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

std::string List::toString() {

	if (headPointer != nullptr) {
	
		ListElement* holder = headPointer;
		std::string result = "";

		do {
			result += 
				" [" + std::to_string(holder->edge->v1) + "-" + std::to_string(holder->edge->v2) +  "] "
				+ std::to_string(holder->edge->weight) + " ,";
			holder = holder->next;
		} while (holder != nullptr);

		return result;
	}
	return "Lista jest pusta";
}

int List::sumWeight() {
	int weight = 0;
	ListElement* holder = headPointer;

	while (holder != nullptr) {
		weight += holder->edge->weight;
		holder = holder->next;
	}

	return weight;
}