#include "shape.h"
#include "entity.h"
#include "utils.h"



Shape::Shape(b2World * world, sf::ConvexShape* convex) : Shape(world, getDefaultStaticBodyDef(), convex) {}


Shape::Shape(b2World * world, const b2BodyDef* bodyDef, sf::ConvexShape* convex) : Entity(world, bodyDef, nullptr) {
    _convex = convex;

   std::vector<b2Vec2> points; 
    for (size_t i = 0; i < convex->getPointCount(); i++) {
        points.push_back(sfToBoxVec(screenToWorld(convex->getPoint(i))));
    }

    convex->setFillColor(sf::Color::Red);

    b2PolygonShape shape;
    shape.Set(points.data(), points.size());
    b2FixtureDef fix;
    fix.shape = &shape;
    fix.density = 1;
    fix.friction = 0.3;
    _body->CreateFixture(&fix);  

}

Shape::~Shape() {

}

void Shape::update(sf::Time elapsed) {
    int a = 0;
}

void Shape::draw(sf::RenderTexture& texture, sf::RenderWindow& window) const {
    _convex->setPosition(boxToSfVec(_body->GetPosition()));
    texture.draw(*_convex);
}

sf::ConvexShape* Shape::getConvex() {
    return _convex;
}
