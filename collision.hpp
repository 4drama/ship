#ifndef COLLISION__
#define COLLISION__

#include <vector>
#include "space_object.hpp"
#include <memory>

namespace{
	
typedef std::vector< std::pair< std::shared_ptr<SpaceObject> ,std::shared_ptr<SpaceObject> > >	Collision_list_type;	
typedef std::vector<std::shared_ptr<SpaceObject> > Object_list_type;

}


bool collisionBoxCheck 	(	double obj1_x, double obj1_y, double obj1_box,
							double obj2_x, double obj2_y, double obj2_box);

bool conformityPairCheck(	std::pair< std::shared_ptr<SpaceObject> ,std::shared_ptr<SpaceObject> > objPair,
							std::shared_ptr<SpaceObject> obj1, std::shared_ptr<SpaceObject> obj2);

//reckon Collision.  NEED REMAKE. NOT EFFECTIVE							
void collisionListCheck	(	Collision_list_type& collList, Object_list_type& objList);					
void collisionBoxCheck	(	Collision_list_type& collList);

Collision_list_type createCollisionList();
	
#endif