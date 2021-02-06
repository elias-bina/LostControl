#ifndef _ENVIRONNEMENT_H_

#define _ENVIRONNEMENT_H_


#include <iostream>
#include <vector>

#include "entity.h"
#include "player.h"

class Environnement{
    public:
        Environnement();
        void draw_env(sf::RenderTexture& texture);
        void update_env(sf::Time& elapsed);
        void add_entity(Entity* entity);
    private:
        std::vector<Entity*> _entities;

};

#endif //_ENTITIES_H_