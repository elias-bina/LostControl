
#include "player.h"


Player::Player(/* args */) : Entity(sf::Vector2f(100, 100), nullptr){
    sf::Sprite* sprite = new sf::Sprite();
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile("../mouton.png"))
    {
        std::cout << "Ono" << std::endl;
    }
    sprite->setTexture(*texture);

    
    
    
    if(_sprite != NULL){
        delete _sprite;
    }

    _sprite = sprite;
}

Player::~Player()
{

}

void Player::update(sf::Time elapsed){
    return;
}