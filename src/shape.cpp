#include "shape.h"
#include "entity.h"


Shape::Shape(sf::Vector2f size, sf::ConvexShape convex) : Entity(size, nullptr) {
    _convex = convex;
}

sf::ConvexShape Shape::getConvex() {
    return _convex;
}
