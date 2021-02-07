#ifndef _ENTITIES_H_

#define _ENTITIES_H_

#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>


class Entity{
    
    public:
        Entity(b2World* world, const b2BodyDef* bodyDef, sf::Sprite* sprite);

        virtual void draw(sf::RenderTexture& , sf::RenderWindow&) const;
        virtual void update(sf::Time elapsed) = 0;

        virtual ~Entity(){};

    protected:
        sf::Sprite *_sprite;
        b2Body* _body;
};


#endif //_ENTITIES_H_
