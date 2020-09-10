#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctype>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string S) {
        std::vector<std::string> ans;
        dfs(S, 0, ans);
        return ans;
    }

    void unittest() const {


    }
private:
    void dfs(std::string& S, int i, std::vector<std::string>& ans) {
        if (i == S.length()) {
            ans.push_back(S);
            return;
        }
        dfs(S, i+1, ans);
        if (!std::isalpha(S[i])) return;
        S[i] ^= (1 << 5);
        dfs(S, i+1, ans);
        S[i] ^= (1 << 5);
    }
};


int main() {
    Solution solution;
    solution.unitest();

    return 0;
}
