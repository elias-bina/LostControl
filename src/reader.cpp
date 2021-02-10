//
// Created by peyrichou on 06/02/2021.
//

#include "reader.h"


Reader::Reader(): _shapes(){

}

// Pour l'instant, on considère uniquement des formes, le joeueur est ajouté
// à part
void Reader::construct_and_add_shape(Environnement* env, std::string file) {
    std::ifstream fs(file);
    int nbr_pts;
    int a, b; // Les points (int seulement)
    // Pour un polygone
    for (std::string line; getline(fs, line);) {
        std::istringstream str(line);
        str >> nbr_pts;
        sf::ConvexShape* forme = new sf::ConvexShape(nbr_pts);
        for (int i = 0; i < nbr_pts; i++) {
            str >> a >> b;

            forme->setPoint(i, sf::Vector2f(a, b));
        }
        _shapes.push_back(forme);
        Shape *ent = new Shape(env->getWorld(), forme);
        env->add_entity(ent);
    }
    fs.close();

}

std::vector<sf::Shape*> Reader::getShapes() {
    return _shapes;
}


