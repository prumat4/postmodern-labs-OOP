#include "../src/States.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Invoke;
using ::testing::_;

class TrafficLightTests : public testing::Test
{
public:
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
    StateInterface* state = new RedState();
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
    StateInterface *state = new RedState();
    delete trafficLight;
    trafficLight = new TrafficLight(state);
    EXPECT_EQ(trafficLight->getState(), state);
}

TEST_F(TrafficLightTests, DestructorTest)
{
    TrafficLight *tl = new TrafficLight;
    StateInterface *checkState = tl->getState();
    delete tl;
    EXPECT_EQ(checkState, nullptr);
}

struct MockState : public StateInterface
{
    MOCK_METHOD1(handle, void (TrafficLight *));
};

class StateTests : public testing::Test
{
public:
    MockState *mockState; 
    void SetUp() override { mockState = new MockState; }
    void TearDown() override { delete mockState; };
};

TEST_F(StateTests, GreenStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(GREEN);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), GREEN);
}

TEST_F(StateTests, BlinkingGreenStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(BLINKING_GREEN);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), BLINKING_GREEN);
}

TEST_F(StateTests, YellowRedStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(YELLOW_RED);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), YELLOW_RED);
}

TEST_F(StateTests, BlinkingYellowStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(BLINKING_YELLOW);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), BLINKING_YELLOW);
}

TEST_F(StateTests, YellowStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(YELLOW);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), YELLOW);
}

TEST_F(StateTests, RedStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(RED);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), RED);
}

TEST_F(StateTests, OffStateTest)
{
    EXPECT_CALL(*mockState, handle(_))
        .Times(1)
        .WillOnce(Invoke([](TrafficLight *trafficLight) 
        {
            if (trafficLight != nullptr)
                trafficLight->setLightStatus(OFF);
        }));

    TrafficLight *trafficLight = new TrafficLight(mockState);

    EXPECT_EQ(trafficLight->getLightStatus(), OFF);
}

int main()
{   
    testing::InitGoogleTest();
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
} 
