#ifndef COLLISION_ZONE
#define COLLISION_ZONE

#include <vector>

#include "geometry.hpp"

struct Index
{
	int i;
	int j;
};

class CollisionZone
{
private:
	
public:

	std::vector<Rectangle> Zones;
	
	std::vector<std::pair<Index,Index> > indexs;
	
	int size;
	
	int xSize;
	int ySize;
	
	void createFourZones(Point centre, double azimuth, int height, int width, double cellSize);
	
//	Rectangle& operator[] (int x);
//	std::vector<Rectangle>* getVector();
};

#endif