#ifndef CENTROID_TRACKER_H
#define CENTROID_TRACKER_H

#include <map>
#include <vector>

class CentroidTracker
{
    int nextObjectID;
    std::map<int, std::pair<int, int>> objects;
    std::map<int, int> disappeared;
    int maxDisappeared;

public:
    CentroidTracker();

    CentroidTracker(int maxDisappeared);

    void registr(std::pair<int, int> centroid);

    void deregister(int objectID);

    std::map<int, std::pair<int, int>> update(std::vector<std::vector<int>> rects);
};

#endif // CENTROID_TRACKER_H