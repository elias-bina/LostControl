
#include "env.h"
#include "utils.h"

Environnement::Environnement(): _entities(){
    _world = new b2World(b2Vec2(0, -9.81));
    Entity* p1 = new Player(_world, 0);
    Entity* p2 = new Player(_world, 1);
    _entities.push_back(p1);
    _entities.push_back(p2);

    //TODO: bouger ces variables dans un module central 
    const int SCREEN_W = 800, SCREEN_H = 600, GROUND_W = SCREEN_W * 2, GROUND_H = 10;

    b2BodyDef ground;
    ground.position.Set(SCREEN_W / 2 * METERS_PER_PIXELS, (-SCREEN_H + GROUND_H) * METERS_PER_PIXELS);
    b2Body * groundBody = _world->CreateBody(&ground);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(GROUND_W / 2 * METERS_PER_PIXELS, GROUND_H / 2 * METERS_PER_PIXELS);
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