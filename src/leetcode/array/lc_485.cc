#include <iostream>
#include <vector>
#include <cmath>

class Solution {

};

int main() {
    std::vector<int> nums {1};

    int count = 0;
    int maxCount = 0;
    for (const auto& n : nums) {
        if (n == 1) ++count;
        else        count = 0;
    }
    maxCount = std::max(maxCount, count);
    // std::cout << maxCount << '\n';

    return 0;
}
