
#include "env.h"
#include "utils.h"

Environnement::Environnement(): _entities(){
    _world = new b2World(b2Vec2(0, -9.81));
    Entity* p1 = new Player(_world, 0);
    Entity* p2 = new Player(_world, 1);
    _entities.push_back(p1);
    _entities.push_back(p2);

    b2BodyDef ground;
    ground.position.Set(400 * METERS_PER_PIXELS, -800 * METERS_PER_PIXELS);
    b2Body * groundBody = _world->CreateBody(&ground);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(800 / 2 * METERS_PER_PIXELS, 1 * METERS_PER_PIXELS);
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void Environnement::add_entity(Entity* entity){
    _entities.push_back(entity);
}

void Environnement::draw_env(sf::RenderTexture& texture, sf::RenderWindow& window){
    for_each(_entities.begin(), _entities.end(), [&texture, &window](const Entity* e){e->draw(texture, window);});
}

void Environnement::update_env(sf::Time& elapsed){
    for_each(_entities.begin(), _entities.end(), [&elapsed](Entity* e){e->update(elapsed);});
    _world->Step(1.f / 60.f, 8, 3);
}

b2World* Environnement::getWorld() {
    return _world;
}


Environnement::~Environnement(){
    delete _world;
    for_each(_entities.begin(), _entities.end(),[](Entity*e){delete e;});
}