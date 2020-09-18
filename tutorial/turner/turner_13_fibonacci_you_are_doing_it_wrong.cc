#include <iostream>

int fib(int val) {
// constexpr int fib(int val) {
    if (val == 0) { return 0; }
    if (val == 1) { return 1; }
    return fib(val-2) + fib(val-1);
}

// template<int I>
// struct Fib {
//     static const int val = Fib<I-1>::val + Fib<I-2>::val;
// };
//
// template<>
// struct Fib<0> {
//     static const int val = 0;
// };
//
// template<>
// struct Fib<1> {
//     static const int val = 1;
// };

int main() {
    std::cout << fib(45) << '\n';
    // std::cout << Fib<45>::val << '\n';
    return 0;
}
