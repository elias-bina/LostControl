
#include "player.h"


Player::Player(int inputNumber) : Entity(sf::Vector2f(100, 100), nullptr){
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
    _controller = new KeyboardInput(inputNumber);
}

Player::~Player()
{

}

void Player::update(sf::Time elapsed){
    _pos.x += (_controller->getRight() - _controller->getLeft() )*0.001*elapsed.asMicroseconds();
    _pos.y += (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )*0.001*elapsed.asMicroseconds();
}