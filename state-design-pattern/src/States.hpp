#include "TrafficLight.hpp"

#ifndef STATES_HPP
#define STATES_HPP

class GreenState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(GREEN);
    }
};

class BlinkingGreenState : public StateInterface
{
    void handle(TrafficLight *character) override 
    {
        character->setLightStatus(BLINKING_GREEN);
    }
};

class YellowRedState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(YELLOW_RED);
    }
};

class BlinkingYellowState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(BLINKING_YELLOW);
    }
};

class YellowState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(YELLOW);
    }
};

class RedState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(RED);
    }
};

class OffState : public StateInterface
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(OFF);
    }
};

#endif