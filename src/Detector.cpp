#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

using namespace cv;

#include "Detector.h"

void Detector::toggleMode() {
    m = (m == Default ? Daimler : Default);
}
    
std::string Detector::modeName() const {
    return (m == Default ? "Default" : "Daimler");
}

std::vector<Person> Detector::detect(InputArray img) {
    // Run the detector with default parameters. To get a higher hit-rate
    // (and more false alarms, respectively), decrease the hitThreshold and
    // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
    std::vector<Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2,2), Size(4,4), 1.05, 2, false);
    else if (m == Daimler)
        hog_d.detectMultiScale(img, found, 1, Size(2,2), Size(4,4), 1.05, 3, true);
    
    std::vector<Person> persons;
    for (std::vector<Rect>::iterator it = found.begin(); it != found.end(); ++it) {
        Rect &r = *it;
        Person p(r);
        persons.push_back(p);
    }
    return persons;
}

void Detector::adjustRect(Rect & r) const {
    // The HOG detector returns slightly larger rectangles than the real objects,
    // so we slightly shrink the rectangles to get a nicer output.
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}