
#ifndef _PLAYER_H_

#define _PLAYER_H_

#include "entity.h"

class Player: public Entity{
public:
    Player(b2World* world);
    ~Player();

    void update(sf::Time elapsed);

private:
    static b2BodyDef* bodyDef;

    static const b2BodyDef* getBodyDef();
    /* data */
};



#endif