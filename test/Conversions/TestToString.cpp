#include <gtest/gtest.h>
#include <SyriusUtils/Conversions/ToString.hpp>

using namespace Syrius;

class TestToString: public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(TestToString, TimePointToString) {
    const TimePoint t1 = timeFromEpoch(1734438000000.0);
    EXPECT_EQ(toString(t1), "2024-12-17 12:20:00");

    const TimePoint t2 = timeFromEpoch(1008403937000.0);
    EXPECT_EQ(toString(t2), "2001-12-15 08:12:17");
}

TEST_F(TestToString, DurationToString) {
    EXPECT_EQ(toString(5.0s), "5000");
    EXPECT_EQ(toString(4.0ms), "4");
}
