#include <iostream>
#include <utility>
#include <vector>

class NaiveVector {
    int* ptr_ = nullptr;
    size_t size_;
public:
    // Constructor
    NaiveVector()
        : ptr_(nullptr), size_(0) {}

    // A class may have many overload constructors, but there
    // is only ever a single destructor
    ~NaiveVector() { delete[] ptr_; }

    // Copy Constructor
    NaiveVector(const NaiveVector& rhs) {
        ptr_ = new int[rhs.size_];
        size_ = rhs.size_;
        std::copy(rhs.ptr_, rhs.ptr_+size_, ptr_);
    }

    // Move Constructor
    NaiveVector(NaiveVector&& rhs) noexcept {
        // Replaces the value of `rhs.ptr_` with `nullptr` and
        // returns the original `rhs.ptr_`
        ptr_ = std::exchange(rhs.ptr_, nullptr);
        size_ = std::exchange(rhs.size_, 0);
    }

    friend void swap(NaiveVector& a, NaiveVector& b) noexcept {
        a.swap(b);
    }

    void swap(NaiveVector& rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(size_, rhs.size_);
    }

    // NaiveVector& operator=(const NaiveVector& rhs) {
    //     NaiveVector copy = rhs;
    //     copy.swap(*this);
    //     return *this;
    // }
    // NaiveVector& operator=(NaiveVector&& rhs) {
    //     NaiveVector copy(std::move());
    //     copy.swap(*this);
    //     return *this;
    // }

    NaiveVector& operator=(NaiveVector copy) noexcept {
        copy.swap(*this);
        return *this;
    }

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

struct RAIIPtr {
    int* ptr_;
    RAIIPtr(int* p) : ptr_(p) {}
    ~RAIIPtr() { delete [] ptr_; }
    RAIIPtr(const RAIIPtr&) = delete;
    RAIIPtr& operator=(const RAIIPtr&) = delete;
};


class Vec {
    std::vector<int> vec_;
    Vec(const Vec& rhs) = default;
    Vec(Vec&& rhs) = default;
    Vec& operator=(const Vec& rhs) = default;
    Vec& operator=(Vec& rhs) = default;
    ~Vec() = default;

    void swap(Vec &rhs) noexcept {
        vec_.swap(rhs.vec_);
    }

    friend void swap(Vec& a, Vec& b) {
        a.swap(b);
    }
};

int main() {
    // NaiveVector v;
    // v.push_back(1);
    // std::cout << v[0] << '\n';
    // {
    //     NaiveVector w = v;
    // }
    // std::cout << v[0] << '\n';

    // try {
    //     //int* arr = new int[4];
    //     RAIIPtr arr = new int[4];
    //     throw std::runtime_error("for example");
    //     //delete[] arr;
    // } catch(const std::exception& ex) {
    //     std::cout << "Caught an exception: " << ex.what() << '\n';
    // }

    return 0;
}
