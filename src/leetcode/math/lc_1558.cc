#include <iostream>
#include <assert.h>
#include <vector>
#include <math.h>
#include <bitset>

// #9 -> 1001
//  0b1001 | 0b0001 = 0b1001
//
//  (#1, #5)  -> (0b1, 0b101)
//            ->  1+0+2+2 = 5

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int ans = 0;
        int high = 0;
        for (int x: nums) {
            high = std::max(high, 31 - __builtin_clz(x|1));
            ans += std::bitset<32>(x).count();
        }

        return ans + high;
    }

    void unittest() {
        std::vector<int> testcase;
        static int result;

        testcase = {1, 5};
        result = minOperations(testcase);
        std::cout << result << '\n';
        assert(result == 5);
    }
};

int main() {
    Solution sol;
    sol.unittest();

    std::cout << __builtin_clz(1) << '\n';
    return 0;
}


