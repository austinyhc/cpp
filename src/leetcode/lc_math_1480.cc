#include <iostream>
#include <vector>
#include <assert.h>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (size_t i{1}; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        return nums;
    }

    void unittest() {
        std::vector<int> testcase;
        std::vector<int> expected;

        testcase = {1,2,3,4};
        expected = {1,3,6,10};

        assert(runningSum(testcase) == expected);

        testcase = {1,1,1,1,1};
        expected = {1,2,3,4,5};
        assert(runningSum(testcase) == expected);

        testcase = {3,1,2,10,1};
        expected = {3,4,6,16,17};
        assert(runningSum(testcase) == expected);
    }
};

int main() {
    Solution sol;
    sol.unittest();

    return 0;
}
