cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.263.tar.gz"
    SHA1 "9b96c376bf3526163e81b7adb8db5a0ea8c7e1bf"
)

project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

# hunter_add_package(gflags)
# hunter_add_package(glog)
# hunter_add_package(Boost COMPONENTS system)
hunter_add_package(GTest)

# find_package(gflag CONFIG REQUIRED)
# find_package(glog CONFIG REQUIRED)
# find_package(Boost CONFIG REQUIRED system)
find_package(GTest CONFIG REQUIRED)

include_directories(inc)

add_subdirectory(src)
add_subdirectory(test)
