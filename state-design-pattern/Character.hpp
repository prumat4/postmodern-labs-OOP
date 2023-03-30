#include <iostream>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define MAX_SPEED 20
#define MAX_HP 100

class Character;

class State
{
public:
    virtual void handle(Character *) = 0;
};

class Character
{
    int hp;
    int speed;
    State* state;
public:
    Character();
    Character(State *);
    
    void changeSpeed(int);
    void changeHP(int);
    void request();
    void setState(State *);
    void show();
};

Character::Character()
{
    hp = MAX_HP;
    speed = MAX_SPEED;
}

Character::Character(State *state_)
{
    hp = MAX_HP;
    speed = MAX_SPEED;
    state = state_;
}

void Character::request()
{
    state->handle(this);
}

void Character::setState(State *state_)
{
    state = state_;
}

void Character::changeSpeed(int speed_)
{
    this->speed += speed_;
}

void Character::changeHP(int hp_) 
{
    this->hp += hp_;
}

void Character::show()
{
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Speed: " << speed << std::endl;
}

#endif