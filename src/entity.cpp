#include "entity.h"



Entity::Entity(sf::Vector2f size, sf::Sprite* sprite): _speed(), _pos(), _size_init(size), _size(size){
    _sprite = sprite;
}

void Entity::draw(sf::RenderTexture& texture) const{
    _sprite->move(_pos - _sprite->getPosition());
    sf::FloatRect rect = _sprite->getLocalBounds();
    _sprite->setScale(_size.x/rect.width, _size.y/rect.height);
    texture.draw(*_sprite);

}