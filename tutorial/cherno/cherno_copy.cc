#include <iostream>
#include <cstring>

class String {
public:
    String(const char* s)
    {
        std::cout << "Created!" << std::endl;
        mSize = strlen(s);
        mData = new char[mSize];
        memcpy(mData, s, mSize);
    }

    // We need a copy constructor
    String(const String& other)
    {
        std::cout << "Copied!" << std::endl;
        mSize = strlen(other.mData);
        mData = new char[mSize];
        memcpy(mData, other.mData, mSize);
    }

    String(String&& other) noexcept
    {
        std::cout << "Moved!" << std::endl;
        mSize = other.mSize;
        mData = other.mData;

        other.mSize = 0;
        other.mData = nullptr;
    }

    ~String()
    {
        std::cout << "Destoryed!" << std::endl;
        delete mData;
    }

    void Print() {
        std::cout << mData << std::endl;
    }

private:
    char* mData;
    uint32_t mSize;
};

// Add another class to consume the String class
class Entity {
public:
    // Note: we need a copy constructor to make `mName(name)` this happened
    Entity(const String& name)
        : mName(name) {}

    Entity(String&& name)
        //: mName((String&&)name) {}
        : mName(std::move(name)) {}

    void Print() {
        mName.Print();
    }

private:
    String mName;
};


int main() {

    Entity mEntity("Oztin");
    mEntity.Print();

    return 0;
}
