#ifndef COLLISION_ZONE
#define COLLISION_ZONE

#include <vector>

struct Point
{
	double x;
	double y;
};

struct Line
{	
	Point first;
	Point last;	
};

struct Rectangle
{
	Line side1;
	Line side2;
	Line side3;
	Line side4;
	
	Rectangle(Point, Point, Point, Point);
};

class CollisionZone
{
private:
	std::vector<Rectangle> Zones; 	
public:
	void createFourZones(Point centre, double azimuth, int height, int width, double cellSize);
};
#endif