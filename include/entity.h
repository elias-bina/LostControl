#ifndef _ENTITIES_H_

#define _ENTITIES_H_

#include <iostream>
#include <SFML/Graphics.hpp>


class Entity{
    
    public:
        Entity(sf::Vector2f size, sf::Sprite* sprite);


    private:

        sf::Sprite *_sprite;
        sf::Vector2f _speed;
        sf::Vector2f _pos;
        sf::Vector2f _size_init;
        sf::Vector2f _size;


};


#endif //_ENTITIES_H_
