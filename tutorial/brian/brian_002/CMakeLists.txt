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
hunter_add_package(Boost COMPONENTS system)

find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED system)

add_executable(
    brianOrrBasics
    brian_002_basices.cc)

target_link_libraries(brainOrrBasics
    Boost::boost
    Boost::system
    glog::glog
    gflags)

add_executable(
    brianOrrCounter
    brian_002_counter.cc)

target_link_libraries(brianOrrCounter
    Boost::boost
    Boost::system
    glog::glog
    gflags)

add_executable(
    brianOrrResolver
    brian_002_resolver.cc)

target_link_libraries(brianOrrResolver
    Boost::boost
    Boost::system
    glog::glog
    gflags)
