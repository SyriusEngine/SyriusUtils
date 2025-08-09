#include <gtest/gtest.h>
#include <SyriusUtils/SyriusEnum.hpp>

class TestSyriusEnum: public ::testing::Test {
};

SR_ENUM(SR_FRUIT_TYPE, int,
    SR_FRUIT_NONE = 0,
    SR_FRUIT_APPLE = 1,
    SR_FRUIT_BANANA = 20,
    SR_FRUIT_CHERRY = 30,
    SR_FRUIT_ORANGE
    );

TEST_F(TestSyriusEnum, EnumToString) {
    EXPECT_EQ("SR_FRUIT_NONE", toString(SR_FRUIT_NONE));
    EXPECT_EQ("SR_FRUIT_APPLE", toString(SR_FRUIT_APPLE));
    EXPECT_EQ("SR_FRUIT_BANANA", toString(SR_FRUIT_BANANA));
    EXPECT_EQ("SR_FRUIT_CHERRY", toString(SR_FRUIT_CHERRY));
    EXPECT_EQ("SR_FRUIT_ORANGE", toString(SR_FRUIT_ORANGE));
}

TEST_F(TestSyriusEnum, StringToEnum) {
    EXPECT_EQ(fromString("SR_FRUIT_NONE"), SR_FRUIT_NONE);
    EXPECT_EQ(fromString("SR_FRUIT_APPLE"), SR_FRUIT_APPLE);
    EXPECT_EQ(fromString("SR_FRUIT_BANANA"), SR_FRUIT_BANANA);
    EXPECT_EQ(fromString("SR_FRUIT_CHERRY"), SR_FRUIT_CHERRY);
    EXPECT_EQ(fromString("SR_FRUIT_ORANGE"), SR_FRUIT_ORANGE);
    EXPECT_THROW(fromString("NON_EXISTENT_VALUE< "), std::runtime_error);
}


