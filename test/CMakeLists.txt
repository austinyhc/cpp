set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cc)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})

# target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib
#     gtest GTest::gtest_main GTest::gtest GTest::gmock_main
#     Boost::boost Boost::system glog::glog gflags)

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib
    GTest::gtest_main GTest::gtest GTest::gmock_main)
