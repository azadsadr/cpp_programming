#include <iostream>

template <typename T>
T sum(T first) {
    return first;
}

template <typename T, typename... Ts>
T sum(T first, Ts... rest) {
    return first + sum(rest...);
}

int main() {
    int res = sum(1,7,90);
    std::cout << "sum: " << res << "\n";
    return 0;
}
