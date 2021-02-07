#pragma once

#ifndef _SHAPE_H_

#define _SHAPE_H_

#include "entity.h"

class Shape : public Entity {

    public:
        Shape(b2World * world, sf::ConvexShape* convex);
        ~Shape();
        void update(sf::Time elapsed);
        void draw(sf::RenderTexture& , sf::RenderWindow&) const;
        sf::ConvexShape* getConvex();
    protected:
        Shape(b2World * world, const b2BodyDef* bodyDef, sf::ConvexShape* convex);
        sf::ConvexShape* _convex;
        static b2BodyDef* bodyDef;

};



#endif