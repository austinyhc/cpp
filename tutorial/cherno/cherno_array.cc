#include <iostream>
#include <array>

template<typename T, size_t S>
class Array
{
public:
    constexpr int Size() const { return S; }
    T& operator[](int index) { return m_Data[index]; }
private:
    T m_Data[S];
};

class Entity
{
public:
    static const int size = 5;
    int data[size];

    Entity() {
        for (int i{0}; i < 5; ++i) {
            data[i] = 18;
        }
    }
};

int main()
{
    // In this tutorial, Cherno introduces two different ways declaring
    // an array, even the data structure are the same, the array, but the
    // lifecycle and in where of the memory they live are totally different,
    // statck vs heap and destroy once it leaves out of scope vs destroy
    // until manually call destroy.
    int examples[5] {0};

    for (auto ex: examples) {
        std::cout << ex << std::endl;
    }

    int* another = new int[5];

    for (int i{0}; i < 5 ; ++i) {
        another[i] = 2;
    }
    std::cout << another[1] << std::endl;

    Entity e;
    for (auto data: e.data) {
        std::cout << data << std::endl;
    }

    int size = 8;
    Array<int, 8> data;
    static_assert(data.Size() < 10, "Size is too large");
    std::cout << data.Size() << std::endl;
    std::cout << data[0] << std::endl;

    return 0;
}
