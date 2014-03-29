#include "ppm.h"
int main() {
    std::cout << *generateTranslator(3,4) << std::endl;
    std::cout << *generateRotator(degreeToRadian(90)) << std::endl;
}
