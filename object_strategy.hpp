#ifndef OBJECT_STRATEGY__
#define OBJECT_STRATEGY__

#include "space_object.hpp"

class TimeLimitedObject;
class FollowingObject;

class TimeLimitedObject
{
private:
	unsigned int life = 1;
protected:
	TimeLimitedObject(const unsigned int);
	
	bool decrementLife();
};

class FollowingObject
{
private:
	SpaceObject* leadingObject;
	Index coordinateIndex;
	Distance offset;
protected:
	FollowingObject(SpaceObject*, const Index&, const Distance&);
	
	Point getPoint() const;
};

#endif