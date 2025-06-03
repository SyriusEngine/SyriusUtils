#include <gtest/gtest.h>
#include <SyriusUtils/Srstl/KeyVector.hpp>

using namespace Srstl;

TEST(TestKeyVector, BasicOperations) {
    KeyVector<int, int> vec;
    vec.insert(0, 10);
    vec.insert(1, 20);
    vec.insert(2, 30);
    vec.insert(3, 40);

    EXPECT_EQ(vec.getSize(), 4);
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));
    EXPECT_TRUE(vec.has(3));

    vec.remove(2);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_FALSE(vec.has(2));
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(3));

    vec.remove(0);
    EXPECT_EQ(vec.getSize(), 2);
    EXPECT_FALSE(vec.has(0));
    EXPECT_TRUE(vec.has(1));

    std::vector<int> data;
    for (const auto& item: vec) {
        data.push_back(item);
    }
    EXPECT_EQ(data.size(), 2);
}

TEST(TestKeyVector, DuplicateKeys) {
    KeyVector<int, int> vec;
    vec.insert(15, 10);
    EXPECT_THROW(vec.insert(15, 20), Syrius::SyriusAssert);
}

struct Position {
    float x;
    float y;

    Position(float x_, float y_) : x(x_), y(y_) {}
};

TEST(TestKeyVector, EmplaceAndRetrieve) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 4.0f, 5.0f);
    vec.emplace(2, 6.0f, 7.0f);

    EXPECT_EQ(vec[0].x, 2.0f);
    EXPECT_EQ(vec[0].y, 3.0f);
    EXPECT_EQ(vec.get(1).x, 4.0f);
    EXPECT_EQ(vec.get(1).y, 5.0f);
    EXPECT_EQ(vec[2].x, 6.0f);
    EXPECT_EQ(vec[2].y, 7.0f);
}

TEST(TestKeyVector, InsertRemoveSingleElement) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);

    EXPECT_EQ(vec[0].x, 2.0f);
    EXPECT_EQ(vec[0].y, 3.0f);

    vec.remove(0);

    EXPECT_FALSE(vec.has(0));
}

TEST(TestKeyVector, InsertRemoveSameOrder) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 2.0f, 3.0f);
    vec.emplace(2, 2.0f, 3.0f);

    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(0);
    EXPECT_FALSE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(1);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(2);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));
}

TEST(TestKeyVector, InsertRemoveReverseOrder) {
    KeyVector<int, Position> vec;
    vec.emplace(0, 2.0f, 3.0f);
    vec.emplace(1, 2.0f, 3.0f);
    vec.emplace(2, 2.0f, 3.0f);

    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_TRUE(vec.has(2));

    vec.remove(2);
    EXPECT_TRUE(vec.has(0));
    EXPECT_TRUE(vec.has(1));
    EXPECT_FALSE(vec.has(2));

    vec.remove(1);
    EXPECT_TRUE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));

    vec.remove(0);
    EXPECT_FALSE(vec.has(0));
    EXPECT_FALSE(vec.has(1));
    EXPECT_FALSE(vec.has(2));
}

