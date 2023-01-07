#pragma once
#include "coeffs.hpp"
#include "complex.hpp"

class CQuadraticEquation {
public:
    CCoeffs coeffs;
    CComplex S1;
    CComplex S2;

    void ask_input();
    void displayEquation();
    void solve();
    void displaySolution();
};

