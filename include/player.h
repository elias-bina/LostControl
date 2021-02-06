
#ifndef _PLAYER_H_

#define _PLAYER_H_

#include "entity.h"

class Player: public Entity{
public:
    Player(/* args */);
    ~Player();

    void update(sf::Time elapsed);

private:
    /* data */
};



#endif