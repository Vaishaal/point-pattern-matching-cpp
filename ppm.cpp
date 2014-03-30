#include "ppm.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <fstream>

#define _USE_MATH_DEFINES
using Eigen::MatrixXd;
Matrix3d* generateTranslator(long x, long y)
{
  Matrix3d* m = new Matrix3d();
  *m << 1, 0, x,
       0, 1,  y,
       0, 0, 1;
  return m;
}

Matrix3d* generateRotator(double theta)
{
  Matrix3d* m = new Matrix3d();
  *m << cos(theta), -sin(theta), 0,
        sin(theta), cos(theta),  0,
        0,          0,           1;
  return m;
}

double degreeToRadian(double degree)
{
    return (degree*M_PI)/180;
}

double radianToDegree(double radian)
{
    return (radian*180)/M_PI;
}

bool areSame(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

bool operator==(const Eigen::Vector3d &v1, const Eigen::Vector3d &v2)
{
    return areSame(v1(0), v2(0)) &&
           areSame(v1(1), v2(1)) &&
           areSame(v1(2), v2(2));
}

bool localMatch(VectorList &a, VectorList &b, double p) 
{
    return false;
}

bool globalMatch(VectorList &l1, VectorList &l2, double p)
{
    return false;
}

bool computeNearestNeighbors(VectorList &points, VectorListList &neighbors)
{
    return false;
}

double computeAverageDistance(VectorList &points)
{
   double total = 0;
   for (VectorList::iterator p1 = points.begin(); p1 != points.end(); ++p1)
   {
       for (VectorList::iterator p2 = points.begin(); p2 != points.end(); ++p2)
       {
           std::cout << (*p1 - *p2).norm() << std::endl;
           total += (*p1 - *p2).norm();
       }
   }
   return total/(points.size()*points.size());
}

int findBin(double avgDistance, Vector3d &point, double min, int rows)
{
    return (point[0] - min)/avgDistance + rows*(point[1] - min)/avgDistance;
}

bool putInBin(double avgDistance, Vector3d &point, VectorListList &bins,
              double min, int rows)
{
    int bin = findBin(avgDistance, point, min, rows);
    if (!bins[bin])
        bins[bin] = new VectorList();
    bins[bin]->push_back(point);
}

bool generatePoints(int numPoints, int xmin, int xmax,  int ymin, int ymax,
                     VectorList &points)
{
    srand(time(NULL));
    for (int i = 0; i < numPoints; ++i)
    {
        points.push_back(Vector3d(rand() % xmax + xmin, rand() % ymax + ymin, 1));
    }
    return true;
}

double computeMax(VectorList &points)
{
    double max_x = std::numeric_limits<double>::min();
    double max_y = std::numeric_limits<double>::min();
    for (VectorList::iterator p1 = points.begin(); p1 != points.end(); ++p1)
    {
        max_x = std::max((*p1)[0], max_x);
        max_y = std::max((*p1)[1], max_y);
    }

    return std::max(max_x, max_y);
}

double computeMin(VectorList &points)
{
    double min_x = std::numeric_limits<double>::max();
    double min_y = std::numeric_limits<double>::max();
    for (VectorList::iterator p1 = points.begin(); p1 != points.end(); ++p1)
    {
        min_x = std::min((*p1)[0], min_x);
        min_y = std::min((*p1)[1], min_y);
    }
    return std::min(min_x, min_y);

}
bool mainLoop(VectorList &points, double lambda, double p)
{
    return false;
}
