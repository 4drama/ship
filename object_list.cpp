#include "object_list.hpp"

#include <iostream>
#include <algorithm>

#include "collision.hpp"

void ObjectList::attributesReckon()
{
	std::for_each(	list.begin(), list.end(), 		
		[](std::shared_ptr<SpaceObject> i)
		{
			i->attributesReckon();
		});
};

void ObjectList::coordinateReckon()
{
	std::for_each(	list.begin(), list.end(), 		
		[](std::shared_ptr<SpaceObject> i)
		{
			i->coordinateReckon();
		});
};

void ObjectList::nextStep()
{
	this->attributesReckon();	
		
	auto collisionList = createCollisionList();
	
	collisionListCheck(collisionList, list);
	collisionBoxCheck(collisionList);
	
	//only if ship not collising. NEED REMAKE. NOT WORK
	this->coordinateReckon();
};