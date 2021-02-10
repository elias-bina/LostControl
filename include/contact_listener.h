#ifndef _CONTACT_LISTENER_
#define _CONTACT_LISTENER_
#include "box2d/box2d.h"

class CustomEngineContactListener : public b2ContactListener {
    public:
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
};
#endif