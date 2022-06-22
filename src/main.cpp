#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.h"
#include "Person.h"

using namespace cv;

int main(int argc, char **argv) {
    Detector detector;
    Mat image;
    image = imread("C:/Users/pc/Pictures/images/image1679.png");
    detector.toggleMode();
    std::cout << detector.modeName() << std::endl;
    
    std::vector<Person> found = detector.detect(image);
    for (std::vector<Person>::iterator it = found.begin(); it != found.end(); it++) {
        Person &p = *it;
        std::cout
            << "(" << p.getXStart() << ", " << p.getYStart()
            << ")" << std::endl;

        rectangle(
            image, Point(p.getXStart(), p.getYStart()),
            Point(p.getXEnd(), p.getYEnd()), Scalar(0, 255, 0), 2
            );
        circle(
            image, Point(p.getXCenter(), p.getYCenter()), 3,
            Scalar(0, 0, 255), 3
            );
    }
    imshow("People detector", image);
    waitKey(0);
    
    return 0;
}
