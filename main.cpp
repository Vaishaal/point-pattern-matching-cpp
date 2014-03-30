#include "ppm.h"
#include <ANN/ANN.h>
int main() {
    std::cout << *generateTranslator(3,4) << std::endl;
    std::cout << "\n";
    std::cout << *generateRotator(degreeToRadian(90)) << std::endl;
    VectorList points;
    generatePoints(100,-100,100,-100,100, points); 
    std::cout << "Average distance: " << computeAverageDistance(points) << std::endl;
}
