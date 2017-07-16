#ifndef OBJECT_EXPLOSION__
#define OBJECT_EXPLOSION__

#include "space_object.hpp"
#include "object_strategy.hpp"

class ObjectExplosion : public SpaceObject, public TimeLimitedObject, public FollowingObject
{
private:
	
public:
	ObjectExplosion(ObjectList* list, const unsigned int life, SpaceObject* obj, const Index& index, const Distance& dist, const int aoe, const double cellSize)
				:	SpaceObject(list, aoe, aoe, cellSize), 
					TimeLimitedObject(life),
					FollowingObject(obj, index, dist)
	{
		
	};
	
	
	void coordinateReckon() override;
	void attributesReckon() override;
	void prepareCollision() override;
	bool cellEmpty(const Index&) const override;
	Point getZeroPosition() const override;
	Point getIndexPosition(const Index&) const override;
	void cellDamaged(const Index& cell, const double& damage) override;	
	double getWeight() const override;
	
};

#endif