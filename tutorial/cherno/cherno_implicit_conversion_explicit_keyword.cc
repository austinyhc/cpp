#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    int m_Age;

public:
    explicit Entity(const std::string& name)
        : m_Name(name), m_Age(-1) {};
    explicit Entity(int age)
        : m_Name("Unknown"), m_Age(age) {};

    friend std::ostream& operator<<(std::ostream& stream, Entity entity);
};

std::ostream& operator<<(std::ostream& stream, Entity entity) {
    stream << entity.m_Name << " is " << entity.m_Age << " years old" << std::endl;
    return stream;
}

void PrintEntity(const Entity& entity) {
    // Printing
    std::cout << entity << std::endl;
}

int main() {
    /* Entity a("Austin"); */
    /* Entity b(34); */

    Entity a(std::string("Austin"));
    Entity b(32);

    PrintEntity(a);
    /* PrintEntity("Cherno"); */
    /* PrintEntity(std::string("Fran")); */

    return 0;
}
