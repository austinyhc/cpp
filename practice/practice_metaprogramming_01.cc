#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace ch22 {
    using std::vector;

    template<class T, class Op>
    void apply(vector<T>& src, Op f) {
        std::transform(src.begin(), src.end(), src.begin(), f);
    }

    template<class T>
    struct Incr {
        T operator()(const T& x) { return x + 1; }
    };
}

int main() {
    using namespace std;
    using namespace ch22;

    vector<int> va {1, 2, 3, 4, 5, 10};
    apply(va, Incr<int>());
    copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}
