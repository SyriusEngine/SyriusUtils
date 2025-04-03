#include <gtest/gtest.h>
#include "../include/SyriusUtils/SyriusUtils.hpp"

using namespace Syrius;

class TestUtils: public testing::Test{
protected:
    void SetUp() override {

    }


    void TearDown() override {

    }
};

TEST_F(TestUtils, CheckFile) {
    EXPECT_THROW(checkFile("NON_EXISTENT_FILE"), std::runtime_error);
}

TEST_F(TestUtils, CheckDirectory) {
    EXPECT_THROW(checkDirectory("NON_EXISTENT_DIRECTORY"), std::runtime_error);
}
