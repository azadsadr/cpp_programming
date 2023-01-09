#pragma once
#include <iostream>

template <typename T>
class CCoeffs {
public:
    T a;
    T b;
    T c;
    CCoeffs() {
        a = 0;
        b = 0;
        c = 0;
    }
    void setValues(T a, T b, T c);
};

template <typename T>
void CCoeffs<T>::setValues(T a, T b, T c) {
    if (a==0) {
        std::cout << "this is not quadratic equation, terminated!\n";
        exit(1);
    }
    this->a = a;
    this->b = b;
    this->c = c;
}

