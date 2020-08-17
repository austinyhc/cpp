#include <iostream>
#include <array>

int fib_recr(int value) {
    if (value <= 0) { return 0; }
    if (value == 1 || value == 2) { return 1; }
    return fib_recr(value-2) + fib_recr(value-1);
}

template <size_t N>
void fib_iter(std::array<int, N>& values) {
    values[0] = 0;
    values[1] = 1;

    for (uint16_t i{2}; i < values.size(); ++i) {
        values[i] = values[i-1] + values[i-2];
    }
}

int main() {
    constexpr int N = 12;

    int result {0};
    result = fib_recr(N);

    std::array<int, N> sequence = {0};
    fib_iter(sequence);

    std::cout << result << "\n";
    std::cout << sequence.back() << "\n";
    return 0;
}
