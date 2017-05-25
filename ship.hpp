#ifndef SHIP__
#define SHIP__

#include "ship_struct.hpp"

#include <vector>

class Ship
{
private:
	typedef std::vector<std::vector<Ship_struct> > Blocks_type;
	typedef int Block_size_type;
	typedef int Line_number_type;
	Blocks_type Blocks;
	
public:
	Ship(Block_size_type);
	void AddShipStructInLine(Line_number_type, Ship_struct);
	void Debug_print();
};


#endif