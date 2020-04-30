#include <gtest/gtest.h>

#include "linked_lists.h"

#include <string>

namespace linkedlists {
class SLinkedListTestInt : public ::testing::Test {
 protected:
  void SetUp() override { list_ = std::make_unique<SLinkedList<int>>(); }
  void TearDown() override {
    list_.reset();
  }
  std::unique_ptr<SLinkedList<int>> list_;
};
TEST_F(SLinkedListTestInt, InsertValidInt) {
  EXPECT_TRUE(list_->insert(3));
  EXPECT_TRUE(list_->insert(5));
  EXPECT_TRUE(list_->insert(-4));
  EXPECT_TRUE(list_->insert(500));
  std::string printout = "3->5->-4->500->";
  EXPECT_EQ(printout, list_->toString());
}

TEST_F(SLinkedListTestInt, ListSize) {
  EXPECT_TRUE(list_->insert(3));
  EXPECT_TRUE(list_->insert(5));
  EXPECT_TRUE(list_->insert(-4));
  EXPECT_EQ(3, list_->size);
}

TEST_F(SLinkedListTestInt, FindExisting) {
  list_->insert(10);
  list_->insert(43);
  list_->insert(5000);
  list_->insert(10);
  list_->insert(-35);
  SLinkedListNode<int> *expectedNode = list_->head;
  EXPECT_EQ(expectedNode, list_->find(10));
  expectedNode = list_->head->next;
  EXPECT_EQ(expectedNode, list_->find(43));
  expectedNode = list_->head->next->next;
  EXPECT_EQ(expectedNode, list_->find(5000));
  expectedNode = list_->head;
  EXPECT_EQ(expectedNode, list_->find(10));
  expectedNode = list_->head->next->next->next;
  EXPECT_NE(expectedNode, list_->find(10));
  EXPECT_EQ(*expectedNode, *list_->find(10));
  expectedNode = list_->tail;
  EXPECT_EQ(expectedNode, list_->find(-35));
}

TEST_F(SLinkedListTestInt, FindNotExisting) {
  list_->insert(10);
  list_->insert(43);
  list_->insert(5000);
  list_->insert(-35);
  EXPECT_EQ(nullptr, list_->find(9001));
}
}  // namespace linkedlists
