#include "object_list.hpp"

#include <iostream>
#include <algorithm>

#include "collision.hpp"


void ObjectList::nextStep(int count)
{
	std::for_each(	list.begin(), list.end(), 		
			[count](std::shared_ptr<SpaceObject> i)
			{
				i->attributesReckon();
			});
	
	
	typedef std::vector< std::pair< std::shared_ptr<SpaceObject> ,std::shared_ptr<SpaceObject> > >	Collision_list_type;		
	Collision_list_type collisionList;
	
	
	//reckon Collision.  NEED REMAKE. NOT EFFECTIVE
	std::for_each(	list.begin(), list.end(), 		
			[this, &collisionList](std::shared_ptr<SpaceObject> i)
			{
				// FIND COLLISION
				for ( auto it = list.begin(); it!=list.end(); it++ )
				{
					if(i == *it)
					{
						continue;
					}
					if(collisionBoxCheck (	(*it)->getX(),	(*it)->getY(),	(*it)->getBox(),
										i->getX(), 		i->getY(), 		i->getBox() ))
					{							
					// ADD UNIQUE COLLISION IN COLLISIONLIST
							auto it2 = std::find_if(	collisionList.begin(), collisionList.end(),
							[i, it](auto objs)
							{	
							 	return conformityPairCheck(objs, i, *it);
							});
							
							if(it2 == collisionList.end())
							{
									
								collisionList.push_back(	std::make_pair(i,*it)	);
								
								std::cout	<< std::fixed << "Collision:" << std::endl <<"Ship first x=" << i->getX() << " y=" << i->getY() 
								<< " Ship second x=" << (*it)->getX() << " y=" << (*it)->getY() << std::endl << std::endl;
							};
												
					};
				};
				
			});
	
	//only if ship not collising. NEED REMAKE. NOT WORK
	std::for_each(	list.begin(), list.end(), 		
			[count](std::shared_ptr<SpaceObject> i)
			{
				i->coordinateReckon();
			});
};