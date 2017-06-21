#include "space_object.hpp"

#include <cmath>
#include <iostream>

int update_frequency = 100;

void SpaceObject::nextStep(int)
{
	std::cerr << "ERROR: SpaceObject::nextStep." << std::endl;
};

double SpaceObject::getSpeed()
{
	return sqrt(pow(xChange,2)+pow(yChange,2));
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

double SpaceObject::getAz()
{
	return azimuth;
};


void set_update_frequency(int i)
{
	update_frequency = i;
};

int get_update_frequency()
{
	return update_frequency;
};