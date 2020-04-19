#include "linked_lists.h"

#include "gtest/gtest.h"

namespace linkedlists {
TEST(SomeTestCase, AddOneTestPositive) {
    EXPECT_EQ(3, addOne(2));
}
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}