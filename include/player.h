
#ifndef _PLAYER_H_

#define _PLAYER_H_

#include "entity.h"
#include "input.h"
#include "keyboard_input.h"

class Player: public Entity{
public:
    Player(b2World* world, int inputNumber);
    ~Player();

    void update(sf::Time elapsed);

private:
    Input* _controller;
    static b2BodyDef* bodyDef;

    static const b2BodyDef* getBodyDef();
    /* data */
};



#endif