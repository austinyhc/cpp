#include <array>
#include <iostream>

using std::cout;
using std::endl;
using std::array;

void Log(int thing) { cout << thing << endl; }

void Increment(int* value) {
    (*value)++;
}

void Increment(int& value) {
    value++;
}

int main(){
    /* int els[2][4] { {1, 2, 3, 4}, {8, 9, 10, 11}}; */
    /* int els[] {1, 2, 3, 4}; */
    /* int elss[2][4] {0}; */

    //std::copy(std::begin(els), std::end(els), std::begin(elss));

    /* for (auto& el: els) { */
    /*     for (auto& e: el) { */
    /*         cout << e << endl; */
    /*     } */
    /* } */

    /* cout << els[0] << endl; */
    /* cout << els[1] << endl; */
    /* cout << std::begin(els) << endl; */
    /* cout << std::end(els) << endl; */
    /* cout << elss << endl; */

    int a = 10;
    Increment(&a);
    Log(a);

    int& ref = a;
    Increment(a);
    Log(a);

    return 0;
}
