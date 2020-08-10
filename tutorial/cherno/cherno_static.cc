#include <iostream>

struct Entity
{
    int x, y;
    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

static void Print(Entity e) {
    std::cout << e.x << ", " << e.y << std::endl;
}

/* int Entity::x; */
/* int Entity::y; */

int main()
{
    Entity e;
    Entity::x = 1;
    Entity::y = 2;

    Entity e1;
    Entity::x = 5;
    Entity::y = 6;

    Entity::Print();
    Entity::Print();

    return 0;
}
