#pragma once
#include "coeffs.hpp"
#include "complex.hpp"


class CQuadraticEquation {
public:
    CCoeffs coeffs;
    CComplex S1;
    CComplex S2;
    bool solved{false};

    void ask_input();
    void read_from_file();
    void write_to_file();
    void displayEquation();
    void solve();
    void displaySolution();
};

