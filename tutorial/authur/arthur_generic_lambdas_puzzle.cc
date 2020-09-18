#include <iostream>
#include <assert.h>
#include <string>


// Lambdas reduce boilerplate
class Plus {
    int value;
public:
    Plus(int v): value(v) {}
    int operator() (int x) const {
        return x + value;
    }
};

// this is identical with the above-defined class Plus
auto plus = [value=1](int x) { return x+value; };

auto GOOD_increment_by(int y) {
    return [=](int x) { return x+y; };
}

auto BAD_increment_by(int y) {
    return [&](int x) { return x+y; };
}

int main() {
    assert(plus(42) == 43);

    auto c_plus = Plus(1);
    assert(c_plus(42) == 43);

    std::string prop = "Austin";
    auto pless = [&]() {
        std::cout << prop << "\n";
    };
    pless();

    auto plus5 = GOOD_increment_by(5);
    int seven = plus5(2);
    std::cout << "I am GOOD: " << seven << "\n";

    auto _plus5 = BAD_increment_by(5);
    int _seven = _plus5(2);
    std::cout << "I am BAD: " << _seven << "\n";

    return 0;
}
