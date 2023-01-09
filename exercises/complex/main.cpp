#include <iostream>

template <typename T>
class CComplex {
public:
    T real;
    T imag;
    CComplex(const T& a, const T& b) {
        real = a;
        imag = b;
    }
    CComplex operator + (const CComplex& obj);
    CComplex operator - (const CComplex& obj);
    CComplex operator * (const CComplex& obj);
    CComplex operator / (const CComplex& obj);
    template <typename V>
    friend std::ostream& operator << (std::ostream& os, const CComplex<V>& obj);
};

template <typename T>
std::ostream& operator << (std::ostream& os, const CComplex<T>& obj) {
    if (obj.imag > 0) {
        os << obj.real << " + " << obj.imag << "i\n";
    } else if (obj.imag < 0) {
        os << obj.real << " - " << -obj.imag << "i\n";
    } else {
        os << obj.real << "\n";
    }
    return os;
}

template <typename T>
CComplex<T> CComplex<T>::operator + (const CComplex<T>& obj) {
    CComplex result(0,0);
    result.real = real + obj.real;
    result.imag = imag + obj.imag;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator - (const CComplex<T>& obj) {
    CComplex<T> result(0,0);
    result.real = real - obj.real;
    result.imag = imag - obj.imag;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator * (const CComplex<T>& obj) {
    CComplex<T> result(0,0);
    result.real = real * obj.real - imag * obj.imag;
    result.imag = real * obj.imag + imag * obj.real;
    return result;
}

template <typename T>
CComplex<T> CComplex<T>::operator / (const CComplex<T>& obj) {
    CComplex<T> result(0,0);
    result.real = ((real*obj.real)+(imag*obj.imag))/(obj.real*obj.real + obj.imag*obj.imag);
    result.imag = (imag*obj.real - real*obj.imag)/(obj.real*obj.real + obj.imag*obj.imag);
    return result;
}


int main() {
    CComplex<double> c1(2,4);
	CComplex<double> c2(1,6);
	std::cout << "c1: " << c1;
	std::cout << "c2: " << c2;
	std::cout << "c1+c2: " << c1+c2;
	std::cout << "c1-c2: " << c1-c2;
	std::cout << "c1*c2: " << c1*c2;
	std::cout << "c1/c2: " << c1/c2;
    return 0;
}
