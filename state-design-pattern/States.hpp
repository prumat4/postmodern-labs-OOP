#include "Character.hpp"

#ifndef STATES_HPP
#define STATES_HPP

class GreenState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(GREEN);
    }
};

class BlinkingGreenState : public State
{
    void handle(TrafficSignal *character) override 
    {
        character->setStatus(BLINKING_GREEN);

    }
};

class YellowRedState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(YELLOW_RED);
    }
};

class BlinkingYellowState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(BLINKING_YELLOW);
    }
};

class YellowState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(YELLOW);
    }
};

class RedState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(RED);
    }
};

class OffState : public State
{
    void handle(TrafficSignal *character) override
    {
        character->setStatus(OFF);
    }
};



#endif