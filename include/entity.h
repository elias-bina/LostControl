#ifndef _ENTITIES_H_

#define _ENTITIES_H_

#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

// Only define needed types
typedef enum {OTHER, PLAYER} EntityType;

class Entity{
    
    public:
        Entity(b2World* world, const b2BodyDef* bodyDef, sf::Sprite* sprite, EntityType type = EntityType::OTHER);

        virtual void draw(sf::RenderTexture& , sf::RenderWindow&) const;
        virtual void update(sf::Time elapsed) = 0;

        virtual void startContact(Entity* other, const b2Vec2& normal) {};
        virtual void endContact(Entity* other, const b2Vec2& normal) {};

        virtual const sf::Vector2f& getScreenPosition() const;
        virtual const b2Vec2& getWorldPosition() const;

        EntityType getType();

        virtual ~Entity(){};

    protected:
        sf::Sprite *_sprite;
        b2Body* _body;
        EntityType _type;
};


#endif //_ENTITIES_H_
