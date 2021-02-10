#pragma once

#ifndef _SHAPE_H_

#define _SHAPE_H_

#include "entity.h"

class Shape : public Entity {

    public:
        Shape(b2World * world, sf::Shape* convex, const sf::Vector2f& position = sf::Vector2f(0, 0));
        ~Shape();
        void update(sf::Time elapsed);
        void draw(sf::RenderTexture& , sf::RenderWindow&) const;
        sf::Shape* getConvex();
    protected:
        Shape(b2World * world, const b2BodyDef* bodyDef, sf::Shape* convex);
        sf::Shape* _convex;

};



#endif