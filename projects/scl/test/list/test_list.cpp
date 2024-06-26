#include <gtest/gtest.h>

#include "list.hpp"

TEST(DoublyLinkedListTest, DefaultConstructor) {
    EAbrakhin::DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}

TEST(DoublyLinkedListTest, PushBack) {
    EAbrakhin::DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
}

TEST(DoublyLinkedListTest, HasItem) {
    EAbrakhin::DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.has_item(2));
    EXPECT_FALSE(list.has_item(4));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    EAbrakhin::DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.remove_first(1);
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.has_item(1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
