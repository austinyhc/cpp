#include <iostream>
#include <vector>
#include <functional>

typedef int (*somefunc)(int, int);

int product(int x, int y) {
    return x*y;
}

// If we use the raw function pointer of course it fails when using the
// lambda capture since it is new to cpp::functional libraray
// void forEach(const std::vector<int>& values, void(*func)(int)) {
void forEach(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value: values) {
        func(value);
    }
}

void helloWorld() {
    std::cout << "Hello World" << std::endl;
}

std::vector<int> filter(const std::vector<int>& values, const std::function<bool(int)>& func) {
    std::vector<int> result;
    for (auto value: values) {
        if (func(value)) {
            result.push_back(value); }
    }
    return result;
}
// Can I rewirte this to the a iterator version

int main() {
    std::cout << "============ Function Pointer Basics ==========" << std::endl;
    somefunc naiveProduct = &product;
    int result = (*naiveProduct)(2, 4);
    std::cout << result << std::endl;

    std::cout << "============ Lambda function Basics ===========" << std::endl;

    // Lambda function is an anonymous function
    // Lambda gives you ability to create a funtion without actually create a function
    std::vector<int> values = {1, 2, 5, 7, 8, 12};
    forEach(values, [](int x){ std::cout << x << std::endl; });

    std::cout << "========= Lambda function::Captures ===========" << std::endl;
    int a = 8;
    // Eitehr you can use = for passing by value (making a copy)
    // or & for passing by reference if you don't want to make a copy of
    // a class or an object that consumes a big chunk of memory.
    auto lambda = [=](int x) { std::cout << "Value: " << a << std::endl; };
    forEach(values, lambda);

    // Something very trivial and probably not much being seen in real-life application,
    // which also being mentioned in the mutatable keyword tutorial. If we want to mutate
    // the captured variable in lambda function, we need to add the mutate keyword.

    // Error because the captured variables in lambda are default read-only (ro)
    //auto lambda_ro = [=](int x) { a = 6; std::cout << "Value: " << a << std::endl; };
    //std::cout << "Value: " << a << std::endl;
    //forEach(values, lambda_rw);

    // If we want to mutate it, we need to add `mutable` keyword to the function.
    // Try both & and = keyword, and guess what the value will be outside of the lambda function.
    auto lambda_rw = [=](int x) mutable { a = 6; std::cout << "Value: " << a << std::endl; };
    //auto lambda_rw = [&](int x) mutable { a = 6; std::cout << "Value: " << a << std::endl; };
    std::cout << "Value: " << a << std::endl;
    forEach(values, lambda_rw);
    std::cout << "Value after mutate by lambda_rw: " << a << std::endl;

    std::cout << "========= std::find_if with lambda ============" << std::endl;
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
    std::cout << *it << std::endl;

    std::cout << std::endl << "========= Extented self-study question =========" << std::endl;
    // We are having the ability to pick up the first element that fullfill the condition
    // defined as a lambda function, it makes me wonder maybe I can implement a filter
    // function as most of high level language library does have.
    auto filter_result = filter(values, [&](int x){ return x > 2;});
    for (auto fr: filter_result) {
        std::cout << fr << std::endl;
    }

    return 0;
}
