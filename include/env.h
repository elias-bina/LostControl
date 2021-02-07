#ifndef _ENVIRONNEMENT_H_

#define _ENVIRONNEMENT_H_


#include <iostream>
#include <vector>

#include "entity.h"
#include "player.h"
#include "rail.h"

class Environnement{
    public:
        Environnement();
        ~Environnement();
        void draw_env(sf::RenderTexture& texture);
        void update_env(sf::Time& elapsed);
        void add_entity(Entity* entity);
    private:
        b2World * _world;
        std::vector<Entity*> _entities;

};

#endif //_ENTITIES_H_