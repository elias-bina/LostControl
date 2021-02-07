#include "utils.h"


const b2BodyDef* getDefaultDynamicBodyDef()
{
    static b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    return &bodyDef;
}


void normalize(float& x, float& y, float mag)
{
    const float currentMag = sqrt(x * x + y * y);
    if (currentMag) {
        x *= mag / currentMag;
        y *= mag / currentMag;
    }
}


void normalize(b2Vec2& vec, float mag)
{
   normalize(vec.x, vec.y, mag);
}

void normalize(sf::Vector2f& vec, float mag)
{
    normalize(vec.x, vec.y, mag);
}

const b2Vec2& sfToBoxVec(const sf::Vector2f& vec)
{
    static b2Vec2 ret;
    ret.x = vec.x;
    ret.y = vec.y;
    return ret;
}
const sf::Vector2f& boxToSfVec(const b2Vec2& vec)
{
    static sf::Vector2f ret;
    ret.x = vec.x;
    ret.y = vec.y;
    return ret;
}

const sf::Vector2f& worldToScreen(const sf::Vector2f& v)
{
    static sf::Vector2f vec;
    vec.x = v.x / METERS_PER_PIXELS;
    vec.y = -v.y / METERS_PER_PIXELS;
    return vec;
}

const sf::Vector2f& screenToWorld(const sf::Vector2f& v)
{
    static sf::Vector2f vec(v);
    vec.x = v.x * METERS_PER_PIXELS;
    vec.y = -v.y * METERS_PER_PIXELS;
    return vec;
}