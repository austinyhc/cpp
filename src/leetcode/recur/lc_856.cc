#include <iostream>
#include <cassert>
#include <string>


class Solution {
public:

    int scoreOfParentheses(std::string S) {
        return score(S, 0, S.length()-1);
    }

    void unittest() {
        std::string testcase;

        testcase = "()()";
        assert(scoreOfParentheses(testcase) == 2);

        testcase = "(())()()";
        assert(scoreOfParentheses(testcase) == 4);

        testcase = "(()(()))";
        assert(scoreOfParentheses(testcase) == 6);
    }
private:
    int score(const std::string& S, int l, int r) {
        if (r-l == 1) return 1; // "()"
        int b = 0;
        for (int i{l}; i < r; ++i) {
            if (S[i] == '(') ++b;
            if (S[i] == ')') --b;
            if (b == 0) {
                // score("(A)") + score("(B)(C)")
                return score(S, l, i) + score(S, i+1, r);
            }
        }
        // score("(A)") = 2 * score("A")
        return 2 * score(S, l+1, r-1);
    }
};

int main() {
    Solution solution;
    solution.unittest();

    return 0;
}
