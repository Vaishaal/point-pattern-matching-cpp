#include "../ppm.h"
#include <Eigen/Dense>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace Eigen;
TEST_CASE( "Translations work", "[affine_transformations]" ) {
    MatrixXd* m = generate_translation(2,3);
    Vector3d v(5,7,1);
    Vector3d v_expect(7,10,1);
    Vector3d v_actual = (*m)*v;
    REQUIRE(v_actual == v_expect);
}
