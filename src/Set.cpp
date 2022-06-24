#include "Set.h"

#include <iostream>

bool Set::isEmpty() {
    return head == nullptr;
}

void Set::add(int data) {
    // Busca si el dato ya se encuentra en la lista
    for (S_Node* node = head; node != nullptr; node = node->next) {
        if (node->data == data)
            return;
    }
    // No lo encontró
    S_Node* node = new S_Node(data);
    node->next = head;
    head = node;
}

void Set::display() {
    for (S_Node* node = head; node != nullptr; node = node->next) {
        std::cout << node->data << ", ";
    }
}