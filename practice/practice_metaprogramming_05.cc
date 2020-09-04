#include <iostream>
#include <string>
#include <type_traits>

template<typename... T>
struct Tuple {};

template<typename T, typename... Rest>
struct Tuple<T, Rest...> {
    T x;
    Tuple<Rest...> rest;

    Tuple(const T& t, const Rest& ... r)
        : x(t), rest(r...) {}
};

// template<size_t idx,
//          template<typename...> class Tuple,
//          typename... Args
//         >
// auto get(Tuple<Args...>& t) {
//     return GetHelper<idx, Tuple<Args...>>::get(t);
// }

int main() {
    Tuple<bool> t1(false);
    Tuple<int, char, std::string> t2 {2500, 'a', "Austin"};
    return 0;
}
