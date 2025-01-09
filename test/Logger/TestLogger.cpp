#include "TestLogger.hpp"
#include "../../include/SyriusUtils/Logger/LoggerMacros.hpp"

using namespace Syrius;

void TestLogger::SetUp() {
    Test::SetUp();
}

void TestLogger::TearDown() {
    Test::TearDown();
}

TEST_F(TestLogger, ConvertSeverityToString){
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_NONE), "NONE");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_INFO), "INFO");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_LOW), "LOW");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_MEDIUM), "MEDIUM");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_HIGH), "HIGH");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_FATAL), "FATAL");
    EXPECT_EQ(getMessageSeverityString(SR_MESSAGE_SEVERITY_UNKNOWN), "UNKNOWN");
}