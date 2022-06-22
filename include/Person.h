#ifndef PERSON_H
#define PERSON_H

/**
 * @brief Clase que guarda información de una persona.
 * 
 */
class Person
{   
    int ID;
    int x, y;
    int framesDissappeared;

public:
    Person(int ID, int x, int y);

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    int getFramesDissappeared();

    void setFramesDissappeared(int frames);


};

#endif // PERSON_H