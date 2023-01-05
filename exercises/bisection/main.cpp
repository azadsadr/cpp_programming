#include <iostream>

double func(double& x) {
    return x*x*x - 6*x*x + 11*x - 6;
}

int main() {

    double a{-10};
    double b{10};
    double m{0};
    double t{1e-9};

    while (std::abs(b-a) >= t) {
        double fa{func(a)};
        double fb{func(b)};

        if (std::abs(fa) < t) {
            m=a;
            break;
        } else if (std::abs(fb) < t) {
            m=b;
            break;
        }

        // actual bisection
        if (fa*func(m) < 0) {
            std::cout << "[a, m] selected!\n";
            b = m;
        } else if (func(m)*fb < 0) {
            std::cout << "[m, b] selected!\n";
            a = m;
        } else {
            std::cout << "bisection won't work in this interval, function has the same signs at both ends!\n";
            exit(1);
        }
        m = (a+b)/2;
    }

    std::cout << "the root is close to: " << m << "\n";
    return 0;
}
