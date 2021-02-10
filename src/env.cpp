
#include "env.h"
#include "utils.h"

Environnement::Environnement(): _entities(){
    _contactListener = new CustomEngineContactListener();

    _world = new b2World(b2Vec2(0, -9.81));
    _world->SetContactListener(_contactListener);
    Entity* p1 = new Player(_world, 0);
    Entity* p2 = new Player(_world, 1);
    _entities.push_back(p1);
    _entities.push_back(p2);

    //TODO: bouger ces variables dans un module central 
    const int SCREEN_W = 800, SCREEN_H = 600, GROUND_W = SCREEN_W * 2, GROUND_H = 10;

    sf::Shape * shape = new sf::RectangleShape(sf::Vector2f(GROUND_W, GROUND_H));
    add_entity(new Shape(_world, shape, sf::Vector2f(SCREEN_W / 2- GROUND_W / 2, SCREEN_H - GROUND_H)));
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
    delete _contactListener;
    delete _world;
    for_each(_entities.begin(), _entities.end(),[](Entity*e){delete e;});
}