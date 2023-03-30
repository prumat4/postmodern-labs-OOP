#include "Character.hpp"

#ifndef STATES_HPP
#define STATES_HPP

class ConcreteStateA : public State
{
public:
    void handle(Character *) override;
};

void ConcreteStateA::handle(Character *character)
{
    character->changeSpeed(-5);
}

#endif