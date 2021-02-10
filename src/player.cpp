
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


Player::Player(b2World* world, int inputNumber) : Entity(world, Player::getBodyDef(), nullptr, EntityType::PLAYER){
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
    _body->SetFixedRotation(true);
        
    _sprite = sprite;
    _controller = new KeyboardInput(inputNumber);
}

Player::~Player()
{
    //delete _sprite->getTexture();
    delete _sprite;
    delete _controller;
}


void Player::startContact(Entity* other, const b2Vec2& normal) {
        std::cout << "Contact with @" << other << ", normal " << normal.y << ";" << normal.x << std::endl;
    if (normal.y < 0)
    {
        _jumpingPlatforms.insert(other);
        std::cout << "Contact with @" << other << std::endl;
    }
}

void Player::endContact(Entity* other, const b2Vec2& normal) {    
    _jumpingPlatforms.erase(other);
    std::cout << "End of contact with @" << other << std::endl;
}

void Player::update(sf::Time elapsed){
    b2Vec2 v = b2Vec2((_controller->getRight() - _controller->getLeft() ) * 0.1, 0); 
    if (_jumpingPlatforms.size())
    {
        if (_jumpClock.getElapsedTime().asMilliseconds() > 100 && _controller->getAction()) {
            v.y = 5;
            std::cout << "Jumped !" << std::endl;
            _jumpClock.restart();
        }
    }   
    else
        v.x *= 0.5;

    v *= _body->GetMass();
   _body->ApplyLinearImpulseToCenter(v, true);
}