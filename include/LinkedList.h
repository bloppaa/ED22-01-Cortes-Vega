#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @brief Una clase para representar un nodo simple.
 * 
 * @tparam T El tipo del nodo.
 */
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node<T>(T data) {
        this->data = data;
        next = nullptr;
    }
};

/**
 * @brief Una clase para representar una lista enlazada simple.
 * 
 * @tparam T El tipo de la lista.
 */
template <typename T>
class LinkedList
{
    Node<T> *head;

public:
    // Constructor predeterminado
    LinkedList<T>() {
        head = nullptr;
    }

    /**
     * @brief Verifica si la lista está vacía.
     * 
     * @return true si la lista no tiene elementos.
     * @return false 
     */
    bool isEmpty();

    /**
     * @brief Retorna el número de elementos en la lista.
     * 
     * @return int El número de elementos en la lista.
     */
    int size();

    /**
     * @brief Añade un nuevo elemento al inicio de la lista.
     * 
     * @param data El elemento que se añadirá.
     */
    void push(T data);

    /**
     * @brief Añade un nuevo elemento al final de la lista.
     * 
     * @param data El elemento que se añadirá.
     */
    void pushBack(T data);

    /**
     * @brief Remueve y retorna el primer elemento de la lista.
     * 
     * @return T El primer elemento de la lista.
     */
    T pop();

    /**
     * @brief Obtiene el i-ésismo elemento de la lista.
     * 
     * @param i El índice del elemento. Este método también acepta índices
     *          negativos.
     * @return T El elemento en la i-ésima posición.
     */
    T get(int i);

    /**
     * @brief Muestra los elementos de la lista.
     * 
     */
    void display();
};

#include "../src/LinkedList.tpp"

#endif // LINKED_LIST_H