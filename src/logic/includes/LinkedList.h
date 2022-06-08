#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class Node
{
public:
    T *data;
    Node<T> *next;

    // Default constructor
    Node<T>() {
        data, next = nullptr;
    }

    Node<T>(T *data) {
        this->data = data;
        next = nullptr;
    }
};

/**
 * @brief A class to represent a singly Linked List.
 * 
 * @tparam T The type of the list.
 */
template <typename T>
class LinkedList
{
    Node<T> *head;

public:
    // Default constructor
    LinkedList<T>() {
        head = nullptr;
    }

    /**
     * @brief Check if the list is empty.
     * 
     * @return true if the list has no elements.
     * @return false 
     */
    bool isEmpty();

    /**
     * @brief Return the number of elements in the list.
     * 
     * @return int The number of elements in the list.
     */
    int size();

    /**
     * @brief Add a new element at the start of the list. 
     * 
     * @param data Generic data.
     */
    void add(T *data);

    /**
     * @brief Remove and return the first element of the list.
     * 
     * @return T The first element of the list.
     */
    T pop();

    /**
     * @brief Get the i-th element of the list.
     * 
     * @param i The index of the element. (Starts at 0 and ends at n-1).
     * @return T The element at the i-th position.
     */
    T get(int i);

    /**
     * @brief Display the elements of the list.
     * 
     */
    void display();
};

#include "../LinkedList.tpp"

#endif // LINKED_LIST_H