#include <iostream>
#include <vector>
#include <algorithm>

#ifndef TRAFFIC_LIGHT_HPP
#define TRAFFIC_LIGHT_HPP

#define GREEN ((uint8_t) 0b0010)
#define BLINKING_GREEN ((uint8_t) 0b0011)
#define YELLOW_RED ((uint8_t) 0b1100)
#define BLINKING_YELLOW ((uint8_t) 0b0101)
#define YELLOW ((uint8_t) 0b0100)
#define RED ((uint8_t) 0b1000)
#define OFF ((uint8_t) 0b0000)

class TrafficLight;

class State
{
public:
    virtual void handle(TrafficLight *) = 0;
};

class TrafficLight
{
private:
    uint8_t lightStatus:4;
    State *state;
    
    void request();
public:
    TrafficLight() : lightStatus(OFF), state(nullptr) {}
    TrafficLight(State *);
    ~TrafficLight() { delete state; }

    uint8_t getLightStatus() { return lightStatus; };
    State* getState() { return state; }
    
    void show();
    void setState(State *);
    void setLightStatus(uint8_t);
};

TrafficLight::TrafficLight(State *state)
{
    setState(state);
    lightStatus = OFF;
    request();
}

void TrafficLight::request()
{
    state->handle(this);
}

void TrafficLight::setState(State *state)
{
    if(this->state != nullptr)
        delete this->state;

    this->state = state;
    request();
}

void TrafficLight::setLightStatus(uint8_t var)
{
    lightStatus = var;
}

void TrafficLight::show()
{
    switch (lightStatus) {
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