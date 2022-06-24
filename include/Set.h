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

    // Constructor con valores iniciales
    Set(int n);

    /**
     * @brief Retorna el nodo al frente de la lista.
     * 
     * @return S_Node* 
     */
    S_Node* front();

    /**
     * @brief Retorna el número de elementos del conjunto.
     * 
     * @return int El número de elementos del conjunto.
     */
    int size();

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
     * @brief Verifica si el elemento se encuentra en el conjunto.
     * 
     * @param data El elemento.
     * @return true si el elemento se encuentra en el conjunto.
     * @return false 
     */
    bool contains(int data);

    /**
     * @brief Retorna un nuevo conjunto con todos los elementos del primer
     * conjunto salvo los elementos del segundo conjunto.
     * 
     * @param set El segundo conjunto.
     * @return Set El conjunto diferencia.
     */
    Set difference(Set set);

    /**
     * @brief Muestra los elementos del conjunto.
     * 
     */
    void display();
};

#endif // SET_H