#ifndef PERSON_H
#define PERSON_H

/**
 * @brief Clase que guarda información de una persona.
 * 
 */
class Person
{   
    // ID único de una persona
    int ID;
    // Coordenadas del centroide
    int x, y;
    // Cantidad de frames que la persona ha estado fuera de alcance
    int framesDissappeared;

public:
    Person(int ID, int x, int y);

    int getID();

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    int getFramesDissappeared();

    void setFramesDissappeared(int frames);
};

#endif // PERSON_H