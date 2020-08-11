#include <iostream>

// https://www.gormanalysis.com/blog/making-a-binary-search-tree-in-cpp/

class Node {
public:
    Node(Node* p, Node* l, Node* r, int32_t v) :
        parent(p), left(l), right(r), value(v)
    {

    }
    ~Node() = default;

    // bool is_locked () {
    //
    // }
    // bool lock () {
    //
    // }
    // bool unlock() {
    //
    // }
private:
    Node* parent = nullptr;
    Node* left   = nullptr;
    Node* right  = nullptr;
    int32_t value;
};

// Design a binary search tree class with
// 1. `is_locked`, which returns whether the node is locked
// 2. true, which attempts to lock the Node. If it cannot be locked, then it should
// return false
class BinarySearchTree {
public:
    BinarySearchTree(int32_t v)
    {
        this->value = v;
    }
    ~BinarySearchTree() = default;

    void insert(int32_t v) {
        if (v < this->value) {
            if (this->left == nullptr) {
                BinarySearchTree* next = new BinarySearchTree(v);
                this->left = next;
                next->parent = this;
            } else {
                this->left->insert(v);
            }
        } else if (v > this->value) {
            if (this->right == nullptr) {
                BinarySearchTree* next = new BinarySearchTree(v);
                this->right = next;
                next->parent = this;
            } else {
                this->right->insert(v);
            }
        }
    }

    BinarySearchTree* parent = nullptr;
    BinarySearchTree* left   = nullptr;
    BinarySearchTree* right  = nullptr;
    int32_t value;
};

int main() {
    BinarySearchTree* tree = new BinarySearchTree(12);
    tree->insert(10);
    tree->insert(8);
    std::cout << tree->left->left->value << std::endl;

    return 0;
}
