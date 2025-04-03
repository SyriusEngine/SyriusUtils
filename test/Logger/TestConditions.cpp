#include <gtest/gtest.h>
#include "../../include/SyriusUtils/Logger/Conditions.hpp"

class TestConditions: public testing::Test{
protected:
  void SetUp() override {

  }

  void TearDown() override {

  }
};

TEST_F(TestConditions, CorrectParse) {
    int x = 5;
    int y = 3;
    EXPECT_THROW(SR_PRECONDITION(x == y, "X is not equal to Y"), Syrius::SyriusAssert);
}
