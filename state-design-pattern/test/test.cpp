#include "../src/States.hpp"
#include <gtest/gtest.h>

struct TrafficLightTest : public testing::Test
{
    TrafficLight *trafficLight;
    void SetUp() override { trafficLight = new TrafficLight; }
    void TearDown() override { delete trafficLight; }
};

TEST_F(TrafficLightTest, SetAndGetLightStatusTest)
{
    trafficLight->setLightStatus(YELLOW);
    EXPECT_EQ(trafficLight->getLightStatus(), YELLOW);
}

TEST_F(TrafficLightTest, SetAndGetStateTest)
{
    State* state = new RedState();
    trafficLight->setState(state);
    ASSERT_EQ(trafficLight->getState(), state);
}

TEST_F(TrafficLightTest, DefaultConstructorTest)
{
    EXPECT_TRUE(trafficLight->getLightStatus() == OFF);
    EXPECT_TRUE(trafficLight->getState() == nullptr);
}

TEST_F(TrafficLightTest, ConstructorWithStatepaParameterTest)
{
    State *state = new RedState();
    delete trafficLight;
    trafficLight = new TrafficLight(state);
    ASSERT_EQ(trafficLight->getState(), state);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
