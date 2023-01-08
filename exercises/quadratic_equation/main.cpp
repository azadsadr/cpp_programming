#include <iostream>
#include "include/quad.hpp"

int main() {

    std::cout << "this program solves a quadratic equation." << std::endl;

    CQuadraticEquation eq;
    eq.ask_input();
    eq.displayEquation();
    eq.solve();
    eq.displaySolution();

    return 0;
}
