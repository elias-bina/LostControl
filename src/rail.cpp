#include "rail.h"
#include "shape.h"


Rail::Rail(sf::Vector2f size, sf::ConvexShape convex, Dir d) : Shape(size, convex) {
    //_p1 = p1;
    //_p2 = p2;
    if (d == Up)
    {
        this->setSpeed(sf::Vector2f(0, 5));
    }

    if (d == Down)
    {
        this->setSpeed(sf::Vector2f(0, -5));
    }
    if (d == Right)
    {
        this->setSpeed(sf::Vector2f(-5, 0));
    }
    if (d == Left)
    {
        this->setSpeed(sf::Vector2f(5, 0));
    }

    _d = d;
}


void Rail::update(sf::Time elapsed, Dir d)
{
    float moveX = 0.0;
    float moveY = 0.0;
    if (d == _d)
    {
        this->getConvex().move(this->getSpeed().x, this->getSpeed().y);
    }
}


void Rail::update(sf::Time elapsed) {

}