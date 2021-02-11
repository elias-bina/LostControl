
#include "player.h"
#include "utils.h"
#include "Thor/Vectors.hpp"

b2BodyDef * Player::bodyDef = nullptr;
    
const b2BodyDef* Player::getBodyDef()
{
    if (!bodyDef) {
        bodyDef = new b2BodyDef();
        bodyDef->type = b2_dynamicBody;
    }
    return bodyDef;
}


Player::Player(b2World* world, int inputNumber) : Entity(world, Player::getBodyDef(), nullptr, EntityType::PLAYER), _jumpDir(1, 0){
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
    if (true || normal.y < 0)
    {
        _jumpingPlatforms.insert(other);
        std::cout << "Contact with @" << other << std::endl;
    }
}

void Player::endContact(Entity* other, const b2Vec2& normal) {    
    _jumpingPlatforms.erase(other);
    std::cout << "End of contact with @" << other << std::endl;
}

void Player::draw(sf::RenderTexture& texture, sf::RenderWindow& fenetre) const
{
    Entity::draw(texture, fenetre);
    float jumpLength = 40;
    sf::Vertex line[] = {sf::Vertex(getScreenPosition()), sf::Vertex(getScreenPosition() + _jumpDir * jumpLength)};
    texture.draw(line, 2, sf::Lines);

   // std::cout << line[0].position.x << ";" << line[0].position.y << " => " << line[1].position.x << ";" << line[1].position.y << std::endl;
}

void Player::update(sf::Time elapsed){
    if (_jumpingPlatforms.size())
    {
        if (_jumpClock.getElapsedTime().asMilliseconds() > 500 && _controller->getAction()) {
            std::cout << "Jumped !" << std::endl;
            _jumpClock.restart();
            b2Vec2 v = sfToBoxVec(screenToWorld(_jumpDir * 1000.0f));
            v *= _body->GetMass();
            _body->ApplyLinearImpulseToCenter(v, true);
        }
    }   
    
    float period = 2;
    auto triangulize = [period](float t) { return 2 * abs(t / period - floor(t / period + .5f));}; 
    float angle = - thor::Pi * triangulize(_actionClock.getElapsedTime().asSeconds());
    thor::setPolarAngle(_jumpDir, thor::toDegree(angle));
}