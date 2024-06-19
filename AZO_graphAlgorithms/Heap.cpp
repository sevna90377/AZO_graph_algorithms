#include "Heap.h"

//dodawanie nowej kraw�dzi do kopca
void Heap::push(Edge e) {

    Edge* newPointer = new Edge[heap_length + 1];

    for (int i = 0; i < heap_length; i++) {
        newPointer[i] = rootPointer[i];
    }

    newPointer[heap_length] = e;

    delete rootPointer;
    rootPointer = newPointer;
    heap_length++;

    heapifyUp((heap_length - 1) >> 1);
}

//usuwanie korzenia kopca
Edge Heap::pop() {

    Edge holder = rootPointer[0];

    rootPointer[0] = rootPointer[heap_length - 1];
    heap_length--;

    heapifyDown(0);

    return holder;
}

void Heap::heapifyUp(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest;

    if (l > 0 && l < heap_length) {

        //sprawdzenie czy lewy potomek jest mniejszy od swojego ojca
        if (rootPointer[l].weight < rootPointer[i].weight) {
            smallest = l;
        }
        else {
            smallest = i;
        }

        //sprawdzenie czy prawy potomek jest wi�kszy od swojego ojca
        if (r < heap_length && rootPointer[r].weight < rootPointer[smallest].weight) {
            smallest = r;
        }

        //zamiana warto�ci miejscami
        if (smallest != i) {
            Edge holder;

            holder = rootPointer[i];
            rootPointer[i] = rootPointer[smallest];
            rootPointer[smallest] = holder;
        }
    }

    //metoda zostaje wywo�ana rekurencyjnie w kierunku korzenia, je�li element 'i' nie by� nim
    if (i > 0) { heapifyUp((i - 1) >> 1); }
}

void Heap::heapifyDown(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest;

    if (l > 0 && l < heap_length) {

        //sprawdzenie czy lewy potomek jest mniejszy od swojego ojca
        if (rootPointer[l].weight < rootPointer[i].weight) {
            smallest = l;
        }
        else {
            smallest = i;
        }

        if (heap_length > 2) {
            //sprawdzenie czy prawy potomek jest wi�kszy od swojego ojca
            if (r < heap_length && rootPointer[r].weight < rootPointer[smallest].weight) {
                smallest = r;
            }
        }

        //zamiana warto�ci miejscami
        if (smallest != i) {
            Edge holder;

            holder = rootPointer[i];
            rootPointer[i] = rootPointer[smallest];
            rootPointer[smallest] = holder;

            //metoda zostaje wywo�ana rekurencyjnie, gdy� zamiana pozycji mog�a spowodowa� 
            //zaburzenie w�asno�ci kopca w danym poddrzewie
            heapifyDown(smallest);
        }
    }
}

void Heap::display()
{
    if (rootPointer != nullptr) {
        display("", "", 0);     //metoda rysuj�ca kopiec

        std::cout << std::endl;

        for (int i = 0; i < heap_length; i++) {     //wypisanie tablicowe kopca
            std::cout << rootPointer[i].weight << ", ";
        }
    }
    else {
        std::cout << "Kopiec jest pusty." << std::endl;
    }
}

void Heap::display(std::string sp, std::string sn, int from)
{
    std::string cr, cl, cp;
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
    std::string s;

    if (from < heap_length)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        display(s + cp, cr, 2 * from + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << rootPointer[from].weight << "\n";

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        display(s + cp, cl, 2 * from + 1);
    }
}