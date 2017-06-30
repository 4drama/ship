#include "collision.hpp"

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