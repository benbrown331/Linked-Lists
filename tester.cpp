#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int>* list = new List<int>();
    list->insertStart(1);
    cout << "Inserted 1 at start" << endl;
    list->print("list");
    list->insertEnd(3);
    cout << "Inserted 3 at end" << endl;
    list->print("list");
    list->insertAt(2, 1);
    cout << "Inserted 2 at index 1" << endl;
    list->print("list");
    cout << "2 is at index " << list->find(2) << endl;
    cout << "1 is at index " << list->find(1) << endl;
    cout << "3 is at index " << list->find(3) << endl;
    cout << "4 is at index " << list->find(4) << endl;
    list->removeAt(1);
    cout << "Removed index 1" << endl;
    list->print("list");
    list->removeStart();
    cout << "Removed start." << endl;
    list->print("list");
    list->removeEnd();
    cout << "Removed end." << endl;
    list->print("list");
    delete list;
    return 0;
}