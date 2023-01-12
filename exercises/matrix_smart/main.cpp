#include <iostream>
#include <vector>
#include <fstream>
#include <memory>


template <typename T>
class CMatrix {
public:
    int size;
    std::unique_ptr<T[]> data;

    CMatrix();                                      // default constructor
    CMatrix(const int& N);                          // parameterized constructor
    CMatrix(const CMatrix<T>& obj);                 // copy constructor
    CMatrix<T>& operator = (const CMatrix<T>& obj); // copy assignment operator
    CMatrix(CMatrix<T>&& obj);                      // move constructor
    CMatrix<T>& operator = (CMatrix<T>&& obj);      // move assignment operator
    //~CMatrix();                                     // destructor

    void importMatrix(const std::string& file);
    void exportMatrix(const std::string& file);
    void printMatrix();
    CMatrix<T> operator * (const CMatrix<T>& B);
};


// default constructor
template<typename T>
CMatrix<T>::CMatrix() {
    size=0;
    data.reset(nullptr);
    std::cout << "default constructor called!\n";
}

// parameterized constructor
template <typename T>
CMatrix<T>::CMatrix(const int& N) {
    size = N;
    if (N>0) {
        data = std::make_unique<T[]>(size*size);
    } else {
        data.reset(nullptr);
    }
    std::cout << "parameterized constructor called!\n";
}

// copy constructor
template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& obj) {
    size = obj.size;
    if (obj.data == nullptr) {
        data.reset(nullptr);
    } else {
        data = std::make_unique<T[]>(size*size);
        for (int i=0; i<size*size; i++) {
            data[i] = obj.data[i];
        }
    }
    std::cout << "copy constructor called!\n";
}

// copy assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator = (const CMatrix<T>& obj) {
    if (this != &obj) {
        size = obj.size;

        if (data != nullptr) {
            //delete[] data;
            data.reset(nullptr);
        }

        if (obj.data != nullptr) {
            data = std::make_unique<T[]>(size*size);
            for (int i=0; i<size*size; i++) {
                data[i] = obj.data[i];
            }
        } else {
            data.reset(nullptr);
        }
    }
    std::cout << "copy assignment operator called!\n";
    return *this;
}

// move constructor
template <typename T>
CMatrix<T>::CMatrix(CMatrix<T>&& obj) {
    if (this != &obj) {
        size = obj.size;
        obj.size = 0;
        data = std::move(obj.data);
        obj.data.reset(nullptr);
    }
    std::cout << "move constructor called!\n";
}


// move assignment operator
template <typename T>
CMatrix<T>& CMatrix<T>::operator = (CMatrix<T>&& obj) {
    if (this != &obj) {
        size = obj.size;
        obj.size = 0;
        data = std::move(obj.data);
        obj.data = nullptr;
    }
    std::cout << "move assignment operator called!\n";
    return *this;
}

/* destructor
template <typename T>
CMatrix<T>::~CMatrix() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    std::cout << "destructor called!\n";
}
*/


template <typename T>
void CMatrix<T>::importMatrix(const std::string& file) {

    std::ifstream filevar(file);
    if (filevar) {
        std::cout << "successfully read the file " << file << "\n";
        filevar >> size;
        data = std::make_unique<T[]>(size*size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                filevar >> data[i*size+j];
            }
        }
        filevar.close();
    } else {
        std::cout << "couldn't open the file " << file << "\n";
        exit(1);
    }
}

template <typename T>
void CMatrix<T>::exportMatrix(const std::string& file) {
    std::ofstream filevar(file);
    if (filevar) {
        filevar << size << "\n";
        if (data != nullptr) {
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    filevar << data[i*size+j] << " ";
                }
                filevar << "\n";
            }
            filevar.close();
            std::cout << "export matrix to file " << file << "\n";
        } else {
            std::cout << "matrix is null, nothing to export!\n";
        }
    } else {
        std::cout << "unable to export the matrix to file!\n";
    }
}


template <typename T>
void CMatrix<T>::printMatrix() {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            std::cout << data[i*size+j] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
CMatrix<T> CMatrix<T>::operator * (const CMatrix<T>& mat) {
    if (size != mat.size) {
        std::cout << "two matrices are not same size, result is nonsense!\n";
    }
    CMatrix<T> res(size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                res.data[i*size+j] += data[i*size+k] * mat.data[k*size+j];
            }
        }
    }
    return res;
}



int main() {

    CMatrix<double> A, B;
    std::cout << "matrix A and B created\n";
    std::cout << "==============\n";
    A.importMatrix("A.txt");
    B.importMatrix("B.txt");
    std::cout << "==============\n";
    std::cout << "Matrix A:\n";
    A.printMatrix();
    std::cout << "Matrix B\n";
    B.printMatrix();
    std::cout << "==============\n";
    auto C = A*B;
    std::cout << "Matrix C = A*B:\n";
    C.printMatrix();
    C.exportMatrix("C.txt");
    std::cout << "==============\n";
    std::cout << "C = A:\n";
    C = A;
    C.printMatrix();
    std::cout << "==============\n";
    std::cout << "CMatrix<double> D(A):\n";
    CMatrix<double> D(A);
    D.printMatrix();
    std::cout << "==============\n";
    std::cout << "C = std::move(A)\n";
    C = std::move(A);
    C.printMatrix();
    std::cout << "==============\n";
    std::cout << "Matrix A:\n";
    A.printMatrix();
    std::cout << "==============\n";

    return 0;
}
