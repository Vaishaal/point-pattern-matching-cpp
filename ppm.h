#include <iostream>
#include <Eigen/Dense>

#define EPSILON 0.00001
using Eigen::MatrixXd;

/*Generates a 3x3 matrix that translates a 2d point by x and y*/
MatrixXd* generateTranslator(long x, long y);
/*Generates a 3x3 matrix that rotates a 2d point by theta (in radians)*/
bool operator==(const Eigen::Vector3d &v1, const Eigen::Vector3d &v2);
MatrixXd* generateRotator(double theta);
double degreeToRadian(double degree);
double radianToDegree(double radian);
bool AreSame(double a, double b);
