#include <iostream>
#include <vector>
#include <algorithm>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define DEFAULT_MAX_SPEED (uint8_t) 30
#define DEFAULT_MAX_HP (uint8_t) 120
#define DEFAULT_MAX_TEMPERATURE (uint8_t) 45
#define DEFAULT_MAX_SATIETY (uint8_t) 100
#define DEFAULT_MAX_HYDRRATION (uint8_t) 100

#define DEFAULT_START_SPEED (uint8_t) 30
#define DEFAULT_START_HP (uint8_t) 100
#define DEFAULT_START_TEMPERATURE (uint8_t) 36
#define DEFAULT_START_SATIETY (uint8_t) 75
#define DEFAULT_START_HYDRRATION (uint8_t) 75

void checkMaxValue(uint8_t &var, uint8_t maxValue)
{
    if(var > maxValue)
        var = maxValue;
}

class Character;

class State
{
public:
    virtual void handle(Character *) = 0;
};

class Character
{
    uint8_t hp;
    uint8_t temperature;
    uint8_t hydration;
    uint8_t satiety;

    uint8_t speed;
    std::vector<State*> states;
    void request();
public:
    Character() : 
        hp(DEFAULT_START_HP),
        temperature(DEFAULT_START_TEMPERATURE),
        hydration(DEFAULT_START_HYDRRATION),
        satiety(DEFAULT_START_SATIETY),
        speed(DEFAULT_START_SPEED)
        {}
    
    void addState(State *);
    void removeState(State *);
    void show();
    
    void changeHP(int);
    void changeTemperature(int);
    void changeSatiety(int); 
    void changeHydration(int);
    
    void changeSpeed(int);
};

void Character::request()
{
    states.at(states.size() - 1)->handle(this);
}

void Character::addState(State *state)
{
    if(std::count(states.begin(), states.end(), state) == 0)
        states.push_back(state);

    request();
}

void Character::removeState(State *state)
{
    states.erase(std::remove(states.begin(), states.end(), state), states.end());
}

void Character::show()
{
    std::cout << (int)hp << " HP\t" 
              << (int)temperature << "\u2103\t"
              << (int)hydration << "%\t"
              << (int)satiety << "%\t"
              << (int)speed << " km/h\n";
}

void Character::changeHP(int hp_) 
{
    hp += hp_;
    checkMaxValue(hp, DEFAULT_MAX_HP);
}

void Character::changeTemperature(int temperature_) 
{
    temperature += temperature_;
    checkMaxValue(temperature, DEFAULT_MAX_TEMPERATURE);
}

void Character::changeSatiety(int satiety_) 
{
    satiety += satiety_;
    checkMaxValue(satiety, DEFAULT_MAX_SATIETY);
}

void Character::changeHydration(int hydration_) 
{
    hydration += hydration_;
    checkMaxValue(hydration, DEFAULT_MAX_HYDRRATION);
}

void Character::changeSpeed(int speed_)
{
    speed += speed_;
    checkMaxValue(speed, DEFAULT_MAX_SPEED);
}

#endif