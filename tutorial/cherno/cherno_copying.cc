#include<iostream>
#include<string>
#include<cstring>

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size];
        memcpy(m_Buffer, string, m_Size);

    }
    // copy construtor
    String(const String& other): m_Buffer(other.m_Buffer), m_Size(other.m_Size) {
        std::cout << "Copied String" << std::endl;
        m_Buffer = new char[m_Size];
        memcpy(m_Buffer, other.m_Buffer, m_Size);
    };
    // If we want to disable the copy constructor
    // String(const String& other) = delete;

    ~String() {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string) {
        stream << string.m_Buffer;
        return stream;
    }
};

// Two reason to rewrite the parameters
// 1. we don't need to pass-by-value because it is rediculous to run
// again and again when calling the PrintString function. We should use
// pass-by-reference.
// 2. Since we won't mutate the `string` we can declare it as const
//void PrintString(String string) {
void PrintString(const String& string) {
    std::cout << string << std::endl;
}

int main() {
    String user1 = "Austin";
    String user2 = user1;

    user1[0] = 'O';
    user2[1] = 'z';

    PrintString(user1);
    PrintString(user2);

    /* std::cout << user1 << std::endl; */
    /* std::cout << user2 << std::endl; */

    return 0;
}
