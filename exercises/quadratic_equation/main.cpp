#include <iostream>
#include "include/quad.hpp"

int main() {

    std::cout << "this program solves a quadratic equation." << std::endl;

    CQuadraticEquation eq;
    //eq.ask_input();
    eq.read_from_file();
    eq.displayEquation();
    eq.solve();
    eq.displaySolution();
    eq.write_to_file();

    return 0;
}
