#include "CentroidTracker.h"

CentroidTracker::CentroidTracker(int maxFrames) {
    nextPersonID = 0;
    people = new LinkedList<Person>();
    maxFrames = 40;
}

void CentroidTracker::regist(int x, int y) {
    
}

void CentroidTracker::deregist(int personID) {

}

LinkedList<Person> *CentroidTracker::update(LinkedList<cv::Rect> rects) {

}

