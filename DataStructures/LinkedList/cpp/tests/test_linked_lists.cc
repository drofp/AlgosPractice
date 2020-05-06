#include <gtest/gtest.h>

#include "linked_lists.h"

#include <string>

namespace linkedlists {
class SLinkedListNodeTestInt : public ::testing::Test {
 protected:
  void SetUp() override {
    n_ = std::make_unique<SLinkedListNode<int>>(42);
  }

  void TearDown() override {
    n_.reset();
  }
  std::unique_ptr<SLinkedListNode<int>> n_;
};

TEST_F(SLinkedListNodeTestInt, CopyConstruct) {
  SLinkedListNode<int> *copiedNode = new SLinkedListNode<int>(*n_.get());
  EXPECT_EQ(*copiedNode, *n_.get());
  EXPECT_NE(copiedNode, n_.get());
}

TEST_F(SLinkedListNodeTestInt, CopyAssign) {
  SLinkedListNode<int> copiedNodeWithNullNext;
  copiedNodeWithNullNext = *n_.get();
  EXPECT_EQ(copiedNodeWithNullNext, *n_.get());
  EXPECT_NE(&copiedNodeWithNullNext, n_.get());

  SLinkedListNode<int> copiedNodeWithExistingNext;
  n_->next = new SLinkedListNode<int>(6);
  copiedNodeWithExistingNext = *n_.get();
  EXPECT_EQ(copiedNodeWithExistingNext, *n_.get());
  EXPECT_NE(&copiedNodeWithExistingNext, n_.get());
}

TEST_F(SLinkedListNodeTestInt, MoveConstruct) {
  n_->data = 54;
  int oldData = n_->data;
  SLinkedListNode<int> *oldNext = n_->next;
  SLinkedListNode<int> newNodeWithNullNext = std::move(*n_);

  EXPECT_EQ(n_->next, nullptr);
  EXPECT_EQ(newNodeWithNullNext.data, oldData);
  EXPECT_EQ(newNodeWithNullNext.next, oldNext);
}

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

TEST_F(SLinkedListTestInt, CopyConstruct) {
  SLinkedList<int> *copiedList = new SLinkedList<int>(*bigList_.get());
  SLinkedListNode<int> *expectedNode = copiedList->head;
  EXPECT_EQ(expectedNode, copiedList->find(10));
  expectedNode = copiedList->head->next;
  EXPECT_EQ(expectedNode, copiedList->find(43));
  expectedNode = copiedList->head->next->next;
  EXPECT_EQ(expectedNode, copiedList->find(5000));
  expectedNode = copiedList->head;
  EXPECT_EQ(expectedNode, copiedList->find(10));
  expectedNode = copiedList->head->next->next->next;
  EXPECT_NE(expectedNode, copiedList->find(10));
  EXPECT_EQ(*expectedNode, *copiedList->find(10));
  expectedNode = copiedList->tail;
  EXPECT_EQ(expectedNode, copiedList->find(-35));
  delete copiedList;
}

TEST_F(SLinkedListTestInt, CopyAssign) {}

TEST_F(SLinkedListTestInt, MoveConstruct) {}

TEST_F(SLinkedListTestInt, MoveAssign) {}
}  // namespace linkedlists
