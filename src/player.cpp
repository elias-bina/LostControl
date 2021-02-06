
#include "player.h"

b2BodyDef * Player::bodyDef = nullptr;
    
const b2BodyDef* Player::getBodyDef()
{
    if (!bodyDef) {
        bodyDef = new b2BodyDef();
        bodyDef->type = b2_dynamicBody;
    }
    return bodyDef;
}


Player::Player(b2World* world, int inputNumber) : Entity(world, Player::getBodyDef(), nullptr){
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
    delete _sprite->getTexture();
    delete _sprite;
    delete _controller;
}

void Player::update(sf::Time elapsed){
    const float absV = 1.2f;
    b2Vec2 v = b2Vec2((_controller->getRight() - _controller->getLeft() ),  (_controller->getAction() - sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ));
    const float mag = sqrt(v.x * v.x + v.y * v.y);
    if (mag) {
        v.x *= absV / mag;
        v.y *= absV / mag;
    }

   _body->SetLinearVelocity(v);
}