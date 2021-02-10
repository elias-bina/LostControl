#pragma once


#include "shape.h"

enum Dir { Up, Down, Right, Left };

class Rail : Shape {
public:
	Rail(b2World * world, sf::Shape* convex, Dir d);
	void update(sf::Time elapsed, Dir d);
	virtual void update(sf::Time elapsed);


private:
	Dir _d;
};
