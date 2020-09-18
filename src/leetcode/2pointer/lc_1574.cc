#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

class Solution {
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr) {
        const int n = arr.size();
        int j = n - 1;
        while (j > 0 && arr[j-1] < arr[j]) --j;
        if (j == 0) return 0;

        std::cout << j << '\n';

        int ans = j-1;
        for (int i{0}; i < j; ++i) {
            if (i > 0 && arr[i-1] > arr[i]) break;
            while (i > 0 && arr[i] > arr[j]) ++j;
            ans = std::min(ans, j-i-1);
        }
        std::cout << ans << '\n';
        return ans;
    }

    void unittest() {
        /* Do nothing */
        std::vector<int> testcase;

        testcase = {1,2,3,10,4,2,3,5};
        assert(findLengthOfShortestSubarray(testcase)==3);
    }
};


int main() {
    Solution solution;
    solution.unittest();
    return 0;
}
