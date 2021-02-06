#ifndef _ENVIRONNEMENT_H_

#define _ENVIRONNEMENT_H_


#include <iostream>
#include <vector>

#include "entity.h"

class Environnement{
    public:
        Environnement();

    private:
        std::vector<Entity*> _entities;

};

#endif //_ENTITIES_H_