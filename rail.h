#pragma once


#include "shape.h"

class Rail : Shape {
public:
	Rail(sf::Vector2f size, sf::ConvexShape convex, sf::Vector2f p1, sf::Vector2f p2);
	void update(sf::Time elapsed, Dir d);


private:
	sf::Vector2f _p1;
	sf::Vector2f _p2;

};
