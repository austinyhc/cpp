#include<iostream>
#include<string>

class Entity {
private:
    int m_x, m_y;
    // mutable is a keyword so we can still mutate the value
    // in const-ending method
    mutable int m_debug_var;
public:
    // There are three const in the statement, they represent
    //  1. the content of the pointer cannot be modified
    //  2. the address of the pointer cannot be modified
    //  3. the member of the class cannot be modified
    /* const int* const GetX() const { */
    /*     return m_x; */
    /* } */

    int GetX() const  {
        m_debug_var = -1;
        return m_x;
    }
    // Sometimes, you would see there are two versions of
    // getter function with/without const keyword.
    int GetX() {
        return m_x;
    }

    void SetX(int x) {
        m_x = x;
    }
};

void PrintEntity(const Entity& e) {
    // Note: Since we use `const Entity& e`, the class method
    // we call has to have const keyword to indicate it won't
    // mutate its' class element.
    std::cout << e.GetX() << std::endl;
}

int main() {

    // The content that `a` is pointing to is promised to
    // be read-only.
    const int* a = new int;
    //or
    //int const* a = new int;

    // However the promise can be break by mutating the address
    // of the pointer
    const int MAX_AGE = 80;
    a = (int*)&MAX_AGE;

    std::cout << *a << std::endl;
    std::cout << MAX_AGE << std::endl;

    // Uncomment the codes below and see the compile error
    // Basically, we not only promise the content of the pointer to be
    // read-only but also the address of the pointer to read-only
    const int* const b = new int;
    /* *b = 100; */
    /* b = (int*)&MAX_AGE; */

    Entity e;
    e.SetX(20);
    PrintEntity(e);

    return 0;
}
