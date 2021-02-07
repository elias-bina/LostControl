#include "shape.h"
#include "entity.h"


b2BodyDef * Shape::bodyDef = nullptr;

const b2BodyDef* Shape::getBodyDef()
{
    if (!bodyDef) {
        bodyDef = new b2BodyDef();
        bodyDef->type = b2_dynamicBody;
    }
    return bodyDef;
}


Shape::Shape(sf::ConvexShape* convex, b2World* world) : Entity(world, Shape::getBodyDef(), nullptr) {
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
