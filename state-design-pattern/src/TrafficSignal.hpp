#include <iostream>
#include <vector>
#include <algorithm>

#ifndef TRAFFIC_SIGNAL_HPP
#define TRAFFIC_SIGNAL_HPP

#define GREEN ((uint8_t) 0b0010)
#define BLINKING_GREEN ((uint8_t) 0b0011)
#define YELLOW_RED ((uint8_t) 0b1100)
#define BLINKING_YELLOW ((uint8_t) 0b0101)
#define YELLOW ((uint8_t) 0b0100)
#define RED ((uint8_t) 0b1000)
#define OFF ((uint8_t) 0b0000)

class TrafficSignal;

class State
{
public:
    virtual void handle(TrafficSignal *) = 0;
};

class TrafficSignal
{
private:
    uint8_t status:4;
    State *state;
    void request();
public:
    TrafficSignal() : status(OFF), state(nullptr) {}
    TrafficSignal(State *);
    ~TrafficSignal();
    
    void show();
    void setState(State *);
    void setStatus(uint8_t var);
};

TrafficSignal::TrafficSignal(State *state)
{
    setState(state);
    status = OFF;
    request();
}

TrafficSignal::~TrafficSignal()
{
    delete state;
}

void TrafficSignal::request()
{
    state->handle(this);
}

void TrafficSignal::setState(State *state)
{
    if(this->state != nullptr)
        delete this->state;

    this->state = state;
    request();
}

void TrafficSignal::setStatus(uint8_t var)
{
    status = var;
}

void TrafficSignal::show()
{
    switch (status) {
        case GREEN:
            std::cout << "green\n";
            break;
        case BLINKING_GREEN:
            std::cout << "blinking green\n";
            break;
        case YELLOW_RED:
            std::cout << "yellow red\n";
            break;
        case BLINKING_YELLOW:
            std::cout << "blinking yellow\n";
            break;
        case YELLOW:
            std::cout << "yellow\n";
            break;
        case RED:
            std::cout << "red\n";
            break;
        case OFF:
            std::cout << "off\n";
            break;
        default:
            std::cout << "unknown status\n";
    }
}

#endif