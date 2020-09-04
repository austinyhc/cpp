#include <iostream>
#include <type_traits>
#include <array>

template<typename T, int N>
struct Array_type {
    using type = T;
    static const int dim = N;
};

// template<int N>
// struct Integer {
//     using Error = void;
//     using type = Select<N,Error, signed char, short, Error, int, Error, Error, Error, long>;
// };

template<typename T>
class On_heap {
private:
    T* p;
public:
    On_heap() : p{new T} {}
    ~On_heap() { delete p; }

    T& operator*()  { return *p; }
    T* operator->() { return  p; }

    On_heap(const On_heap&) = delete;
    On_heap& operator=(const On_heap&) = delete;
};

template<typename T>
class Scoped {
private:
    T x;
public:
    Scoped() {}

    T& operator*()  { return x; }
    T* operator->() { return &x; }

    Scoped(const Scoped&) = delete;
    Scoped& operator=(const Scoped&) = delete;
};

constexpr int on_stack_max = sizeof(std::string);
template<typename T>
struct Obj_holder {
    using type = typename std::conditional<(sizeof(T)<=on_stack_max),
                                            Scoped<T>,
                                            On_heap<T>
                                          >::type;
    // using type = std::conditional_t<(sizeof(T)<=on_stack_max),
    //                                         Scoped<T>,
    //                                         On_heap<T>
    //                                       >;
};

template<typename T>
using Holder = typename Obj_holder<T>::type;


template<bool B, typename T, typename F>
struct condition {
    using type = T;
};

template<typename T, typename F>
struct condition<false, T, F> {
    using type = F;
};

int main() {
    enum class Axis : char {x, y, z};
    enum Flags {off, x=1, y=x<<1, z=x<<2, t=x<<3};

    typename std::underlying_type<Axis>::type v1;
    typename std::underlying_type<Flags>::type v2;

    using Array = Array_type<int, 5>;
    Array::type aa = 18;
    constexpr int s = Array::dim;

    std::cout << aa << '\n';
    std::cout << s << '\n';

    typename Obj_holder<double>::type v3; // on the stack
    typename Obj_holder<std::array<double, 200>>::type v4; // on the heap

    *v3 = 7.7;
    (*v4)[77] = 9.9;

    Holder<double> v5;
    Holder<std::array<double, 200>> v6;

    return 0;
}
