#include <gtest/gtest.h>

#include "linked_lists.h"

#include <string>

namespace linkedlists {
// dummy test for sanity check
TEST(SomeTestCase, AddOneTestPositive) { EXPECT_EQ(3, addOne(2)); }

class SLinkedListTestInt : public ::testing::Test {
//  public:
//   ~SLinkedListTestInt() override { delete list_; }
 protected:
  void SetUp() override { list_ = new SLinkedList<int>(); }
  void TearDown() override {
    delete list_;
    list_ = nullptr;
  }
  SLinkedList<int> *list_;
};
TEST_F(SLinkedListTestInt, InsertValidInt) {
    EXPECT_TRUE(list_->insert(3));
    EXPECT_TRUE(list_->insert(5));
    EXPECT_TRUE(list_->insert(-4));
    EXPECT_TRUE(list_->insert(500));
    std::string printout = "3->5->-4->500->";
    EXPECT_EQ(printout, list_->toString());
    }
}  // namespace linkedlists
