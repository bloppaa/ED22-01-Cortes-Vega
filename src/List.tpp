#include <iostream>

template <typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    mSize = 0;
}

template <typename T>
List<T>::List(std::initializer_list<T> args) {
    head = nullptr;
    tail = nullptr;
    mSize = 0;

    for (auto arg: args) { push_back(arg); }
}

template <typename T>
int List<T>::size() {
    return mSize;
}

template <typename T>
bool List<T>::empty() {
    return head == nullptr;
}

template <typename T>
void List<T>::push_back(T &data) {
    Node *node = new Node(data);
    if (empty()) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    mSize++;
}

template <typename T>
T &List<T>::get(int i) {
    Node *aux = head;
    for (int j = 0; j < i; j++) {
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
T &List<T>::operator[](int i) {
    return get(i);
}

template <typename T>
void List<T>::print() {
    if (empty()) {
        std::cout << "Empty list";
    }
    else {
        Node *aux = head;
        while (aux != nullptr) {
            std::cout << aux->data << " ";
            aux = aux->next;
        }
    }
}

template <typename T>
void List<T>::remove(int ID) {
    Node *aux = head;
    if (aux->data.getID() == ID) {
        head = aux->next;
        delete aux;
    }
    else {
        while (aux->next != nullptr) {
            if (aux->next->data.getID() == ID) {
                Node *aux2 = aux->next;
                aux->next = aux->next->next;
                delete aux2;
                break;
            }
        }
    }
    mSize--;
}