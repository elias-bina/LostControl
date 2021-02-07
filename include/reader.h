
#ifndef _READER_H_

#define _READER_H_

#include <string>
#include <fstream>
#include <sstream>
#include "env.h"
#include "shape.h"

class Reader {
    public:
        Reader();
        void construct_and_add_shape(Environnement* env, std::string file);
        std::vector<sf::ConvexShape*> getShapes();
private:
    std::vector<sf::ConvexShape*> _shapes;


};

#endif