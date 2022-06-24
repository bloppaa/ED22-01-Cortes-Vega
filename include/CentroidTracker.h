#ifndef CENTROID_TRACKER_H
#define CENTROID_TRACKER_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <vector>
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
     * @param x Coordenada x del centroide inicial de la persona.
     * @param y Coordenada y del centroide inicial de la persona.
     */
    void regist(int x, int y);

    /**
     * @brief Elimina la persona especificada de la lista de personas.
     * 
     * @param personID El ID de la persona.
     */
    void deregist(int personID);

    /**
     * @brief Actualiza el centroide de una persona con respecto al frame
     * anterior. También registra y elimina personas según sea necesario.
     * 
     * @param rects La lista de rectángulos detectados por el detector.
     * @return LinkedList<Person>* La lista de personas.
     */
    LinkedList<Person> *update(std::vector<cv::Rect> rects);
};

#endif // CENTROID_TRACKER_H