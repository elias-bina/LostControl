#pragma once

#ifndef _SHAPE_H_

#define _SHAPE_H_

#include "entity.h"

class Shape : public Entity {

    public:
        Shape(sf::ConvexShape* convex, b2World* world);
        ~Shape();
        void update(sf::Time elapsed);
        const b2BodyDef* getBodyDef();
        void draw(sf::RenderTexture& , sf::RenderWindow&) const;
        sf::ConvexShape* getConvex();
    private:
        sf::ConvexShape* _convex;
        static b2BodyDef* bodyDef;

};



#endif