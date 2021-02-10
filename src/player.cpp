
#include "player.h"
#include "utils.h"

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
    if (!texture->loadFromFile(Path::getResource("mouton.png", ResourceType::IMAGE)))
    {
        std::cout << "Ono" << std::endl;
    }
    sprite->setTexture(*texture);

    b2PolygonShape shape;
    // On définit la bonne taille de notre personnage
    // On divise par deux car SetAsBox prend un "rayon"
    float halfW = texture->getSize().x * METERS_PER_PIXELS / 2, halfH = texture->getSize().y * METERS_PER_PIXELS / 2;

    shape.SetAsBox(halfW, halfH);
    std::cout << "Player size " << texture->getSize().x * METERS_PER_PIXELS << "x" << texture->getSize().y * METERS_PER_PIXELS <<std::endl;
   
    b2FixtureDef fix;
    fix.shape = &shape;
    fix.density = 1;
    fix.friction = 0.3;

    _body->CreateFixture(&fix);
        
    _sprite = sprite;
    _controller = new KeyboardInput(inputNumber);
}

Player::~Player()
{
    //delete _sprite->getTexture();
    delete _sprite;
    delete _controller;
}

void Player::update(sf::Time elapsed){
    b2Vec2 v = b2Vec2((_controller->getRight() - _controller->getLeft() ) * 0.25, 0);
    if (_controller->getAction()) {
        if (_body->GetContactList() != nullptr)
        {
            v.y = 0.5;
            std::cout << "Jumped !" << std::endl;
        }
    }
   _body->ApplyForceToCenter(v, true);
}