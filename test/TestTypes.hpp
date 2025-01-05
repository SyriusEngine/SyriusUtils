#pragma once

#include <gtest/gtest.h>

class TestTypes: public testing::Test{
protected:
    void SetUp() override;

    void TearDown() override;
};