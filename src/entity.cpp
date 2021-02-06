#include "entity.h"


Entity::Entity(b2World* world, const b2BodyDef* bodyDef, sf::Sprite* sprite) {
    _sprite = sprite;
    _body = world->CreateBody(bodyDef);
}

const sf::Vector2f& Entity::getPosition() const {
    static sf::Vector2f v;
    v.x = _body->GetPosition().x;
    v.y = _body->GetPosition().y;
    std::cout << "Pos : " << _body->GetPosition().x << ";" << _body->GetPosition().y << std::endl;

    return v;
}


void Entity::draw(sf::RenderTexture& texture) const {
    _sprite->setPosition(getPosition());
    texture.draw(*_sprite);
}