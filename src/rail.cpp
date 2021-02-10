#include "rail.h"
#include "shape.h"
#include "utils.h"

Rail::Rail(b2World * world, sf::ConvexShape* convex, Dir d) : Shape(world, getDefaultDynamicBodyDef(), convex) {
    b2Vec2 vec;

    if (d == Up)
    {
        vec.y = 5;
    }
    else if (d == Down)
    {
        vec.y = -5;
    }

    if (d == Right)
    {
        vec.x = -5;
    }
    else if (d == Left)
    {
        vec.x = 5;
    }
     _body->SetLinearVelocity(vec);
    

    _d = d;
}


void Rail::update(sf::Time elapsed, Dir d)
{
    float moveX = 0.0;
    float moveY = 0.0;
}


void Rail::update(sf::Time elapsed) {

}