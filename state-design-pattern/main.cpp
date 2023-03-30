#include "States.hpp"

int main()
{
    State *state = new ConcreteStateA();
    Character character(state);

    character.show();
    character.request();
    character.show();

    return 0;
}