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
		//Utworzenie wskaŸnika, który przechowa pozycjê poprzedniego elementu
		// po przypisaniu nowego elementu do wskaŸnika na ogon listy
		ListElement* lastElement = tailPointer;

		//Przypisanie do wskaŸnika na ogon nowego elementu i uzupe³nienie jego pól
		tailPointer = new ListElement;
		tailPointer->edge = e;
		tailPointer->next = nullptr;
		tailPointer->previous = lastElement;

		//Przypisanie ostatniemu elementowi wskaŸnika na nowy element
		lastElement->next = tailPointer;
	}
	list_length++;
}