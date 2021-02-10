#include "contact_listener.h"
#include "entity.h"

void applyToContactEntities(b2Contact * contact, void (*lambda)(Entity*, Entity*, b2Contact *,const b2Vec2&))
{
    Entity* e1 = reinterpret_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
    Entity* e2 = reinterpret_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
    
    // Le vecteur normal pointe de e1 vers e2
    lambda(e1, e2, contact, contact->GetManifold()->localNormal);
    // Inversion du vecteur normal pour qu'il pointe de e2 vers e1
    lambda(e2, e1, contact, 100 * contact->GetManifold()->localNormal);
}

void CustomEngineContactListener::BeginContact(b2Contact* contact)
{
    applyToContactEntities(contact, [](Entity *e1, Entity * e2, b2Contact *c, const b2Vec2& v) {
        if (c->IsTouching())
          e1->startContact(e2, v);
        });
}
    
void CustomEngineContactListener::EndContact(b2Contact* contact)
{
    applyToContactEntities(contact, [](Entity *e1, Entity * e2, b2Contact *c, const b2Vec2 &v) {e1->endContact(e2, v);});
}