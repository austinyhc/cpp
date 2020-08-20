#include <iostream>
#include <math.h>
#include <string>
#include <assert.h>

// 7 -> 2 base -> 0b111
// 7 % 2 = 1; 7 / 2 = 3;
// 3 % 2 = 1; 3 / 2 = 1;
// 1 % 2 = 1; 1 / 2 = 0;

class Solution {
public:
    std::string convertToBase7(int num) {
        int isNegative = num < 0;
        int numAbs = std::abs(num);
        std::string result = "";

        while(numAbs) {
            result.insert(0, std::to_string(numAbs % 7));
            numAbs = floor(numAbs / 7);
        }
        if (isNegative) {
            result.insert(0, "-");
        }

        return result;

    }

};

int main() {

    // int x = 8;
    // std::string result = "";
    // std::cout << result.append(std::to_string(x % 7)) << "\n";

    Solution sol;
    assert(sol.convertToBase7(100) == "202");
    assert(sol.convertToBase7(-7) == "-10");

    return 0;
}
