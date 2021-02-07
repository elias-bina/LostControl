#pragma once


#include "shape.h"

enum Dir { Up, Down, Right, Left };

class Rail : Shape {
public:
	Rail(sf::Vector2f size, sf::ConvexShape convex, Dir d);
	void update(sf::Time elapsed, Dir d);
	virtual void update(sf::Time elapsed);


private:
	//sf::Vector2f _p1;
	//sf::Vector2f _p2;
	Dir _d;
};
