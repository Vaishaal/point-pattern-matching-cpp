#include <iostream>
#include <Eigen/Dense>
#include<vector>
#define EPSILON 0.00001
#define K 5
using namespace Eigen;
/*Useful typedefs*/
typedef std::vector<Matrix3d*> MatrixList;
typedef std::vector<Vector3d*> VectorList;
typedef std::vector<VectorList*> VectorListList;

/*
 * Generates a 3x3 matrix that translates a 2d point by x and y
 *
 * This matrix will be multiplied by a 2d point in homogeneous coordinates
 * to generate a translation of that point by x and y
 */

Matrix3d* generateTranslator(long x, long y);

/*
 * Generates a 3x3 matrix that rotates a 2d point by theta (in radians)
 * This matrix will be multiplied by a 2d point in homogeneous coordinates
 * to generate a rotation of that point by theta
 */
Matrix3d* generateRotator(double theta);
bool operator==(const Eigen::Vector3d &v1, const Eigen::Vector3d &v2);
double degreeToRadian(double degree);
double radianToDegree(double radian);
bool areSame(double a, double b);
bool localMatch(VectorList &a, VectorList &b, double p);
bool globalMatch(VectorList &l1, VectorList &l2, double p);

/*
 * Use ANN to compute nearest neighbors and store result in neighbors
 *
 * ANN uses its own point representation so this function needs to take care 
 * of translation between eigen points and ANN points
 * */
bool computeNearestNeighbors(VectorList &points, VectorListList &neighbors);

/*
 * Brute force computation of average separation distance between two points in 
 * the query set
 *
 * Note: Iyengar used r/sqrt(n) as an approximation of average distance
 * We don't have to or can use the approximation because our points are
 * not guarenteed to be uniformly distributed on a disk of radius r.
 * Also since our query set is so much smaller than our background set
 * doing this computation is relatively cheap.
 *
 * Lambda times this distance will be the matching factor
 */
double computeAverageDistance(VectorList &points);

/*
 * These functions are used in part 1b of the iyengar algorithm
 * for precomputation of the location of query points so a quick lookup
 * can be performed to see if there exists a query point at a particular
 * coordinate
 */
int findBin(double avgDistance, Vector3d &point, VectorListList &bins);
bool putInBins(double avgDistance, Vector3d &point, VectorListList &bins);

