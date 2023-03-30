#include "Character.hpp"

#ifndef STATES_HPP
#define STATES_HPP

class CoolingState : public State
{
    void handle(Character *character) override
    {
        character->changeTemperature(-1);
        std::cout << "entered colling state\n";
    }
};

class WarmingState : public State
{
    void handle(Character *character) override 
    {
        character->changeTemperature(1);
        std::cout << "entered warming state\n";
    }
};

#endif