#ifndef _UTILS_H_
#define _UTILS_H_

    #include "SFML/Graphics.hpp"
    #include "box2d/box2d.h"

    #define METERS_PER_PIXELS 0.004f


    const b2BodyDef* getDefaultDynamicBodyDef();

    void normalize(b2Vec2& vec, float mag = 1.0f);
    void normalize(sf::Vector2f& vec, float mag = 1.0f);


    const b2Vec2& sfToBoxVec(const sf::Vector2f& vec); 
    const sf::Vector2f& boxToSfVec(const b2Vec2& vec);

    const sf::Vector2f& worldToScreen(const sf::Vector2f& vec);
    const sf::Vector2f& screenToWorld(const sf::Vector2f& vec);

    class Vector2 : sf::Vector2f, b2Vec2 {
        public:
            using sf::Vector2f::x;
            using sf::Vector2f::y;
    };

#endif