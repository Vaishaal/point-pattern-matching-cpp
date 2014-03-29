#include <iostream>
#include <Eigen/Dense>
#include<vector>
#define EPSILON 0.00001
using namespace Eigen;
typedef std::vector<Matrix3d*> MatrixVector;
/*Generates a 3x3 matrix that translates a 2d point by x and y*/
Matrix3d* generateTranslator(long x, long y);
/*Generates a 3x3 matrix that rotates a 2d point by theta (in radians)*/
bool operator==(const Eigen::Vector3d &v1, const Eigen::Vector3d &v2);
Matrix3d* generateRotator(double theta);
double degreeToRadian(double degree);
double radianToDegree(double radian);
bool areSame(double a, double b);
