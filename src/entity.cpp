#include "entity.h"
#include "utils.h"

Entity::Entity(b2World* world, const b2BodyDef* bodyDef, sf::Sprite* sprite, EntityType type) {
    _sprite = sprite;
    _body = world->CreateBody(bodyDef);
    _body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
    _type = type;
}

EntityType Entity::getType()
{
    return _type;
}

void Entity::draw(sf::RenderTexture& texture, sf::RenderWindow& window) const {
    sf::Vector2f screenPos = worldToScreen(boxToSfVec(_body->GetPosition()));
    _sprite->setPosition(screenPos - toFloatVec(_sprite->getTexture()->getSize()) / 2.0f);

   // std::cout << "Pos : " << _body->GetPosition().x << ";" << _body->GetPosition().y << std::endl;
    //std::cout << "Screen pos : " <<screenPos.x << ";" << screenPos.y << std::endl;

    texture.draw(*_sprite);
}

