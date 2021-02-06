
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
    _pos.x += (sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )*0.001*elapsed.asMicroseconds();
    _pos.y += (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )*0.001*elapsed.asMicroseconds();
}