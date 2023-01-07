#include <iostream>
#include "coeffs.hpp"

CCoeffs::CCoeffs() {
    a = 0;
    b = 0;
    c = 0;
}

void CCoeffs::setValues(double a, double b, double c) {
    if (a==0) {
        std::cout << "this is not quadratic equation, terminated!\n";
        exit(1);
    }
    this->a = a;
    this->b = b;
    this->c = c;
}
