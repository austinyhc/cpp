#include <iostream>
#include <memory>

// I will create a dirty simple way to track the memory usage
// by overloading the new and delete operator.
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

struct SensorReadings {
    int x, y, z;
};

int main() {
    PrintMemoryUsage();
    // Interesting: seems like there is a scenario that the std::string
    // won't allocate memory on the heap. BTW, avoid to use any string
    // in the embedded world unless it is neccessary.
    //
    // Caveat here, using standard libraries are not generally expected to
    // be extensive or widespread in the embedded environemens where this
    // code will run.
    std::string sensorName = "Simulated Piezo Force Sensor";
    PrintMemoryUsage();

    SensorReadings* reading = new SensorReadings;
    PrintMemoryUsage();
    {
        std::unique_ptr<SensorReadings> p_reading = std::make_unique<SensorReadings>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();

    return 0;
}
