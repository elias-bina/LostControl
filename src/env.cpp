
#include "env.h"

Environnement::Environnement(): _entities(){
    Entity* p1 = new Entity(sf::Vector2f(), nullptr);
    _entities.push_back(p1);
}