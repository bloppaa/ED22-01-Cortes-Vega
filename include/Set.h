#ifndef SET_H
#define SET_H

/**
 * @brief Clase para representar un nodo simple.
 * 
 */
class S_Node
{
public:
    int data;
    S_Node* next;

    S_Node(int data) : data(data), next(nullptr) {}
};

/**
 * @brief Clase para representar un conjunto. Un conjunto no tiene elementos
 * repetidos, es decir, todos sus elementos son únicos.
 * 
 */
class Set
{
private:
    S_Node* head;

public:
    Set() : head(nullptr) {}

    /**
     * @brief Verifica si el conjunto está vacío.
     * 
     * @return true si el conjunto no tiene elementos.
     * @return false 
     */
    bool isEmpty();

    /**
     * @brief Añade un elemento al conjunto. Si el elemento ya se encuentra
     * en el conjunto, este no se añadirá.
     * 
     * @param data El elemento que se ingresará.
     */
    void add(int data);

    /**
     * @brief Muestra los elementos del conjunto.
     * 
     */
    void display();
};

#endif // SET_H