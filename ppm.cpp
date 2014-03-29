#include "ppm.h"

using Eigen::MatrixXd;

MatrixXd* generate_translation(long x_trans, long y_trans)
{
  MatrixXd* m = new MatrixXd(3,3);
  *m << 1, 0, x_trans,
       0, 1, y_trans,
       0, 0, 1;
  return m;
}


