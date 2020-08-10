#include <iostream>
#include <string>

struct Vector3 {
    float x, y, z;

    Vector3(): x(12), y(23), z(-21) {};
};

int main() {
    // stack allocation is defintely faster since it is managed by
    // stack pointer rather than a bunch of logic it has in heap
    // allocation, such as searching through and book-keeping the
    // free memory list.
    int value = 5;
    int array[5];
    for (int i{0}; i<5; ++i) {
        array[i] = i+1;
    }
    Vector3 vector;

    int* hvalue = new int;
    int* harray = new int[5];
    Vector3* hvector = new Vector3();

    std::cout << array[0] << std::endl;
    std::cout << vector.x << std::endl;
    return 0;
}
