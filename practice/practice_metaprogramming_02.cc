#include<cmath>
#include<iostream>

#pragma optimize("", off)

// polymorphism
// 1. inheritance -> subtype, run-time, dynamic polymorphism
// 2. templates -> generics, compile-time polymorphism, parametric polymorphism
// 3. overloading -> ad-hoc polymorphism (ad-hoc is Latin -> "for this")
// 4. casting -> coerction polymorphism

template<typename T>
bool Equals(const T& lhs, const T& rhs) {
    return lhs == rhs;
}

template<>
bool Equals<float>(const float& lhs, const float& rhs) {
    std::cout << "Comparing floating number can be buggy!" << '\n';
    return false;
}

template<typename T, typename U>
bool Equals(const T& lhs, const U& rhs) {
    std::cout << "Fuck off!!"  << '\n';
    return false;
}

int main() {
    std::cout << Equals(1, 1) << '\n';
    std::cout << Equals(1.f, 1.f) << '\n';
    std::cout << Equals(1., 1.) << '\n';
    std::cout << Equals(1u, 1u) << '\n';
    std::cout << Equals(1, 1.f) << '\n';

    return 0;
}
