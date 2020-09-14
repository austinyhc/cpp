#include <iostream>
#include <list>

struct ListNode {
    int value = 0;
    ListNode* next = nullptr;

    ListNode()
        : value(0), next(nullptr) {}
    ListNode(int v)
        : value(v), next(nullptr) {}
    ListNode(int v, ListNode* n)
        : value(v), next(n) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // the dummy will be destroyed afterward
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int sum = 0;

        // 3 continue conditions
        //  1. if the 1st linked list has `value`
        //  2. if the 2st linked list has `value`
        //  3. if there is a carry bit to process

        while (l1 || l2 || sum) {
            sum += (l1 ? l1->value : 0) + (l2 ? l2->value : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail->next = new ListNode(sum % 10);
            sum /= 10;
            tail = tail->next;
        }
        // the dummy is like a anchor (at init) and it could
        // be destroyed afterward, as long as we return what
        // we need. Here it's next and the next(s) followed
        // after are created in heap, so it won't disapear if
        // we leave this scope.

        return dummy.next;
    }
};

int main() {
    Solution solution;
    ListNode l1(2, new ListNode(4, new ListNode(3)));
    ListNode l2(5, new ListNode(6, new ListNode(7)));

    auto result = solution.addTwoNumbers(&l1, &l2);

    std::cin.get();

    return 0;
}
