#include <iostream>
#include <string>

// When you pass in a class like this, we are actually creating a
// copy of that class, of that object and giving it to the function.
// Copying a class or a std::string in our case here means we have
// to dynamically on the heap allocate a brand new char array to store
// that exact same text we've already got. That is not fast. String copy
// is actually really quite slow comparatively. Always make sure we pass
// in with CONST REFERENCE.
void PrintString(const std::string& name) {
    std::cout << name << std::endl;
}

int main() {
    std::cout << "======== Conventional String(array of char) =========" << std::endl;
    // const char pointer
    const char* name1 = "Austin";
    // Note: Even you remove the const keyword and think now you can mutate the
    // string by indexing the array, but the truth is you cannot or precisely,
    // in C++ it is an undefined behavior, the error it generates really depends
    // on the compiler. The reason it is undefined is because what you've actually
    // done here is you've taken a pointer to the memory location of that `string literal`
    // and a `STRING LITERAL` is stored in a read-only memory segment.
    //char* name1 = "Austin";
    //name1[2] = 'z';

    // const char array
    const char name2[7] = {'A', 'u', 's', 't', 'i', 'n', 0};
    char name3[] = "Austin";

    std::cout << name1 << std::endl;
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;

    std::cout << "============ Start to use std::string ===========" << std::endl;
    std::string name4 = "Austin";
    // in c we would do `strlen(name4)` to calculate the size of string
    std::cout << name4 << " " << name4.size() << std::endl;

    std::string name5 = "Austin";
    name5 += "Hello!";
    bool has_contained = name5.find("fran") != std::string::npos;
    std::cout << (has_contained ? "true" : "false") << std::endl;

    has_contained = name5.find("stin") != std::string::npos;
    std::cout << (has_contained ? "true" : "false") << std::endl;

    std::cout << "============ Pass std::string to a function ===========" << std::endl;
    std::string name6 = "Austin";
    PrintString(name6);

    std::cout << "============ String literal ===========" << std::endl;
    // One thing I can think of the usage of the `wchar_t`, `char16_t` or `char32_t`
    // is to support utf-8, utf-16 and utf-32.
    const wchar_t*  name1_1 = L"Austin";
    const char16_t* name1_2 = u"Austin";
    const char32_t* name1_3 = U"Austin";

    std::cout << name1_1 << std::endl;
    std::cout << name1_2 << std::endl;
    std::cout << name1_3 << std::endl;

    using namespace std::string_literals;
    std::string name7 = "Austin"s + " hello!";
    std::cout << name7 << std::endl;

    return 0;
}
