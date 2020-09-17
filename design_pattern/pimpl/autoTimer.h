#include <string>

// class AutoTimer {
// public:
//     explicit AutoTimer(const std::string &name);
//     ~AutoTimer();
//
// private:
//     double GetElapsed() const;
//     std::string mName;
//     struct timeval mStartTime;
// };

class AutoTimer {
public:
    explicit AutoTimer(const std::string &name);
    ~AutoTimer();

private:
    class Impl;
    Impl* mImpl;
};
