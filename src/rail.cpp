#include "rail.h"
#include "shape.h"
#include "utils.h"

Rail::Rail(b2World * world, sf::ConvexShape* convex, Dir d) : Shape(world, getDefaultDynamicBodyDef(), convex) {
    
    std::vector<b2Vec2> points; 
    for (size_t i = 0; i < convex->getPointCount(); i++)
        points.push_back(sfToBoxVec(convex->getPoint(i)));

    b2PolygonShape shape;
    shape.Set(points.data(), points.size());
    b2FixtureDef fix;
    fix.shape = &shape;
    fix.density = 1;
    fix.friction = 0.3;

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
    _body->CreateFixture(&fix);
}


void Rail::update(sf::Time elapsed, Dir d)
{
    float moveX = 0.0;
    float moveY = 0.0;
}


void Rail::update(sf::Time elapsed) {

}