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

/*void collisionReckon()
{
	
};*/

void ObjectList::nextStep()
{
	this->attributesReckon();	
	this->coordinateReckon();
	
	auto collisionList = createCollisionList();
	
	collisionListCheck(collisionList, list);
	
	std::for_each(	collisionList.begin(), collisionList.end(), 		
		[](auto i)
		{
			i.collisionReckon();
		});
		
	
//	collisionBoxCheck(collisionList);
	
};