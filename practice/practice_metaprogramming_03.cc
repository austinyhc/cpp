#include <iostream>
#include <type_traits>

using namespace std;

// tag dispatch
// SFINAE -> Substitution Failure is not an error

template<typename T>
bool Equals(T lhs, T rhs) {
    // std::cout << conditional_t<is_floating_point<T>::value, true_type, false_type>{} << '\n';
    // typename std::conditional<is_floating_point<T>::value,
    //                                        true_type,
    //                                        false_type
    //                                       >::type;
    return Equals(lhs, rhs, typename conditional<is_floating_point<T>(),
                                           true_type,
                                           false_type
                                          >::type);
}

template<typename T>
bool Equals(T lhs, T rhs, const true_type) { // floating
    return true;
}

template<typename T>
bool Equals(T lhs, T rhs, const false_type) { // non-floating
    return lhs == rhs;
}

int main() {
    std::cout << Equals(1.f, 1.f) << '\n';
    // std::cout << Equals(1.f, 1.f) << '\n';
    // std::cout << Equals(1., 1.) << '\n';
    // std::cout << Equals(1u, 1u) << '\n';

    return 0;
}
