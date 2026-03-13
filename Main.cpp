#include "iostream"
#include "List.h"

int main(int argc, char** argv) {
	
    List* list = new List();
    list->insert_last(10);
    list->insert_last(20);
    list->insert_last(30);
    list->print_first();
    list->print_last();
    list->remove_last();
    list->remove_first();
    list->insert_last(20);
    list->print_first();
    list->print_last();



}