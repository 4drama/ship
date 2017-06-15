#ifndef RESOURCE_STATUS__
#define RESOURCE_STATUS__

#include <vector>

#include "new_ship_attributes.hpp"

struct NewShipAttributes;

struct Resource_status
{
	typedef int Key_type;
	enum Overheat_status_type
	{
		overheatStatusGood = 0,
		overheatStatusBad = 1,
	};	
	enum Energy_status_type
	{
		energyStatusGood = 0,
		energyStatusBad = 1,
	};	
	enum Shield_status_type
	{
		shieldStatusNotFull = 0,
		shieldStatusFull = 1,
	};
	
	Overheat_status_type overheatStatus = overheatStatusGood;
	Energy_status_type energyStatus = energyStatusGood;
	Shield_status_type shieldStatus = shieldStatusNotFull;
	std::vector<Key_type>* shieldKeys;
	
};

#endif