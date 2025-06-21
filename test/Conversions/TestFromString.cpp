#include <gtest/gtest.h>
#include <SyriusUtils/Conversions/FromString.hpp>

using namespace Syrius;

class TestFromString: public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(TestFromString, TimePointFromString) {
    const std::string ts1 = "2024-12-17 12:20:00";
    const TimePoint t1 = fromString<TimePoint>(ts1);
    const TimePoint refT1 = timeFromEpoch(1734438000000.0);
    EXPECT_EQ(t1, refT1);

    const std::string ts2 = "2001-12-15 08:12:17";
    const TimePoint t2 = fromString<TimePoint>(ts2);
    const TimePoint refT2 = timeFromEpoch(1008403937000.0);
    EXPECT_EQ(t2, refT2);
}

TEST_F(TestFromString, DurationFromString) {
    EXPECT_EQ(fromString<Duration>("5000.0"), 5.0s);
    EXPECT_EQ(fromString<Duration>("4"), 4ms);
}
