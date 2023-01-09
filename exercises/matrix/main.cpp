#include <iostream>
#include <vector>
#include <fstream>

template <typename T>
class CMatrix {
public:
    int size;
    std::vector<T> data;
    CMatrix() {}
    CMatrix(const int& N) {
        size = N;
        data.resize(N*N);
    }
    void importMatrix(const std::string& file);
    void exportMatrix(const std::string& file);
    CMatrix<T> operator * (const CMatrix<T>& B);
    void printMatrix();
};

template <typename T>
void CMatrix<T>::importMatrix(const std::string& file) {

    std::ifstream filevar(file);
    if (filevar) {
        std::cout << "successfully read the file " << file << "\n";
        filevar >> size;
        data.resize(size*size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                filevar >> data.at(i*size+j);
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
    filevar << size << "\n";
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            filevar << data.at(i*size+j) << " ";
        }
        filevar << "\n";
    }
    std::cout << "export matrix to file " << file << "\n";
    filevar.close();
}


template <typename T>
void CMatrix<T>::printMatrix() {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            std::cout << data.at(i*size+j) << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
CMatrix<T> CMatrix<T>::operator * (const CMatrix<T>& mat) {
    if (size != mat.size) {
        std::cout << "two matrices are not same size!\n";
    }
    CMatrix<T> res(size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                res.data.at(i*size+j) += data.at(i*size+k) * mat.data.at(k*size+j);
            }
        }
    }
    return res;
}


int main() {
    CMatrix<int> A, B;
    A.importMatrix("A.txt");
    B.importMatrix("B.txt");
    std::cout << "==============\n";
    std::cout << "Matrix A:\n";
    A.printMatrix();
    std::cout << "Matrix B\n";
    B.printMatrix();
    std::cout << "==============\n";
    auto C = A*B;
    C.exportMatrix("C.txt");
    return 0;
}
