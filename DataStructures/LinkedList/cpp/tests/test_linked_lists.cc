#include <gtest/gtest.h>

#include "linked_lists.h"

#include <string>

namespace linkedlists {
class SLinkedListTestInt : public ::testing::Test {
 protected:
  void SetUp() override {
    emptyList_ = std::make_unique<SLinkedList<int>>();
    smallList_ = std::make_unique<SLinkedList<int>>();
    bigList_ = std::make_unique<SLinkedList<int>>();
    smallList_->insert(3);
    smallList_->insert(5);
    smallList_->insert(-4);
    bigList_->insert(10);
    bigList_->insert(43);
    bigList_->insert(5000);
    bigList_->insert(10);
    bigList_->insert(-35);
  }
  void TearDown() override {
    emptyList_.reset();
    smallList_.reset();
    bigList_.reset();
  }
  std::unique_ptr<SLinkedList<int>> emptyList_;
  std::unique_ptr<SLinkedList<int>> smallList_;
  std::unique_ptr<SLinkedList<int>> bigList_;
};

TEST_F(SLinkedListTestInt, InsertValidInt) {
  EXPECT_TRUE(emptyList_->insert(3));
  EXPECT_TRUE(emptyList_->insert(5));
  EXPECT_TRUE(emptyList_->insert(-4));
  EXPECT_TRUE(emptyList_->insert(500));
  std::string printout = "3->5->-4->500->";
  EXPECT_EQ(printout, emptyList_->toString());
}

TEST_F(SLinkedListTestInt, ListSize) {
  EXPECT_EQ(3, smallList_->size);
}

TEST_F(SLinkedListTestInt, FindExisting) {
  SLinkedListNode<int> *expectedNode = bigList_->head;
  EXPECT_EQ(expectedNode, bigList_->find(10));
  expectedNode = bigList_->head->next;
  EXPECT_EQ(expectedNode, bigList_->find(43));
  expectedNode = bigList_->head->next->next;
  EXPECT_EQ(expectedNode, bigList_->find(5000));
  expectedNode = bigList_->head;
  EXPECT_EQ(expectedNode, bigList_->find(10));
  expectedNode = bigList_->head->next->next->next;
  EXPECT_NE(expectedNode, bigList_->find(10));
  EXPECT_EQ(*expectedNode, *bigList_->find(10));
  expectedNode = bigList_->tail;
  EXPECT_EQ(expectedNode, bigList_->find(-35));
}

TEST_F(SLinkedListTestInt, FindNotExisting) {
  EXPECT_EQ(nullptr, bigList_->find(9001));
}
}  // namespace linkedlists
