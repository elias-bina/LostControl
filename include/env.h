#ifndef _ENVIRONNEMENT_H_

#define _ENVIRONNEMENT_H_


#include <iostream>
#include <vector>

#include "entity.h"
#include "player.h"
#include "rail.h"
#include "contact_listener.h"

class Environnement{
    public:
        Environnement();
        ~Environnement();
        void draw_env(sf::RenderTexture& texture, sf::RenderWindow& window);
        void update_env(sf::Time& elapsed);
        void add_entity(Entity* entity);
        b2World* getWorld();
    private:
        b2World * _world;
        CustomEngineContactListener* _contactListener;
        std::vector<Entity*> _entities;


};

#endif //_ENTITIES_H_