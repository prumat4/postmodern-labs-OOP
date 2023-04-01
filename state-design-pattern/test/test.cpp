#include "../src/States.hpp"
#include <gtest/gtest.h>

struct TrafficLightTests : public testing::Test
{
    TrafficLight *trafficLight;
    void SetUp() override { trafficLight = new TrafficLight; }
    void TearDown() override { delete trafficLight; }
};

TEST_F(TrafficLightTests, SetAndGetLightStatusTest)
{
    trafficLight->setLightStatus(YELLOW);
    EXPECT_EQ(trafficLight->getLightStatus(), YELLOW);
}

TEST_F(TrafficLightTests, SetAndGetStateTest)
{
    State* state = new RedState();
    trafficLight->setState(state);
    EXPECT_EQ(trafficLight->getState(), state);
}

TEST_F(TrafficLightTests, DefaultConstructorTest)
{
    EXPECT_TRUE(trafficLight->getLightStatus() == OFF);
    EXPECT_TRUE(trafficLight->getState() == nullptr);
}

TEST_F(TrafficLightTests, ConstructorWithStatepaParameterTest)
{
    State *state = new RedState();
    delete trafficLight;
    trafficLight = new TrafficLight(state);
    EXPECT_EQ(trafficLight->getState(), state);
}

TEST_F(TrafficLightTests, DestructorTest)
{
    TrafficLight * tl = new TrafficLight;
    State *checkState = tl->getState();
    delete tl;
    EXPECT_EQ(checkState, nullptr);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
