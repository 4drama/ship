#include "space_object.hpp"

#include <cmath>
#include <iostream>

int update_frequency = 100;
double shipCellSize = 0.05;

SpaceObject::SpaceObject(	ObjectList* list_, int size, int size_2, double CellSize)
						:	list(list_)
{
	boxSize = sqrt(pow(size*CellSize,2)+pow(size_2*CellSize,2))/2;
};

/*void SpaceObject::nextStep(int)
{
	std::cerr << "ERROR: SpaceObject::nextStep." << std::endl;
};*/

void SpaceObject::coordinateReckon()
{
	std::cerr << "ERROR: SpaceObject::coordinateReckon." << std::endl;
};

void SpaceObject::coordinateBack()
{
	xCurrent -= xChange;
	yCurrent -= yChange;
};

void SpaceObject::attributesReckon()
{
	std::cerr << "ERROR: SpaceObject::attributesReckon." << std::endl;
};

void SpaceObject::prepareCollision()
{
	std::cerr << "ERROR: SpaceObject::prepareCollision." << std::endl;
};

double SpaceObject::getSpeed()
{
	return sqrt(pow(xChange,2)+pow(yChange,2));
};

CollisionZone* SpaceObject::getZones()
{
	return &zones;
};

void SpaceObject::setPosition(Coordinate_type x, Coordinate_type y, Azimuth_type az)
{
	xCurrent = x;
	yCurrent = y;
	azimuth = az;
};

double SpaceObject::getX()
{
	return xCurrent;
};

double SpaceObject::getY()
{
	return yCurrent;
};

double SpaceObject::getXch() const
{
	return xChange;
};

double SpaceObject::getYch() const
{
	return yChange;
};

void SpaceObject::setChangeCoordinate(Coordinate_type x, Coordinate_type y)
{
	xChange = x;
	yChange = y;
};

double SpaceObject::getAz()
{
	return azimuth;
};

double SpaceObject::getBox()
{
	return boxSize;
};

void set_update_frequency(int i)
{
	update_frequency = i;
};

int get_update_frequency()
{
	return update_frequency;
};