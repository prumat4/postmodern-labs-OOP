#include "States.hpp"

int main()
{
    State *state = new GreenState();
    TrafficSignal sv;
    sv.show();

    sv.setState(state);
    sv.show();

    return 0;
}