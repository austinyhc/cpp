#include <iostream>
#include <list>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x), next(nullptr) {}
};

class Solution {
public:
    bool detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) true;
        }
        return false;
    }

    void unittest() {
        ListNode* testcase = new ListNode(3);
        testcase->next = new ListNode(2);
        testcase->next->next = new ListNode(0);
        testcase->next->next->next = new ListNode(-4);
        testcase->next->next->next->next = testcase->next;
        assert(detectCycle(testcase) == true);

        ListNode* testcase1 = new ListNode(1);
        assert(detectCycle(testcas1) == false);

        ListNode* testcase2 = new ListNode(1);
        testcase2->next = new ListNode(2);
        testcase2->next->next = testcase2;
        assert(detectCycle(testcase2) == true);
    }
};

int main() {
    std::cout << "aloha loha" << '\n';
    Solution solution;
    solution.unittest();
    return 0;
}
