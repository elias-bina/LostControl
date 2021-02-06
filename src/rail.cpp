#include "rail.h"
#include "shape.h"


Rail::Rail(sf::Vector2f size, sf::ConvexShape convex, sf::Vector2f p1, sf::Vector2f p2) : Shape(size, convex) {
    _p1 = p1;
    _p2 = p2;
}

void Rail::update(sf::Time elapsed, Dir d) 
{
    if (d == Up) 
    {

    }

}