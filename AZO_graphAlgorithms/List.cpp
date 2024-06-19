#include "List.h"

void List::push(Edge e){

	if (headPointer == nullptr) {	//gdy lista jest pusta
		tailPointer = new ListElement;
		tailPointer->next = nullptr;
		tailPointer->previous = nullptr;
		tailPointer->edge = e;
		headPointer = tailPointer;
	}
	else {
		//Utworzenie wska�nika, kt�ry przechowa pozycj� poprzedniego elementu
		// po przypisaniu nowego elementu do wska�nika na ogon listy
		ListElement* lastElement = tailPointer;

		//Przypisanie do wska�nika na ogon nowego elementu i uzupe�nienie jego p�l
		tailPointer = new ListElement;
		tailPointer->edge = e;
		tailPointer->next = nullptr;
		tailPointer->previous = lastElement;

		//Przypisanie ostatniemu elementowi wska�nika na nowy element
		lastElement->next = tailPointer;
	}
	list_length++;
}