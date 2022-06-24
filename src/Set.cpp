#include "Set.h"

#include <iostream>

S_Node* S_Node::front() {
    return head;
}

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

bool Set::contains(int data) {
    for (S_Node* node = head; node != nullptr; node = node->next) {
        if (node->data == data)
            return true;
    }
    // No lo encontró
    return false;
}

void Set::display() {
    for (S_Node* node = head; node != nullptr; node = node->next) {
        std::cout << node->data << ", ";
    }
}