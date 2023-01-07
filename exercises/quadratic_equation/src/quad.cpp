#include <iostream>
#include <cmath>
#include "quad.hpp"

void CQuadraticEquation::ask_input() {
    int a{0}, b{0}, c{0};
    std::cout << "Enter coefficients:!\n";
    std::cin >> a >> b >> c;
    coeffs.setValues(a,b,c);
}

void CQuadraticEquation::displayEquation() {
    if (coeffs.a==1) {
        std::cout << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
    } else {
        std::cout << coeffs.a << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
    }
}

void CQuadraticEquation::solve() {
    double delta{ coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c };
    if (delta >= 0) {
        double delta_root{std::sqrt(delta)};
        S1.real = (-coeffs.b + delta_root) / (2*coeffs.a);
        S2.real = (-coeffs.b - delta_root) / (2*coeffs.a);
    } else {
        double delta_root{std::sqrt(-delta)};
        S1.real = -coeffs.b / 2*coeffs.a;
        S1.imag = delta_root / 2*coeffs.a;
        S2.real = -coeffs.b / 2*coeffs.a;
        S2.imag = -delta_root / 2*coeffs.a;
    }
}


void CQuadraticEquation::displaySolution() {
    std::cout << "Solutions are:\n";
    if (S1.imag > 0) {
        std::cout << S1.real << " + " << S1.imag << "i" << "\n";
    } else if (S1.imag < 0) {
        std::cout << S1.real << " - " << -S1.imag << "i" << "\n";
    } else {
        std::cout << S1.real << "\n";
    }

    if (S2.imag > 0) {
        std::cout << S2.real << " + " << S2.imag << "i" << "\n";
    } else if (S2.imag < 0) {
        std::cout << S2.real << " - " << -S2.imag << "i" << "\n";
    } else {
        std::cout << S2.real << "\n";
    }
}



