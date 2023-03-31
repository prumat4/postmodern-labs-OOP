#include "States.hpp"

void setAndShow(TrafficSignal &ts, State *state)
{
    ts.setState(state);
    ts.show();
}

void clientCode()
{
    TrafficSignal ts;
    ts.show();

    State *state = new RedState;
    setAndShow(ts, state);

    state = new YellowRedState;
    setAndShow(ts, state);

    state = new GreenState;
    setAndShow(ts, state);

    state = new BlinkingGreenState;
    setAndShow(ts, state);

    state = new YellowState;
    setAndShow(ts, state);

    state = new OffState;
    setAndShow(ts, state);

}

int main()
{
    clientCode();
    return 0;
}