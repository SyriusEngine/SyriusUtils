#pragma once

#include <gtest/gtest.h>

class TestRandom: public ::testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;

};
