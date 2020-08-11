/*
 * One tatkaway here, for performance improvement, we can always put
 * the fuction that return
 *
 * */

#include <iostream>

using std::cout;
using std::endl;

bool function1(int* arg) {
    cout << "I am function 1 (" << *arg << ")" << endl;
    return true;
}

bool function2() {
    cout << "I am function 2" << endl;
    return true;
}

int main() {
    int* param = nullptr;
    if (param && function1(param) && function2()) {
        cout << "Two functions are true" << endl;
    };
    return 0;
}
