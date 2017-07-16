#ifndef SPACE_OBJECT__
#define SPACE_OBJECT__

#include "collision_zone.hpp"

//double shipCellSize = 0.05;
extern int update_frequency;
extern double shipCellSize;

class ObjectList;

class SpaceObject
{
protected:
	typedef double Coordinate_type;
	typedef double Azimuth_type;
	
	ObjectList* list;
	
	Coordinate_type boxSize = 0;
	
	Coordinate_type xCurrent = 0;
	Coordinate_type yCurrent = 0;
	
	Coordinate_type xChange = 0;
	Coordinate_type yChange = 0;	
	
	Azimuth_type azimuth = 0;
	
	CollisionZone zones;
	
	double getSpeed();

public:

	SpaceObject(ObjectList*, int, int, double);

//	virtual void nextStep(int);
	virtual void coordinateReckon();
			void coordinateBack();
	
	virtual void attributesReckon();
	virtual void prepareCollision();
	
	virtual bool cellEmpty(const Index&) const = 0;
//	virtual void cellDamaged(const Index& cell, const Point& coordinate, const double&& damage) = 0;
	virtual void cellDamaged(const Index& cell, const double& damage) = 0;
	
	void setPosition(Coordinate_type, Coordinate_type, Azimuth_type);
	
	double getX();
	double getY();
	
	double getXch() const;
	double getYch() const;
	
	void setChangeCoordinate(Coordinate_type x, Coordinate_type y);
	
	double getAz();
	double getBox();
	
	virtual double getWeight() const = 0;
	virtual Point getZeroPosition() const = 0;
	virtual Point getIndexPosition(const Index&) const = 0;
	
	CollisionZone* getZones();
};

void set_update_frequency(int);

int get_update_frequency();

#endif