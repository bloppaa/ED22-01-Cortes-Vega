#include "Set.h"

#include <iostream>

S_Node* Set::front() {
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

Set Set::difference(Set B) {
    Set C = Set();
    S_Node* a_it = head;
    while (a_it != nullptr) {
        S_Node* b_it = B.front();
        while (b_it != nullptr) {
            if (a_it->data == b_it->data)
                break;
            b_it = b_it->next;
        }
        if (b_it == nullptr)
            C.add(a_it->data);
        a_it = a_it->next;
    }
    return C;
}

void Set::display() {
    for (S_Node* node = head; node != nullptr; node = node->next) {
        std::cout << node->data << ", ";
    }
}