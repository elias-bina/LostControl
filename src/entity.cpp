#include "entity.h"


Entity::Entity(sf::Vector2f size, sf::Sprite* sprite): _speed(), _pos(), _size_init(size), _size(size){
    _sprite = sprite;
}