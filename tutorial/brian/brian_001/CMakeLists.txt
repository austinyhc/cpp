cmake_minimum_required(VERSION 3.0)

# Include the Hunter package manager module
include("../cmake/HunterGate.cmake")

# Ensure a reproducible build by locking down the Hunter package versions.
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.263.tar.gz"
    SHA1 "9b96c376bf3526163e81b7adb8db5a0ea8c7e1bf"
)

project(brianOrr)

# Tell Hunter which packages to pull in for our app. Each one has a helpful
# entry on Hunter's wiki that indicates how to include it.
hunter_add_package(gflags)
hunter_add_package(glog)

find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

add_executable(
    brianOrr
    brian_001.cc)

target_link_libraries(brianOrr
    glog::glog
    gflags)

install(TARGETS brianOrr DESTINATION bin)
