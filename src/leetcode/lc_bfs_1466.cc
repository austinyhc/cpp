#include <iostream>
#include <vector>
#include <assert.h>
#include <tuple>
#include <queue>


class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::pair<int,int>>> graph(n); // u-> {v, cost}
        for (auto& edge: connections) {
            graph[edge[0]].emplace_back(edge[1], 1); // u -> v, needs cost
            graph[edge[1]].emplace_back(edge[0], 0); // v -> u, no cost
        }
        int ans = 0;
        std::queue<int> q{{0}};
        std::vector<int> seen(n);

        while(!q.empty()) {
            int current = q.front(); q.pop();
            seen[current] = 1;
            for (const auto& [nxt, cost]: graph[current]) {
                if (seen[nxt]) continue;
                ans += cost;
                q.push(nxt);
            }
        }
        return ans;
    }

    void unittest() {
        std::vector<std::vector<int>> testcase;
        int result = -1;

        /*
         * 4 -> 0 -> 1 -> 3
         *  \-> 5    2 ->/
         *
         * */
        testcase = {{0,1}, {1,3}, {2,3}, {4,0}, {4,5}};
        result = minReorder(6, testcase);
        assert(result == 1);

        testcase = {{1,0}, {1,2}, {3,2}, {3,4}};
        result = minReorder(5, testcase);
        assert(result == 2);

        testcase = {{1,0}, {2,1}};
        result = minReorder(3, testcase);
        assert(result == 0);
    }
};

int main() {
    // std::vector<std::vector<int>> testcase {{0,1}, {1,3}, {2,3}, {4,0}, {4,5}};
    // for (auto& outer: testcase) {
    //     for(auto& inner: outer) {
    //         std::cout << inner << "\n";
    //     }
    // }

    // std::queue<int> q{{0}};
    // std::cout << "Size of q: " << q.size() << "\n";

    Solution sol;
    sol.unittest();

    return 0;
}

