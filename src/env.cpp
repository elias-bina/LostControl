
#include "env.h"

Environnement::Environnement(): _entities(){
    _world = new b2World(b2Vec2(0, -9.81));
    Entity* p1 = new Player(_world);
    _entities.push_back(p1);
}

void Environnement::add_entity(Entity* entity){
    _entities.push_back(entity);
}

void Environnement::draw_env(sf::RenderTexture& texture){
    for_each(_entities.begin(), _entities.end(), [&texture](const Entity* e){e->draw(texture);}); 
}

void Environnement::update_env(sf::Time& elapsed){
    for_each(_entities.begin(), _entities.end(), [&elapsed](Entity* e){e->update(elapsed);});
    _world->Step(1.f / 6.f, 8, 3);
}