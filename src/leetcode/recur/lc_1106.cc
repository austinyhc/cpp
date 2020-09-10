#include <iostream>
#include <string>

class Solution {
public:
    bool parseBoolExpr(std::string expression) {
        int s = 0;
        return parse(expression, s);
    }

private:
    bool parse(const std::string& expr, int& i) {
        char c = expr[i++];
        if (c == 't') return true;
        if (c == 'f') return false;
        if (c == '!') {
            bool ans = !parse(expr, ++i);
            ++i;
            return ans;
        }
        // if (c == '|' || c == '&')
        bool is_and = (c == '&');
        bool ans = is_and;
        ++i;
        while (true) {
            if (is_and) ans &= parse(expr, i);
            else ans |= parse(expr, i);

            if (expr[i++] == ')') break;
        }
        return ans;
    }
};


int main() {
    Solution solution;
    std::cout << solution.parseBoolExpr("|(&(t,f,t),!(t))") << '\n';
    return 0;
}
