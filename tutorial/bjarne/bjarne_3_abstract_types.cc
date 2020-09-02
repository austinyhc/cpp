#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>

class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

class Vector {
private:
    double* _elements;
    int _size;
public:
    Vector(int s)
        : _elements{new double[s]}, _size{s}
    {
        for (int i{0}; i!=s; ++i) _elements[i] = 0;
    }
    ~Vector()
    {
        delete[] _elements;
    }

    double& operator[](int i) { return _elements[i]; };
    int size() const { return _size; };
};

class Vector_container: public Container {
private:
    Vector v;
public:
    Vector_container(int s) : v(s) {}
    ~Vector_container() {}

    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

class List_container: public Container {
private:
    std::list<double> ld;
public:
    List_container(std::initializer_list<double> il) : ld{il} {}
    ~List_container() {}

    double& operator[](int i);
    int size() const { return ld.size(); }
};

double& List_container::operator[](int i) {
    for (auto& x: ld) {
        if (i==0) return x;
        --i;
    }
    throw std::out_of_range("List container");
}

void use(Container& c) {
    const int sz = c.size();
    for (int i{0}; i!=sz; ++i) {
        std::cout << c[i] << '\n';
    }
}

int main() {
    Vector_container vc(10);
    use(vc);

    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8};
    use(lc);
    return 0;
}
