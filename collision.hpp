#ifndef COLLISION__
#define COLLISION__

#include "space_object.hpp"
#include <memory>

bool collisionBoxCheck (	double obj1_x, double obj1_y, double obj1_box,
							double obj2_x, double obj2_y, double obj2_box);

bool conformityPairCheck(	std::pair< std::shared_ptr<SpaceObject> ,std::shared_ptr<SpaceObject> > objPair,
							std::shared_ptr<SpaceObject> obj1, std::shared_ptr<SpaceObject> obj2);
						
#endif