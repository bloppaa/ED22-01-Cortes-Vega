#include "Person.h"

Person::Person(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
}

int Person::getX() { return x; }

int Person::getY() { return y; }

void Person::setX(int x) { this->x = x; }

void Person::setY(int y) { this->y = y; }

int Person::getFramesDissappeared() { return framesDissappeared; }

void Person::setFramesDissappeared(int frames) {
    this->framesDissappeared = frames;
}