#include <iostream>


int main() {

    const int N{5};
    int arr[N];

    std::cout << "this program will sort an array of size " << N << "\n";

    std::cout << "please enter " << N << " integer numbers: ";
    for (int i=0; i<N; i++) {
        std::cin >> arr[i];
    }

    int minVal{0};
    int idx{0};
    for (int i=0; i<N-1; i++) {
        minVal = arr[i];
        idx = i;
        for (int j=i+1; j<N; j++) {
            if (arr[j] < minVal) {
                minVal = arr[j];
                idx = j;
            }
        }
        if (idx != i) {
            std::swap(arr[i], arr[idx]);
        }
    }

    std::cout << "sorted array is:\n";

    for (int i=0; i<N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";


    return 0;
}
