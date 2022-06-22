#include <iostream>

template <typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T> *aux = head;
    while (aux != nullptr) {
        count++;
        aux = aux->next;
    }
    return count;
}

template <typename T>
void LinkedList<T>::push(T *data) {
    Node<T> *node = new Node<T>(data);
    node->next = head;
    head = node;
}

template <typename T>
void LinkedList<T>::pushBack(T *data) {
    Node<T> *node = new Node<T>(data);
    if (isEmpty()) {
        head = node;
    }
    else {
        Node<T> *aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = node;
    }
}

template <typename T>
T LinkedList<T>::pop() {
    if (isEmpty()) {
        return;
    }
    else {
        Node<T> *aux = head;
        T data = aux->data;
        head = aux->next;

        delete aux;
        return data;
    }
}

template <typename T>
T* LinkedList<T>::get(int i) {
    // Compatibilidad con índices negativos
    if (i < 0) {
        i += size();
    }
    // Índice fuera de rango
    if (i < 0 || i >= size()) {
        throw std::invalid_argument("Error: index out of range");
    }
    else {
        Node<T> *aux = head;
        for (int j = 0; j < i; j++) {
            aux = aux->next;
        }
        return aux->data;
    }
}

template <typename T>
void LinkedList<T>::display() {
    if (isEmpty())
        std::cout << "The list is empty" << std::endl;
    else {
        for (Node* node = head; node != nullptr; node = node->next) {
            std::cout << aux->data << std::endl;
        }
    }
}