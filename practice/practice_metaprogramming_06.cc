#include <iostream>
#include <array>
#include <algorithm>

template<typename T, typename U>
void foo(std::array<T, sizeof(U)> x,
         std::array<U, sizeof(T)> y,
         int z) {
    puts(__PRETTY_FUNCTION__);
}

template<typename T, typename U>
void add(T x, U y) {
    puts(__PRETTY_FUNCTION__);
}

int main() {
    // foo(std::array<int, 8>{}, std::array<double, 4>{}, 0.0);
    // foo(std::array<int, 9>{}, std::array<double, 4>{}, 0.0);

    add<int, int>('x', 3.1);
    add<int>('x', 3.1);
    add<>('x', 3.1);
    add('x', 3.1);

    return 0;
}
