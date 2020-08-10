#include <iostream>
#include <string>
#include <vector>


struct Vertex {
    float _x, _y, _z;
    Vertex(float x, float y, float z)
        : _x(x), _y(y), _z(z)
    {

    }

    Vertex(const Vertex& vertex)
        : _x(vertex._x), _y(vertex._y), _z(vertex._z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

// void PrintVertex(const std::vector<Vertex&> v) {
//     std::cout << v.std::endl;
// }

int main() {
    std::vector<Vertex> vertices;

    // vertices.push_back(Vertex(1, 2, 3));
    // vertices.push_back(Vertex(4, 5, 6));
    // vertices.push_back(Vertex(7, 8, 9));

    vertices.push_back(Vertex(1, 2, 3));
    vertices.push_back(Vertex(4, 5, 6));
    vertices.push_back(Vertex(7, 8, 9));

    std::cout << vertices.at(1)._x << std::endl;

    return 0;
}
