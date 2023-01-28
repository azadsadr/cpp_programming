#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
struct CCoords {
    T x, y;
    CCoords() {
        x = 0;
        y = 0;
        std::cout << "CCoords constructor called!\n";
    }
    void setValues(const T& x0, const T& y0) {
        x = x0;
        y = y0;
    }
    void printCoords() {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

template <typename T>
T distance(CCoords<T> c1, CCoords<T> c2) {
    return std::sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y));
}

template <typename T>
class CShape {
public:
    virtual T perimeter() = 0;
    virtual void print_vertices() = 0;
    virtual ~CShape() {};
};

template <typename T>
class CTriangle : public CShape<T> {
public:
    CCoords<T> c1, c2, c3;
    CTriangle(const std::vector<T>& myvertices);
    T perimeter() override;
    void print_vertices() override;
};

template <typename T>
CTriangle<T>::CTriangle(const std::vector<T>& myvertices) { // check
    if (myvertices.size() == 6) {
        c1.setValues(myvertices[0], myvertices[1]);
        c2.setValues(myvertices[2], myvertices[3]);
        c3.setValues(myvertices[4], myvertices[5]);
        std::cout << "CTriangle constructor called!\n";
    } else {
        std::cout << "this is not a triangle! use polygon instead.\n";
        exit(1);
    }
}

template <typename T>
T CTriangle<T>::perimeter() {
    return distance(c1, c2) + distance(c1, c3) + distance(c2, c3);
}

template <typename T>
void CTriangle<T>::print_vertices() {
    std::cout << "the triangle coordinates are:\n";
    c1.printCoords();
    c2.printCoords();
    c3.printCoords();
}

template <typename T>
class CPolygon : public CShape<T> {
public:
    CCoords<T>* vertices;
    int Nv;
    CPolygon(const std::vector<T>& myvertices);
    T perimeter() override;
    void print_vertices() override;
    ~CPolygon() {
        std::cout << "polygon destructor called!\n";
        delete[] vertices;
    }
};

template <typename T>
CPolygon<T>::CPolygon(const std::vector<T>& myvertices) {
    Nv = myvertices.size()/2;
    vertices = new CCoords<T>[Nv];
    for (int i = 0; i < Nv; i++) {
        vertices[i].setValues(myvertices[2 * i], myvertices[2 * i + 1]);
    }
    std::cout << "CPolygon constructor called!\n";
}

template <typename T>
T CPolygon<T>::perimeter() {
    T result{0};
    for (int i = 0; i < Nv - 1; i++) {
        result += distance(vertices[i], vertices[i + 1]);
    }
    result += distance(vertices[0], vertices[Nv - 1]);
    return result;
}

template <typename T>
void CPolygon<T>::print_vertices() {
    std::cout << "the polygon coordinates are:\n";
    for (int i = 0; i < Nv; i++) {
        vertices[i].printCoords();
    }
}

int main() {

    CTriangle<double> tr({0, 0, 1, 0, 1, 1});
    CShape<double>* shape1 = &tr;
    std::cout << "triangle perimeter: " << shape1->perimeter() << "\n";
    shape1->print_vertices();

    std::cout << "\n";

    CPolygon<double> pol({0, 0, 1, 0, 1, 1, 0, 1});
    CShape<double> *shape2 = &pol;
    std::cout << "polygon perimeter: " << shape2->perimeter() << "\n";
    shape2->print_vertices();

    return 0;
}
