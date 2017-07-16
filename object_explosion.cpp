#include "object_explosion.hpp"



void ObjectExplosion::coordinateReckon()
{
	Point p = this->getPoint();
	xCurrent = p.x;
	yCurrent = p.y;
};

void ObjectExplosion::attributesReckon()
{
	
};

void ObjectExplosion::prepareCollision()
{
	//need
};

bool ObjectExplosion::cellEmpty(const Index&) const
{
	return false;
};

Point ObjectExplosion::getZeroPosition() const
{
	return pointFromDistance(Point{xCurrent, yCurrent}, Azimuth(azimuth+270), Distance{boxSize, boxSize});
};

Point ObjectExplosion::getIndexPosition(const Index&) const
{
	//?
};

void ObjectExplosion::cellDamaged(const Index& cell, const double& damage)
{
	//?
};	

double ObjectExplosion::getWeight() const
{
	//?
};