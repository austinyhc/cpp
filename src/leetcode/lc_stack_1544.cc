#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::string ans;

        for (auto c: s) {
            //std::cout << c << "\n";
            if (!ans.empty() &&
                std::abs(ans.back()-c) == std::abs('A' - 'a')) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        //std::cout << ans << "\n";
        return ans;
    }

    void unittest() {
        assert(makeGood("apPle") == "ale");
        assert(makeGood("apple") == "apple");
        assert(makeGood("LeeEecode") == "Leecode");
        assert(makeGood("abBACc") == "");
    }
};

int main() {
    Solution sol;
    sol.unittest();

    return 0;
}

