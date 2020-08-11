#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>

template <size_t T>
int minmax(int depth, int node_index, bool is_max,
        const std::array<int, T>& scores, double height) {

    if (depth == height) {
        return scores[node_index];
    }

    int v1 = minmax(depth + 1, node_index * 2, !is_max, scores, height);
    int v2 = minmax(depth + 1, node_index *2 + 1, !is_max, scores, height);

    return is_max ? std::max(v1, v2) : std::min(v1, v2);
}

int main() {
    std::array<int, 9> scores = {90, 23, 5, 33, 21, 65, 123, 23555, 20};
    double height = log2(scores.size());

    std::cout << "Optimal value: " << minmax(0, 0, true, scores, height) << "\n";
    std::cout << "Optimal value: " << minmax(0, 0, false, scores, height) << "\n";

    return 0;
}
