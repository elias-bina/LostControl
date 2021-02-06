
#include "env.h"

class DrawF{
    public:
        DrawF(sf::RenderTexture& tex): _tex(tex){};

        void operator()(const Entity* e){
            e->draw(_tex);
        }

        sf::RenderTexture& _tex;
};

class UpdateF{
    public:
        UpdateF(sf::Time elapsed): _elapsed(elapsed){};

        void operator()(Entity* e){
            e->update(_elapsed);
        }

        sf::Time _elapsed;
};

Environnement::Environnement(): _entities(){

    Entity* p1 = new Player();
    _entities.push_back(p1);
}

void Environnement::draw_env(sf::RenderTexture& texture){
    for_each(_entities.begin(), _entities.end(), DrawF(texture)); 
}

void Environnement::update_env(sf::Time elapsed){
    for_each(_entities.begin(), _entities.end(), UpdateF(elapsed)); 
}