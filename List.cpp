#include "List.h"
#include <iostream>

List::List() {
    head = nullptr;
    last = nullptr;
}

List::~List() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next_node;
        delete current;
        current = next;
    }
}

void List::insert_last(int i) {
    Node* new_node = new Node(i);
    if (head == nullptr) {
        head = new_node;
        last = new_node;
    } else {
        last->next_node = new_node;
        last = new_node;
    }
}

Node* List::fetch(int i) {
    Node* current = head;
    while (current != nullptr && current->info != i) {
        current = current->next_node;
    }
    return current;
}

bool List::remove(int i) {
    if (head == nullptr) {
        return false;
    }
    
    if (head->info == i) {
        return remove_first(); 
    }

    Node* current = head;
    while (current->next_node != nullptr && current->next_node->info != i) {
        current = current->next_node;
    }

    if (current->next_node == nullptr) {
        return false;
    }

    Node* target = current->next_node;
    current->next_node = target->next_node;

    if (target == last) {
        last = current;
    }

    delete target;
    return true;
}

bool List::remove_first() {
    if (head == nullptr) {
        return false;
    } else if (head == last) {
        delete head;
        head = nullptr;
        last = nullptr;
        return true;
    } else {
        Node* first = head;
        head = head->next_node;
        delete first;
        return true;
    }
}

bool List::remove_last() {
    if (head == nullptr) {
        return false;
    } else if (head == last) {
        delete head;
        head = nullptr;
        last = nullptr;
        return true;
    } else {
        Node* previous = head;
        while (previous->next_node != last) {
            previous = previous->next_node;
        }
    
        delete last;                 
        last = previous;             
        last->next_node = nullptr;   
    
        return true;
    }
}

void List::print_first() {
    if (head != nullptr) {
        std::cout << head->info << std::endl;
    } else {
        std::cout << "Empty list" << std::endl;
    }
}

void List::print_last() {
    if (last != nullptr) {
        std::cout << last->info << std::endl;
    } else {
        std::cout << "Empty list" << std::endl;
    }
}