#include <iostream>
#include <vector>
#include <algorithm>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

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
    // Red Yellow Green IsBlinking
    uint8_t status:4;
    State *state;
    void request();
public:
    TrafficSignal() : status(OFF), state(nullptr) {}
    TrafficSignal(State *);
    ~TrafficSignal() { delete state; }
    
    void show();
    void setState(State *);
    void setStatus(uint8_t var);
};

void TrafficSignal::setStatus(uint8_t var)
{
    status = var;
}

TrafficSignal::TrafficSignal(State *state)
{
    setState(state);
    status = OFF;
    request();
}

void TrafficSignal::show()
{
    if(status == GREEN)
        std::cout << "green\n";
    if(status == BLINKING_GREEN)
        std::cout << "blinking red\n";
    if(status == YELLOW_RED)
        std::cout << "yellow red\n";
    if(status == BLINKING_YELLOW)
        std::cout << "blinking yellow\n";
    if(status == YELLOW)
        std::cout << "yellow\n";
    if(status == RED)
        std::cout << "red\n";
    if(status == OFF)
        std::cout << "off\n";

}

void TrafficSignal::request()
{
    state->handle(this);
}

void TrafficSignal::setState(State *state)
{
    this->state = state;
    request();
}

#endif