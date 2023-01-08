#include <iostream>

class CComplex {
public:
    double real;
    double imag;
    CComplex(const double& a, const double& b) {
        real = a;
        imag = b;
    }
    CComplex operator + (const CComplex& obj);
    CComplex operator - (const CComplex& obj);
    CComplex operator * (const CComplex& obj);
    CComplex operator / (const CComplex& obj);
    friend std::ostream& operator << (std::ostream& os, const CComplex& obj);
};


std::ostream& operator << (std::ostream& os, const CComplex& obj) {
    if (obj.imag > 0) {
        os << obj.real << " + " << obj.imag << "i\n";
    } else if (obj.imag < 0) {
        os << obj.real << " - " << -obj.imag << "i\n";
    } else {
        os << obj.real << "\n";
    }
    return os;
}


CComplex CComplex::operator + (const CComplex& obj) {
    CComplex result(0,0);
    result.real = real + obj.real;
    result.imag = imag + obj.imag;
    return result;
}


CComplex CComplex::operator - (const CComplex& obj) {
    CComplex result(0,0);
    result.real = real - obj.real;
    result.imag = imag - obj.imag;
    return result;
}

CComplex CComplex::operator * (const CComplex& obj) {
    CComplex result(0,0);
    result.real = real * obj.real - imag * obj.imag;
    result.imag = real * obj.imag + imag * obj.real;
    return result;
}

CComplex CComplex::operator / (const CComplex& obj) {
    CComplex result(0,0);
    result.real = ((real*obj.real)+(imag*obj.imag))/(obj.real*obj.real + obj.imag*obj.imag);
    result.imag = (imag*obj.real - real*obj.imag)/(obj.real*obj.real + obj.imag*obj.imag);
    return result;
}


int main() {
    CComplex c1(2,4);
	CComplex c2(1,6);
	std::cout << "c1: " << c1;
	std::cout << "c2: " << c2;
	std::cout << "c1+c2: " << c1+c2;
	std::cout << "c1-c2: " << c1-c2;
	std::cout << "c1*c2: " << c1*c2;
	std::cout << "c1/c2: " << c1/c2;
    return 0;
}
