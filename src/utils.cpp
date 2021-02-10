#include "utils.h"
#include <iostream>

std::string Path::subDirs[] = {
    "config", "images", "levels", "sounds"
};


std::string Path::rootDir = ".";

void Path::configure(const std::string& self)
{
    std::string binaryDir;
    Path::dirname(self, binaryDir);
    rootDir = binaryDir + getDelimiter() + "..";
}

char Path::getDelimiter()
{
    return 
    #ifdef _WIN32 
        '\\'
    #else 
        '/' 
    #endif
    ;
}

void Path::dirname(const std::string& path, std::string& dest)
{
    int index = path.find_last_of(Path::getDelimiter());
    if (index == -1)
        dest.assign(path);
    else if (index == path.size() - 1) // Skip trailing slashes
        index = path.substr(0, -1).find_last_of(Path::getDelimiter());

    dest.assign(path.substr(0, index));
}

const std::string& Path::getRootDir()
{
    return rootDir;
}

const std::string& Path::getResource(const std::string& resName, ResourceType resType)
{  
    static std::string res;
    res.assign(getRootDir() + "/" + subDirs[resType] + "/" + resName);
    return res;
}


const b2BodyDef* getDefaultDynamicBodyDef()
{
    static b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    return &bodyDef;
}

const b2BodyDef* getDefaultStaticBodyDef()
{
    static b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
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

const sf::Vector2f& toFloatVec(const sf::Vector2u& v)
{
    static sf::Vector2f ret;
    ret.x = v.x;
    ret.y = v.y;
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