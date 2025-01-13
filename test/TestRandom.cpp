#include "TestRandom.hpp"

#include "../include/SyriusUtils/Random.hpp"

using namespace Syrius;

constexpr u64 s_Seed = 1234;

void TestRandom::SetUp() {
    Random::setSeed(s_Seed);
}

void TestRandom::TearDown() {

}

TEST_F(TestRandom, GetSetSeed) {
    constexpr u64 newSeed = 12345;
    Random::setSeed(newSeed);
    EXPECT_EQ(Random::getSeed(), newSeed);
}

TEST_F(TestRandom, RandomIntSequence) {
    const std::vector<int> expected = {1920845167,  -1923185962, 2037181481, 1914474662,
                                       -1350132284, 1927295164,  1642986574};
    std::vector<int> actual;
    for (size_t i = 0; i < expected.size(); ++i) {
        actual.push_back(Random::getRandom<int>());
    }
    // Compare the expected and actual vectors, sadly GTest does not support comparing vectors directly.
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], actual[i]);
    }
}

TEST_F(TestRandom, RandomIntBounds) {
    for (int i = 0; i < 10; i++) {
        constexpr int min = 10;
        constexpr int max = 200;
        const auto random = Random::getRandom<int>(min, max);
        EXPECT_GE(random, min);
        EXPECT_LE(random, max);
    }
}

TEST_F(TestRandom, RandomFloatSequence) {
    const std::vector<float> expected = {3.22326187e+38, 1.77706918e+37, 3.31543305e+38, 3.2182148e+38,
                                         6.31726781e+37, 3.22837223e+38, 3.00311964e+38};
    std::vector<float> actual;
    for (size_t i = 0; i < expected.size(); ++i) {
        actual.push_back(Random::getRandom<float>());
    }
    // Compare the expected and actual vectors, sadly GTest does not support comparing vectors directly.
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(expected[i], actual[i], 0.0001);
    }
}

TEST_F(TestRandom, RandomFloatBounds) {
    for (int i = 0; i < 10; i++) {
        constexpr float max = 200.0;
        constexpr float min = 10.0;
        const auto random = Random::getRandom<float>(min, max);
        EXPECT_GE(random, min);
        EXPECT_LE(random, max);
    }
}