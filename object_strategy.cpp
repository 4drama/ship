#include "object_strategy.hpp"

#include "geometry.hpp"
#include <cassert>

TimeLimitedObject::TimeLimitedObject(const unsigned int life_)
{
	life = life_ * update_frequency;
};

bool TimeLimitedObject::decrementLife()
{
	assert(life != 0);
	return (--life == 0)	?	true	:	false;
};

FollowingObject::FollowingObject(SpaceObject* leadingObject_, const Index& coordinateIndex_, const Distance& offset_)
								:		leadingObject(leadingObject_), coordinateIndex(coordinateIndex_), offset(offset_)
{
	
};

Point FollowingObject::getPoint() const
{
	return leadingObject->getIndexPosition(coordinateIndex) + offset;
};