#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
    Entity() {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }
    void Print() {}
private:
    int x;
};


class ScopedPtr {
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr): m_Ptr(ptr) {}
    ~ScopedPtr() { delete m_Ptr; }
};

int main() {

    {
        // Uncomment the two `e` declaration, and see what is the difference between
        // them, one is allocated in the heap while the other is in the stack.
        //Entity* e = new Entity();

        // - This works because of implicit conversion
        // - Definitely need to go back to the implicit conversion tutorial.
        // Even it looks very similar to the heap allocation, please be noted
        // that we do not use asterisk keyword when declaring `ScropePtr e`,
        // so the `ScopedPtr e` is allocated in the stack.
        // - Also this technique is called RAII, which is commonly used for some
        // real-life application, such as time profiler, logger at the beginning and
        // the end of a scope, mutex locking within a scope and so on and so forth.

        //ScopedPtr e = new Entity();
    }

    {
        //std::unique_ptr<Entity> entity(new Entity);
        // This is the most recommended way to declare an unique pointer.
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        //std::unique_ptr<Entity> e0 = entity;

        std::shared_ptr<Entity> e0;
        {
            //std::shared_ptr<Entity> sharedEntity(new Entity())
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
        }
    }

    return 0;
}
