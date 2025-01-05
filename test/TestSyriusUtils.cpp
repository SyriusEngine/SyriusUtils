#include "../include/SyriusUtils/SyriusUtils.hpp"

#include <gtest/gtest.h>

TEST(TestGtest, add){
    EXPECT_EQ(Syrius::add(1, 2), 3);
}
