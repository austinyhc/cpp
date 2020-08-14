#include <iostream>

class NonCopyable {
public:
    NonCopyable() {
        std::cout << "NonCopyable" << "\n";
    }
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

// class DynamicVectorBase: public NonCopyable,
//                          public NonConstructible {
// protected:
//     void* mData = nullptr;
//     size_t mSize = 0;
//     size_t mCapacity = 0;
//
//     DynamicVectorBase() = default;
//
//     // DynamicVecotrBase(DynamicVectorBase&& other)
//     //     : mData(other.mData),
//     //       mSize(other.mSize),
//     //       mCapcity(other.mCapacity) {
//     //     other.mData = nullptr;
//     //     other.mSzie = 0;
//     //     other.mCapacitor = 0;
//     // }
// };

// template<typename ObjectType>
// class Singleton: public NonCopyable {
// public:
//     template<typename... Args>
//     static void init(Args&&... args);
//
//     static void deinit();
//     static bool isInitialized();
//     static ObjectType *get();
//     static ObjectType *safeGet();
//
// private:
//     static typename std::aligned_storage<
//         sizeof(ObjectType), alignof(ObjectType)>::type_sObject;
//     static bool sIsInitialized;
// }


class A: public NonCopyable {
// public:
//     A() {
//         std::cout << "A" << "\n";
//     };
};



int main() {
    A a();
    A b();
    std::cout << a << "\n";
    std::cout << b << "\n";
    //a = b;
    return 0;
}
