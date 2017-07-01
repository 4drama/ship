#ifndef SPACE_OBJECT__
#define SPACE_OBJECT__

#include "collision_zone.hpp"

class SpaceObject
{
protected:
	typedef double Coordinate_type;
	typedef double Azimuth_type;
	
	Coordinate_type boxSize = 0;
	
	Coordinate_type xCurrent = 0;
	Coordinate_type yCurrent = 0;
	
	Coordinate_type xChange = 0;
	Coordinate_type yChange = 0;	
	
	Azimuth_type azimuth = 0;
	
	CollisionZone zones;
	
	double getSpeed();

public:
//	virtual void nextStep(int);
	virtual void coordinateReckon();
	virtual void attributesReckon();
	virtual void prepareCollision();

	void setPosition(Coordinate_type, Coordinate_type, Azimuth_type);
	
	double getX();
	double getY();
	double getAz();
	double getBox();
	
};

void set_update_frequency(int);

int get_update_frequency();

#endif