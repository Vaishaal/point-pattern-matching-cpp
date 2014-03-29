#include "ppm.h"
#include <math.h>
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

