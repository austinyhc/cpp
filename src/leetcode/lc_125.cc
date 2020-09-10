#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            while (i < j && !std::isalnum(s[i])) ++i;
            while (i < j && !std::isalnum(s[j])) --j;

            if (std::tolower(s[i++]) != std::tolower(s[j--]))
                return false;
        }
        return true;
    }

    void unittest() {
        std::string testcase;

        testcase = "abac";
        assert(isPalindrome(testcase) == false);

        testcase = "A man, a plan, a canal: Panama";
        assert(isPalindrome(testcase) == true);

        testcase = "Red rum, sir, is murder";
        assert(isPalindrome(testcase) == true);

        testcase = "The sower Arepo holds the wheels with effore";
        assert(isPalindrome(testcase) == false);
    }
};

int main() {
    Solution solution;
    solution.unittest();
    return 0;
}
