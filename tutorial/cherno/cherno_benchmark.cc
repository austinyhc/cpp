#include <iostream>
#include <memory>
#include <chrono>

class Timer {
public:
    Timer() {
        m_startTime = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        Stop();
    }
    void Stop() {
        auto m_endTime = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTime).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endTime).time_since_epoch().count();

        auto timelapsed = start - end;
        double ms = timelapsed * 0.001;

        std::cout << timelapsed << " us ("  << ms << " ms)" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
};

int main() {

    int value = 0;
    {
        Timer timer;
        for (int i{0}; i < 1000'000; ++i) {
            value += 2;
        }
    }

    std::cout << value << std::endl;

    /* __debugbreak(); */
}
