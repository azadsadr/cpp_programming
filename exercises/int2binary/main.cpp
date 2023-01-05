#include <iostream>


int main() {

    int number;
    // our binary shouldn't have more than 64 digits in 64-bit systems
    int arr[64];
    int counter{0};

    std::cout << "this program converts integer to binary!" << std::endl;
    std::cout << "please enter an integer number:\n";
    std::cin >> number;

    while (number != 0) {
        arr[counter] = number % 2; // remainder of division by 2
        counter = counter + 1;
        number = number / 2;
    }

    // print the array in reverse order
    for (int i=counter-1; i>=0; i--) {
        std::cout << arr[i];
    }
    std::cout << "\n";

    return 0;
}
