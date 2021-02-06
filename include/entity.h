#ifndef _ENTITIES_H_

#define _ENTITIES_H_

#include <iostream>
#include <SFML/Graphics.hpp>


class Entity{
    
    public:
        Entity(sf::Vector2f size, sf::Sprite* sprite);
        virtual void draw(sf::RenderTexture& texture) const;
        virtual void update(sf::Time elapsed) = 0;
        
        sf::Sprite *_sprite;

    private:

        sf::Vector2f _speed;
        sf::Vector2f _pos;
        sf::Vector2f _size_init;
        sf::Vector2f _size;


};


#endif //_ENTITIES_H_
