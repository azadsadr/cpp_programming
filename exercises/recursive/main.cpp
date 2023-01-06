#include <iostream>


int factorial(const int N) {
    if (N==0 | N==1) {
        return 1;
    }
    return N*factorial(N-1);
}


int main(int argc, char** argv) {

    // convert the first element of the command-line arguments to integer
    int n = atoi(argv[1]);
    int res;

    res = factorial(n);
    std::cout << "factorial of " << n << " is " << res << "\n";

    return 0;
}
