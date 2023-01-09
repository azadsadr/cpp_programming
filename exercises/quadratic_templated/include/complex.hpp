#pragma once

template <typename T>
class CComplex {
public:
    T real;
    T imag;
    void setValues(T real, T imag);
};

template <typename T>
void CComplex<T>::setValues(T real, T imag) {
    this->real = real;
    this->imag = imag;
}
