#include "collision.hpp"

#include <algorithm>

#include <iostream>

Collision::Collision	(	std::shared_ptr<SpaceObject> firstObj_, std::shared_ptr<SpaceObject> secondObj_)
						:	firstObj(firstObj_), secondObj(secondObj_)
{

};

void Collision::collisionBox()
{
	indexsColl.resize(10);
	
	firstObj->prepareCollision();
	secondObj->prepareCollision();
	
	auto* firstZones = firstObj->getZones();
	auto* secondZones = secondObj->getZones();
		
	for(int i = 0, size = firstZones->Zones.size(); i<size; ++i)
	{
		for(int j = 0, size = secondZones->Zones.size(); j<size; ++j)
		{
			bool collisionCheck = intersectionRectangle(firstZones->Zones[i], secondZones->Zones[j]);
			if (collisionCheck)
			{
				indexsColl.push_back(std::make_pair(i, j));
				std::cout << "CollisionBox : [" << i << "][" << j << "]" << std::endl; 
			}
		};
	};
};

void Collision::createPoints()
{
//	CollisionZone.xSize
//	firstObj.ySize
//	pointFromDistance(const Point&, const Azimuth&, const Distance&)
	
//	std:: cout << firstObj->getZones()->xSize << " " << firstObj->getZones()->ySize << std::endl;
	
	for (int i = 0, size = firstObj->getZones()->xSize; i < size; ++i)
	{
		for (int j = 0, size2 = firstObj->getZones()->ySize; j < size2; ++j)
		{
			auto p1 = pointFromDistance( firstObj->getZones()->Zones[0].side1.first, Azimuth(firstObj->getAz()+180), Distance{((pSize/2)+(i*pSize)), ((pSize/2)+(j*pSize))});
		//	firstBoxs[0].push_back(p1);
			std::cout << "Add point: [" << i << ":" << j <<"] [" << p1.x << ":" << p1.y << "]" << std::endl << std::endl;
		}
	}
	
};

void Collision::collisionReckon()
{
	this->collisionBox();
	this->createPoints();
};

bool checkEqual(const Collision& first, const Collision& second)
{
	if	(
		(first.firstObj == second.firstObj && first.secondObj == second.secondObj)	||
		(first.firstObj == second.secondObj && first.secondObj == second.firstObj)
		)
		{
			return true;
		}
	else
		{
			return false;
		}	
};

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
/*
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
};*/


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
							 //	return conformityPairCheck(objs, obj1, *obj2it);
								return checkEqual(objs, Collision(obj1, *obj2it));
							});
							
							if(collListIt == collList.end())
							{
									
								collList.push_back(	 Collision(obj1, *obj2it)	);
								
								std::cout	<< std::fixed << "Collision:" << std::endl <<"Ship first x=" << obj1->getX() << " y=" << obj1->getY() 
								<< " Ship second x=" << (*obj2it)->getX() << " y=" << (*obj2it)->getY() << std::endl << std::endl;
							};
												
					};
				};
			});
};	

/*void collisionBoxCheck	(	Collision_list_type& collList)
{
	std::for_each(	collList.begin(), collList.end(), 		
			[](auto objPair)
			{
			//	objPair.first->prepareCollision();
			//	objPair.second->prepareCollision();
				
				//
				//COLLISION
				//
			});
};			*/	

Collision_list_type createCollisionList()
{
	Collision_list_type list;
	return list;
};