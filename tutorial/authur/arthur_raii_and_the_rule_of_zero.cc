#include <iostream>


class NaiveVector {
    int* ptr_ = nullptr;
    size_t size_;
public:
    NaiveVector()
        : ptr_(nullptr), size_(0) {}
    // A class may have many overload constructors, but there
    // is only ever a single destructor
    ~NaiveVector() { delete[] ptr_; }

    void push_back(int newvalue) {
        int* newptr = new int[size_ + 1];
        std::copy(ptr_, ptr_ + size_, newptr);
        delete[] ptr_;
        ptr_ = newptr;
        ptr_[size_++] = newvalue;
    }

    int& operator[](int index) {
        return this->ptr_[index];
    }
};

int main() {
    NaiveVector v;
    v.push_back(1);
    std::cout << v[0] << '\n';
    // {
    //     NaiveVector w = v;
    // }
    // std::cout << v[0] << '\n';
    return 0;
}
