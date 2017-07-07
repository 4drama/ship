#include "collision.hpp"

#include <algorithm>

#include <iostream>

Collision::Collision	(	std::shared_ptr<SpaceObject> firstObj_, std::shared_ptr<SpaceObject> secondObj_)
						:	firstObj(firstObj_), secondObj(secondObj_)
{

};

void Collision::collisionBox()
{
	indexsColl.reserve(10);
	
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
				
				this->addUnique(i ,uniqueBoxCollisionFirst);
				this->addUnique(j ,uniqueBoxCollisionSecond);
				
				std::cout << "CollisionBox : [" << i << "][" << j << "]" << std::endl; 
			}
		};
	};
};

void Collision::addPoints(const Index& begin, const Index& end, const int boxNumber, const std::shared_ptr<SpaceObject>& object, std::vector<Points_pairs_type>& boxs)
{
	std::cout << std::endl << "Collision::addPoints " << boxNumber << " begin: " << begin.i << " " <<begin.j << " end: " << end.i << " " << end.j << std::endl;
	
	int sz = (begin.i+1-end.i)*(end.j + 1 - begin.j);	
	boxs[boxNumber].reserve(std::move(sz));
	
	for (int i = begin.i, size = end.i - 1; i > size; --i)
	{
		for (int j =  begin.j, size2 = end.j + 1 ; j < size2; ++j)
		{
			auto p1 = pointFromDistance( object->getZones()->Zones[boxNumber].side1.first, Azimuth(object->getAz()+180), Distance{((pSize/2)+(i*pSize)), ((pSize/2)+(j*pSize))});
			boxs[boxNumber].push_back(std::make_pair(Index{i,j} ,p1));
			std::cout << "Add point: [" << i << ":" << j <<"] [" << p1.x << ":" << p1.y << "]" << std::endl;
		}
	}
};

void Collision::addUnique(const int n, std::vector<int>& uBox)
{
	auto It = std::find(uBox.begin(), uBox.end(), n);
							
	if(It == uBox.end())
	{
		uBox.push_back(n);
		std::cout << "add unique:" << n << std::endl;
	};
};

void Collision::addCollisions(const std::pair<int,int>& boxIndexs)
{
/*	struct CollisionBox
	{
		Point begin, end;
		
		CollisionBox(const Point& p, const double size)
		{
			double halfSize = size/2;
			begin = Point{p.x+halfSize, p.y-halfSize};
			end = Point{p.x-halfSize, p.y+halfSize};
		}
	};*/
	
//	collisionPairs.reserve(20);
	
	for(int i = 0, size = firstBoxs[boxIndexs.first].size(); i<size; ++i)
	{
		for(int j = 0, size = secondBoxs[boxIndexs.second].size(); j<size; ++j)
		{
//			CollisionBox firstCell(firstBoxs[boxIndexs.first][i].second, pSize);
//			CollisionBox secondCell(secondBoxs[boxIndexs.second][j].second, pSize);
			auto firstCellPoint = firstBoxs[boxIndexs.first][i].second;
			auto secondCellPoint = secondBoxs[boxIndexs.second][j].second;
			
			bool check = collisionBoxCheck ( firstCellPoint.x, firstCellPoint.y, pSize/2, secondCellPoint.x, secondCellPoint.y, pSize/2);
			
			if(check)
			{
				collisionPairs.push_back(std::make_pair(firstBoxs[boxIndexs.first][i].first, secondBoxs[boxIndexs.second][j].first));
			}
			
		}
		
	}
	
};

void Collision::createPoints()
{
	firstBoxs.resize(firstObj->getZones()->size);
	secondBoxs.resize(secondObj->getZones()->size);
	
	std::for_each(	uniqueBoxCollisionFirst.begin(), uniqueBoxCollisionFirst.end(), 
							[this](int n)
							{
								this->addPoints(this->firstObj->getZones()->indexs[n].first, this->firstObj->getZones()->indexs[n].second, n, this->firstObj, this->firstBoxs);
							});
	
	std::for_each(	uniqueBoxCollisionSecond.begin(), uniqueBoxCollisionSecond.end(), 
							[this](int n)
							{
								this->addPoints(this->secondObj->getZones()->indexs[n].first, this->secondObj->getZones()->indexs[n].second, n, this->secondObj, this->secondBoxs);
							});
};

void Collision::collisionReckon()
{
	this->collisionBox();
	this->createPoints();
	
	std::for_each(	indexsColl.begin(), indexsColl.end(), 
							[this](auto& pair)
							{
								std::cout << '[' << pair.first << ',' << pair.second << ']' << std::endl;
								this->addCollisions(pair);
							});
							
	std::for_each(	collisionPairs.begin(), collisionPairs.end(), 
							[](auto& cellPair)
							{
								std::cout << '[' << cellPair.first.i << ',' << cellPair.first.j << "]&[" << cellPair.second.i << ',' << cellPair.second.j << ']' << std::endl;
							});
};

bool checkEqual(const Collision& first, const Collision& second)
{
	if(	(first.firstObj == second.firstObj && first.secondObj == second.secondObj)||
		(first.firstObj == second.secondObj && first.secondObj == second.firstObj)	)
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