#include <iostream>
#include <memory>

struct AllocationMetrices {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};
static AllocationMetrices s_AllocationMetrices;
static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << s_AllocationMetrices.CurrentUsage() << " bytes\n";
}

void* operator new(size_t size) {
    s_AllocationMetrices.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    s_AllocationMetrices.TotalFreed += size;
    free(memory);
}

struct Object {
    int x, y, z;
};

int main() {
    PrintMemoryUsage();
    std::string str = "Cherno";
    PrintMemoryUsage();

    Object* obj = new Object;
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj_uptr = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();

    return 0;
}
