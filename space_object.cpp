#include "space_object.hpp"

#include <cmath>


double SpaceObject::getSpeed()
{
	return sqrt(pow(xChange,2)+pow(yChange,2));
};
