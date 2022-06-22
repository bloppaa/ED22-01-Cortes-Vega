#ifndef PERSON_H
#define PERSON_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class Person
{
    int xStart, yStart;
    int xEnd, yEnd;
    int xCenter, yCenter;

public:
    Person(cv::Rect&);

    int getXStart();

    int getYStart();

    int getXEnd();

    int getYEnd();

    int getXCenter();

    int getYCenter();
};

#endif // PERSON_H