
#ifndef _PLAYER_H_

#define _PLAYER_H_

#include <set>
#include "entity.h"
#include "SFML/System.hpp"
#include "input.h"
#include "keyboard_input.h"

class Player: public Entity{
public:
    Player(b2World* world, int inputNumber);
    ~Player();

    void update(sf::Time elapsed);

    virtual void startContact(Entity* other, const b2Vec2& normal);
    virtual void endContact(Entity* other, const b2Vec2& normal);

    virtual void draw(sf::RenderTexture& texture, sf::RenderWindow& fenetre) const;


private:
    Input* _controller;
    static b2BodyDef* bodyDef;
    sf::Clock _jumpClock;
    sf::Clock _actionClock;
    sf::Vector2f _jumpDir;

    std::set<Entity*> _jumpingPlatforms;

    static const b2BodyDef* getBodyDef();
    /* data */
};



#endif