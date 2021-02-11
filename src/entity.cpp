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

const sf::Vector2f& Entity::getScreenPosition() const
{
    return worldToScreen(boxToSfVec(getWorldPosition()));
}

const b2Vec2& Entity::getWorldPosition() const
{
    return _body->GetPosition();
}


void Entity::draw(sf::RenderTexture& texture, sf::RenderWindow& window) const {
    _sprite->setPosition(getScreenPosition() - toFloatVec(_sprite->getTexture()->getSize()) / 2.0f);

   // std::cout << "Pos : " << _body->GetPosition().x << ";" << _body->GetPosition().y << std::endl;
    //std::cout << "Screen pos : " <<screenPos.x << ";" << screenPos.y << std::endl;

    texture.draw(*_sprite);
}

