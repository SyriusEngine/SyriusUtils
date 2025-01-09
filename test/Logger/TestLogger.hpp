#pragma once

#include <gtest/gtest.h>

class TestLogger: public testing::Test{
protected:
    void SetUp() override;

    void TearDown() override;
};