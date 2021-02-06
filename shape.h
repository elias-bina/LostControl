#pragma once

#ifndef _SHAPE_H_

#define _SHAPE_H_

#include "entity.h"

class Shape : public Entity {

    public:
        Shape(sf::Vector2f size, sf::ConvexShape convex);
        void update(sf::Time elapsed, Dir d);

    private:
        sf::ConvexShape _convex;
};



#endif