#include <gtest/gtest.h>
#include "accumulator.h"

TEST(AccumulatorTest, EmptyVector) {
    std::vector<int> v;
    EXPECT_EQ(accumulator(v), 0);
}

TEST(AccumulatorTest, OneElementVector) {
    std::vector<int> v = {1};
    EXPECT_EQ(accumulator(v), 1);
}

TEST(AccumulatorTest, ManyElementsVector) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    EXPECT_EQ(accumulator(v), 15);
}