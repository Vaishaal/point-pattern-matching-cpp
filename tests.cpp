#include "ppm.h"
#include <Eigen/Dense>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace Eigen;
TEST_CASE( "Translations", "[affine_transformations]" ) {
    Matrix3d* m = generateTranslator(2,3);
    Vector3d v(5,7,1);
    Vector3d v_expect(7,10,1);
    Vector3d v_actual = (*m)*v;
    REQUIRE(v_actual == v_expect);
}
TEST_CASE( "Rotations", "[affine_transformations]" ) {
    Matrix3d* m1 = generateRotator(degreeToRadian(360));
    Matrix3d* m2 = generateRotator(degreeToRadian(45));
    Matrix3d* m3 = generateRotator(degreeToRadian(90));
    Vector3d v(1,0,1);
    Vector3d v1_expect(1,0,1);
    Vector3d v2_expect(sqrt(2)/2,sqrt(2)/2,1);
    Vector3d v3_expect(0,1,1);
    Vector3d v1_actual = (*m1)*v;
    Vector3d v2_actual = (*m2)*v;
    Vector3d v3_actual = (*m3)*v;
    REQUIRE(v1_actual == v1_expect);
    REQUIRE(v2_actual == v2_expect);
    REQUIRE(v3_actual == v3_expect);
}
