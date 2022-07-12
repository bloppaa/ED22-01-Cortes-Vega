#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class List
{
    class Node;

    Node *head, *tail;
    int mSize;

public:
    List();

    List(std::initializer_list<T> args);

    class Iterator;

    Iterator begin() { return Iterator(head); }

    Iterator end() { return Iterator(nullptr); }

    int size();

    bool empty();

    void push_back(T &data);

    T &get(int i);

    T &operator[](int i);

    void print();

    friend std::ostream &operator<<(std::ostream &os, List<T> &list) {
        List<T>::Iterator it;
        for (it = list.begin(); it != list.end(); ++it) {
            os << *it << " ";
        }
        return os;
    }

    void remove(int data);

private:
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T &data) : data(data), next(nullptr) {}
    };

public:
    class Iterator
    {
        Node *current;

    public:
        Iterator() : current(nullptr) {}

        Iterator(Node *node) : current(node) {}

        void operator=(Iterator it) {
            current = it.current;
        }

        bool operator!=(Iterator it) {
            return current != it.current;
        }

        void operator++() {
            current = current->next;
        }

        T &operator*() {
            return current->data;
        }
    };
};

#include "../src/List.tpp"

#endif // LIST_H