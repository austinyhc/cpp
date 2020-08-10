#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> values = {3, 5, 1, 4, 2};
    // Use the default comparison function
    //std::sort(values.begin(), values.end());

    // Use the stl std::greater
    //std::sort(values.begin(), values.end(), std::greater<int>());

    // Use the customer defined lambda function
    std::sort(values.begin(), values.end(), [](int a, int b) {
        // Comparison function object which return `true` if the first
        // argument is ordered before the second.
        if (a == 1) return false;
        if (b == 1) return true;
        return a < b;
    });

    for (auto v: values) {
        std::cout << v << std::endl;
    }

    return 0;
}
