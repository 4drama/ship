#include "collision.hpp"

#include <algorithm>

#include <iostream>

bool collisionBoxCheck (	double obj1_x, double obj1_y, double obj1_box,
						double obj2_x, double obj2_y, double obj2_box)
{
	double o1x1 = (obj1_x - obj1_box);
	double o1x2 = (obj1_x + obj1_box);
	double o1y1 = (obj1_y - obj1_box);
	double o1y2 = (obj1_y + obj1_box);
	
	double o2x1 = (obj2_x - obj2_box);
	double o2x2 = (obj2_x + obj2_box);
	double o2y1 = (obj2_y - obj2_box);
	double o2y2 = (obj2_y + obj2_box);
	
//	std::cout << std::endl	<< "object 1: x(" << o1x1 << "," <<  o1x2 << ") y(" << o1y1 << "," << o1y2 << ")" << std::endl;
//	std::cout 				<< "object 2: x(" << o2x1 << "," <<  o2x2 << ") y(" << o2y1 << "," << o2y2 << ")" << std::endl;
	
	bool check =	(
		(	((o1x1 <= o2x1) && (o1x2 >= o2x1)) ||
			((o1x1 <= o2x2) && (o1x2 >= o2x2))	)
		&&
		(	((o1y1 <= o2y1) && (o1y2 >= o2y1)) ||
			((o1y1 <= o2y2) && (o1y2 >= o2y2))	)
					);
	
//	std::cout << "Check :" << check << std::endl << std::endl;
	
	return check;
};

bool conformityPairCheck(	
		std::pair< std::shared_ptr<SpaceObject>, std::shared_ptr<SpaceObject> > objPair,
		std::shared_ptr<SpaceObject> obj1, std::shared_ptr<SpaceObject> obj2)
{
	if	(
		(objPair.first == obj1 && objPair.second == obj2)	||
		(objPair.first == obj2 && objPair.second == obj1)
		)
		{
			return true;
		}
	else
		{
			return false;
		}		
};


//reckon Collision.  NEED REMAKE. NOT EFFECTIVE	
void collisionListCheck	(	Collision_list_type& collList, Object_list_type& objList)
{
	std::for_each(	objList.begin(), objList.end(), 		
			[&objList, &collList](std::shared_ptr<SpaceObject> obj1)
			{
				// FIND COLLISION
				for ( auto obj2it = objList.begin(); obj2it!=objList.end(); obj2it++ )
				{
					if(obj1 == *obj2it)
					{
						continue;
					}
					if(collisionBoxCheck (	(*obj2it)->getX(),	(*obj2it)->getY(),	(*obj2it)->getBox(),
										obj1->getX(), 		obj1->getY(), 		obj1->getBox() ))
					{							
					// ADD UNIQUE COLLISION IN COLLISIONLIST
							auto collListIt = std::find_if(	collList.begin(), collList.end(),
							[obj1, obj2it](auto objs)
							{	
							 	return conformityPairCheck(objs, obj1, *obj2it);
							});
							
							if(collListIt == collList.end())
							{
									
								collList.push_back(	std::make_pair(obj1,*obj2it)	);
								
								std::cout	<< std::fixed << "Collision:" << std::endl <<"Ship first x=" << obj1->getX() << " y=" << obj1->getY() 
								<< " Ship second x=" << (*obj2it)->getX() << " y=" << (*obj2it)->getY() << std::endl << std::endl;
							};
												
					};
				};
			});
};	

void collisionBoxCheck	(	Collision_list_type& collList)
{
	std::for_each(	collList.begin(), collList.end(), 		
			[](auto objPair)
			{
				objPair.first->prepareCollision();
				objPair.second->prepareCollision();
				
				//
				//COLLISION
				//
			});
};				

Collision_list_type createCollisionList()
{
	Collision_list_type list;
	return list;
};