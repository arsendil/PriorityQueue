#include <gtest/gtest.h>
#include "headers/PriorityQueue.hpp"

TEST(PriorityQueueTest, IsInitiallyEmpty) {
    PriorityQueue<int> pq;
    EXPECT_TRUE(pq.empty());
    EXPECT_EQ(pq.size(), 0u);
}

TEST(PriorityQueueTest, PushIncreasesSize) {
    PriorityQueue<int> pq;
    pq.push(5);
    EXPECT_FALSE(pq.empty());
    EXPECT_EQ(pq.size(), 1u);
}

TEST(PriorityQueueTest, TopReturnsMaxElement) {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    EXPECT_EQ(pq.top(), 20);
}

TEST(PriorityQueueTest, PopRemovesTopElement) {
    PriorityQueue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.pop();
    EXPECT_EQ(pq.top(), 2);
    EXPECT_EQ(pq.size(), 2u);
}

TEST(PriorityQueueTest, SizeAfterMultipleOperations) {
    PriorityQueue<int> pq;
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.pop();
    EXPECT_EQ(pq.size(), 2u);
}

TEST(PriorityQueueTest, MultiplePushPopSequence) {
    PriorityQueue<int> pq;
    pq.push(4);
    pq.push(7);
    pq.push(5);
    pq.pop();
    pq.push(10);
    pq.pop();
    EXPECT_EQ(pq.top(), 5);
    EXPECT_EQ(pq.size(), 2u);
}

TEST(PriorityQueueTest, HandlesDuplicateElements) {
    PriorityQueue<int> pq;
    pq.push(3);
    pq.push(3);
    pq.push(3);
    EXPECT_EQ(pq.top(), 3);
    pq.pop();
    EXPECT_EQ(pq.top(), 3);
}

TEST(PriorityQueueTest, TopDoesNotRemoveElement) {
    PriorityQueue<int> pq;
    pq.push(42);
    int top = pq.top();
    EXPECT_EQ(top, 42);
    EXPECT_EQ(pq.size(), 1u);
}

TEST(PriorityQueueTest, IsEmptyAfterPoppingAllElements) {
    PriorityQueue<int> pq;
    pq.push(9);
    pq.pop();
    EXPECT_TRUE(pq.empty());
    EXPECT_EQ(pq.size(), 0u);
}

TEST(PriorityQueueTest, HandlesDifferentTypes) {
    PriorityQueue<std::string> pq;
    pq.push("apple");
    pq.push("banana");
    EXPECT_EQ(pq.top(), "banana"); // assuming lex order, "banana" > "apple"
    pq.pop();
    EXPECT_EQ(pq.top(), "apple");
}

TEST(PriorityQueueTest, PopUpdatesTopCorrectlyEachStep) {
    PriorityQueue<int> pq;
    pq.push(25);
    pq.push(10);
    pq.push(40);
    pq.push(5);

    EXPECT_EQ(40, pq.top());
    pq.pop();
    EXPECT_EQ(25, pq.top());
    pq.pop();
    EXPECT_EQ(10, pq.top());
    pq.pop();
    EXPECT_EQ(5, pq.top());
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueueTest, PopSequenceWithAscendingInput) {
    PriorityQueue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    EXPECT_EQ(4, pq.top());
    pq.pop();
    EXPECT_EQ(3, pq.top());
    pq.pop();
    EXPECT_EQ(2, pq.top());
    pq.pop();
    EXPECT_EQ(1, pq.top());
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueueTest, PopSequenceWithDescendingInput) {
    PriorityQueue<int> pq;
    pq.push(100);
    pq.push(50);
    pq.push(25);
    pq.push(10);

    EXPECT_EQ(100, pq.top());
    pq.pop();
    EXPECT_EQ(50, pq.top());
    pq.pop();
    EXPECT_EQ(25, pq.top());
    pq.pop();
    EXPECT_EQ(10, pq.top());
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueueTest, PopSequenceWithMixedInput) {
    PriorityQueue<int> pq;
    pq.push(7);
    pq.push(42);
    pq.push(3);
    pq.push(15);
    pq.push(9);

    EXPECT_EQ(42, pq.top());
    pq.pop();
    EXPECT_EQ(15, pq.top());
    pq.pop();
    EXPECT_EQ(9, pq.top());
    pq.pop();
    EXPECT_EQ(7, pq.top());
    pq.pop();
    EXPECT_EQ(3, pq.top());
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueueTest, PopSequenceWithDuplicates) {
    PriorityQueue<int> pq;
    pq.push(20);
    pq.push(20);
    pq.push(10);
    pq.push(30);
    pq.push(30);

    EXPECT_EQ(30, pq.top());
    pq.pop();
    EXPECT_EQ(30, pq.top());
    pq.pop();
    EXPECT_EQ(20, pq.top());
    pq.pop();
    EXPECT_EQ(20, pq.top());
    pq.pop();
    EXPECT_EQ(10, pq.top());
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

