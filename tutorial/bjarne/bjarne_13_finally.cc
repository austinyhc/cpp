#include <iostream>
#include <cstdlib>

template<typename F>
struct Final_action {
    Final_action(F func) : clean{func} {}
    ~Final_action() { clean(); }
    F clean;

    // Non Copyable
    // Final_action(const Final_action&) = delete;
    // Final_action& operator=(const Final_action&) = delete;
};

template<typename F>
Final_action<F> finally(F func) {
    return Final_action<F>(func);
}

int main() {
    int* p = new int{7};
    int* buf = (int*)malloc(100*sizeof(int));

    // putting the `guard` near the declaration could be a good idea compared
    // to sparsely locates in places.
    auto act1 = finally([&]() {
            delete p;
            free(buf);
            std::cout << "Goodbye, Curel world!" << '\n';
    });

    int var = 0;
    std::cout << "var: " << var << '\n';

    {
        var = 1;
        auto act2 = finally([&]() { std::cout << "Finally!\n"; var = 8; });
        std::cout << "var: " << var << '\n';
    }

    std::cout << "var: " << var << '\n';
    return 0;
}
