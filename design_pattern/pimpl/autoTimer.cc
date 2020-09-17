#include "autoTimer.h"
#include <iostream>

class AutoTimer::Impl {
public:
    double GetElapsed() const {
        struct timeval end_time;
        gettimeofday(&end_time, nullptr);
        double t1 = mStartTimef.tv_usec / 1e6 + mStartTime.tv_sec;
        double t2 = end_time.tv_usec / 1e6 + end_time.tv_sec;
        return t2 - t1;
    }

    std::string mName;
    struct timeval mStartTime;
};

AutoTimer::AutoTimer(const std::string& name)
    : mImpl(new AutoTimer::Impl())
{
    mImpl->mName = name;
    gettimeofday(&mImpl->mStartTime, nullptr);
}

AutoTimer::~AutoTimer()
{
    std::cout << mImpl->mName << ": took"
        << mImpl->GetElapsed() << " secs" << '\n';
    delete mImpl;
    mImpl = nullptr;
}

