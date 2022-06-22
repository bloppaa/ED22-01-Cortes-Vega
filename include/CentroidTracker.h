#ifndef CENTROID_TRACKER_H
#define CENTROID_TRACKER_H

#include "LinkedList.h"
#include "Person.h"

/**
 * @brief Clase que se encarga de los cálculos necesarios para
 * hacer el seguimiento de centroides de personas.
 * 
 */
class CentroidTracker
{
private:
    // Cada persona nueva que entra tiene un ID único.
    int nextPersonID;
    LinkedList<Person> *people;
    // La cantidad máxima de frames que una persona puede estar
    // fuera de alcande antes de ser eliminada.
    int maxFrames;

public:
    CentroidTracker(int maxFrames);

    /**
     * @brief Ingresa una persona nueva a la lista de personas.
     * 
     * @param x Coordenada X del centroide inicial de la persona.
     * @param y Coordenada Y del centroide inicial de la persona.
     */
    void register(int x, int y);

    /**
     * @brief Elimina la persona especificada de la lista de personas.
     * 
     * @param personID El ID de la persona.
     */
    void deregister(int personID);

    /**
     * @brief Método principal que hace todos los cálculos necesarios
     * para hacer el seguimiento de centroides.
     * 
     * @param rects La lista de rectángulos detectados por el detector.
     * @return LinkedList<Person>* La lista de personas.
     */
    LinkedList<Person> *update(LinkedList<Rect> rects);
};

#endif // CENTROID_TRACKER_H