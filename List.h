#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "iostream"

class List {
private:
    Node* head;
    Node* last;

public:
    List();
    ~List();

    void insert_last(int i);
    
    Node* fetch(int i);
    
    bool remove(int i); 
    
    bool remove_first();
    
    bool remove_last(); 
    
    void print_first();
    
    void print_last();
};

#endif