#include "shape.h"
#include "entity.h"
#include "utils.h"



Shape::Shape(b2World * world, sf::ConvexShape* convex) : Shape(world, getDefaultDynamicBodyDef(), convex) {}


Shape::Shape(b2World * world, const b2BodyDef* bodyDef, sf::ConvexShape* convex) : Entity(world, bodyDef, nullptr) {
    _convex = convex;
}

Shape::~Shape() {

}

void Shape::update(sf::Time elapsed) {
    int a = 0;
}

void Shape::draw(sf::RenderTexture& texture, sf::RenderWindow& window) const {
    window.draw(*_convex);
}

sf::ConvexShape* Shape::getConvex() {
    return _convex;
}
