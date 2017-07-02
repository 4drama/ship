#ifndef COLLISION_ZONE
#define COLLISION_ZONE

#include <vector>

#include "geometry.hpp"

class CollisionZone
{
private:
	std::vector<Rectangle> Zones; 	
public:
	void createFourZones(Point centre, double azimuth, int height, int width, double cellSize);
};

#endif