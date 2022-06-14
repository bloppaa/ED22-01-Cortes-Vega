#include "include/Person.h"

Person::Person(cv::Rect &r) {
    xStart = r.x;
    yStart = r.y;
    xEnd = r.x + r.width;
    yEnd = r.y + r.height;
    xCenter = r.x + ((int)r.width / 2);
    yCenter = r.y + ((int)r.height / 2);
}

int Person::getXStart() {
    return xStart;
}

int Person::getYStart() {
    return yStart;
}

int Person::getXEnd() {
    return xEnd;
}

int Person::getYEnd() {
    return yEnd;
}

int Person::getXCenter() {
    return xCenter;
}

int Person::getYCenter() {
    return yCenter;
}