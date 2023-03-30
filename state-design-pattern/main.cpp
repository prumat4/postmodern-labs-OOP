#include "States.hpp"

int main()
{
    State *state = new CoolingState();
    Character character;
    character.show();
    character.addState(state);

    delete state;
    return 0;
}