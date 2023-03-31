#include "TrafficLight.hpp"

#ifndef STATES_HPP
#define STATES_HPP

class GreenState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(GREEN);
    }
};

class BlinkingGreenState : public State
{
    void handle(TrafficLight *character) override 
    {
        character->setLightStatus(BLINKING_GREEN);
    }
};

class YellowRedState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(YELLOW_RED);
    }
};

class BlinkingYellowState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(BLINKING_YELLOW);
    }
};

class YellowState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(YELLOW);
    }
};

class RedState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(RED);
    }
};

class OffState : public State
{
    void handle(TrafficLight *character) override
    {
        character->setLightStatus(OFF);
    }
};

#endif