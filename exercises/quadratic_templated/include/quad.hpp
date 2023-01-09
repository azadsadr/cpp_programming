#pragma once
#include <cmath>
#include <fstream>
#include "coeffs.hpp"
#include "complex.hpp"

template <typename T>
class CQuadraticEquation {
public:
    CCoeffs<T> coeffs;
    CComplex<T> S1;
    CComplex<T> S2;
    bool solved{false};

    void ask_input();
    void read_from_file();
    void write_to_file();
    void displayEquation();
    void solve();
    void displaySolution();
};

template <typename T>
void CQuadraticEquation<T>::ask_input() {
    int a{0}, b{0}, c{0};
    std::cout << "Enter coefficients:!\n";
    std::cin >> a >> b >> c;
    coeffs.setValues(a,b,c);
}

template <typename T>
void CQuadraticEquation<T>::read_from_file() {
    std::ifstream file("input.txt");
    if (file) {
        std::cout << "successfully read the file!\n";
        int a{0}, b{0}, c{0};
        file >> a >> b >> c;
        coeffs.setValues(a,b,c);
    } else {
        std::cout << "failed to read the file!\n";
        exit(1);
    }
    file.close();
}

template <typename T>
void CQuadraticEquation<T>::write_to_file() {
    std::fstream file("solution_history.txt", std::ios::app);
    if (solved==true) {
        if (coeffs.a==1) {
        file << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
        } else {
        file << coeffs.a << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
        }
        std::cout << "equation saved in slution history!\n";
    }
}

template <typename T>
void CQuadraticEquation<T>::displayEquation() {
    if (coeffs.a==1) {
        std::cout << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
    } else {
        std::cout << coeffs.a << "x^2 + " << coeffs.b << "x + " << coeffs.c << "\n";
    }
}

template <typename T>
void CQuadraticEquation<T>::solve() {
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
    solved = true;
}

template <typename T>
void CQuadraticEquation<T>::displaySolution() {
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





