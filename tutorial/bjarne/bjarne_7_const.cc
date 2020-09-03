#include <iostream>

int main() {
    char s[] = "Austin";
    char t[] = "Fran";
    s[0] = 'O';
    std::cout << s << '\n';

    // pc: pointer to const
    const char* pc = s;
    s[1] = 'F';
    //Fail *(pc+2) = 'z';
    std::cout << pc << '\n';

    // cp: const pointer
    char* const cp = s;
    cp[0] = 'a';
    std::cout << cp << '\n';
    //Fail cp = t;

    // cpc; const pointer to const data
    const char* const cpc = s;
    //cpc[3] = 'R';
    //Fail cpc = t;

    const int constant = 8;
    int variable = 19;

    const int* pci = &variable;
    int* pi = &variable;
    std::cout << *pci << ' ' << *pi << '\n';

    pci = &constant;
    // It is not allow to assign a const to a pointer
    // that points to non-const data.
    pi = &constant;

    return 0;
}
