#include <gtest/gtest.h>
#include "solution.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (Solution::bla (0),  0);
    EXPECT_EQ (Solution::bla (10), 20);
    EXPECT_EQ (Solution::bla (50), 100);
}
