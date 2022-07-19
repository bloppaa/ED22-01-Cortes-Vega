#include "centroidtracker.h"

#include <set>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef std::pair<int, int> point;

CentroidTracker::CentroidTracker()
{
    nextObjectID = 0;
    maxDisappeared = 50;
}

CentroidTracker::CentroidTracker(int maxDisappeared)
{
    nextObjectID = 0;
    this->maxDisappeared = maxDisappeared;
}

void CentroidTracker::registr(point centroid)
{
    objects[nextObjectID] = centroid;
    disappeared[nextObjectID] = 0;
    nextObjectID++;
}

void CentroidTracker::deregister(int objectID)
{
    objects.erase(objectID);
    disappeared.erase(objectID);
}

float dist(point p1, point p2)
{
    float x = p2.first - p1.first;
    float y = p2.second - p1.second;
    return sqrt(x * x + y * y);
}

template <typename T1, typename T2>
std::vector<T1> keys(std::map<T1, T2> dict)
{
    std::vector<T1> k;
    for (auto i : dict)
    {
        k.push_back(i.first);
    }
    return k;
}

template <typename T1, typename T2>
std::vector<T2> values(std::map<T1, T2> dict)
{
    std::vector<T2> v;
    for (auto i : dict)
    {
        v.push_back(i.second);
    }
    return v;
}

std::vector<std::vector<float>> cdist(std::vector<point> points1, std::vector<point> points2)
{
    std::vector<std::vector<float>> D;
    for (point p1 : points1)
    {
        std::vector<float> distances;
        for (point p2 : points2)
        {
            distances.push_back(dist(p1, p2));
        }
        D.push_back(distances);
    }
    return D;
}

std::vector<int> argsort(std::vector<float> vals)
{
    std::vector<int> idx(vals.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::stable_sort(idx.begin(), idx.end(),
                     [vals](size_t i1, size_t i2)
                     { return vals[i1] < vals[i2]; });

    return idx;
}

std::vector<float> min(std::vector<std::vector<float>> D)
{
    std::vector<float> mins;
    for (std::vector<float> v : D)
    {
        float min = v[0];
        for (float f : v)
        {
            if (f < min)
                min = f;
        }
        mins.push_back(min);
    }
    return mins;
}

std::vector<int> argmin(std::vector<std::vector<float>> D)
{
    std::vector<int> mins;
    for (std::vector<float> v : D)
    {
        float min = v[0];
        int idx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < min)
            {
                min = v[i];
                idx = i;
            }
        }
        mins.push_back(idx);
    }
    return mins;
}

std::vector<int> swap(std::vector<int> v, std::vector<int> idx)
{
    std::vector<int> v2;
    for (int i : idx)
        v2.push_back(v[i]);
    return v2;
}

std::set<int> range_set(int range)
{
    std::set<int> s;
    for (int i = 0; i < range; i++)
    {
        s.insert(i);
    }
    return s;
}

std::set<int> difference(std::set<int> s1, std::set<int> s2)
{
    std::set<int> s;
    for (int i : s1)
    {
        if (s2.count(i) == 0)
            s.insert(i);
    }
    return s;
}

std::map<int, point> CentroidTracker::update(std::vector<std::vector<int>> rects)
{
    if (rects.empty())
    {
        for (int objectID : keys(disappeared))
        {
            disappeared[objectID]++;

            if (disappeared[objectID] > maxDisappeared)
            {
                deregister(objectID);
            }
        }
        return objects;
    }

    std::vector<point> inputCentroids;

    for (int i = 0; i < rects.size(); i++)
    {
        std::vector<int> rect = rects[i];
        int cX = (int)((rect[0] + rect[2]) / 2);
        int cY = (int)((rect[1] + rect[3]) / 2);
        inputCentroids.push_back(std::make_pair(cX, cY));
    }

    if (objects.empty())
    {
        for (int i = 0; i < inputCentroids.size(); i++)
        {
            registr(inputCentroids[i]);
        }
    }
    else
    {
        std::vector<int> objectIDs = keys(objects);
        std::vector<point> objectCentroids = values(objects);

        std::vector<std::vector<float>> D = cdist(objectCentroids, inputCentroids);

        std::vector<int> rows = argsort(min(D));

        std::vector<int> cols = swap(argmin(D), rows);

        std::set<int> usedRows;
        std::set<int> usedCols;

        for (int i = 0; i < rows.size(); i++)
        {
            int row = rows[i];
            int col = cols[i];

            if (usedRows.count(row) != 0 || usedCols.count(col) != 0)
            {
                continue;
            }

            int objectID = objectIDs[row];
            objects[objectID] = inputCentroids[col];
            disappeared[objectID] = 0;

            usedRows.insert(row);
            usedCols.insert(col);
        }

        std::set<int> unusedRows = difference(range_set(D.size()), usedRows);
        std::set<int> unusedCols = difference(range_set(D[0].size()), usedCols);

        if (D.size() >= D[0].size())
        {
            for (int row : unusedRows)
            {
                int objectID = objectIDs[row];
                disappeared[objectID]++;

                if (disappeared[objectID] > maxDisappeared)
                {
                    deregister(objectID);
                }
            }
        }
        else
        {
            for (int col : unusedCols)
            {
                registr(inputCentroids[col]);
            }
        }
    }

    return objects;
}