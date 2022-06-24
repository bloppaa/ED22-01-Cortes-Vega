#include "CentroidTracker.h"

CentroidTracker::CentroidTracker(int maxFrames) {
    nextPersonID = 0;
    people = new LinkedList<Person>();
    this->maxFrames = maxFrames;
}

void CentroidTracker::regist(int x, int y) {
    Person *p = new Person(nextPersonID, x, y);
    people->push(p);
    nextPersonID++;
}

void CentroidTracker::deregist(int personID) {
    
}

LinkedList<Person> *CentroidTracker::update(LinkedList<cv::Rect> rects) {

}