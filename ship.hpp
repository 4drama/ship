#ifndef SHIP__
#define SHIP__

#include "ship_struct.hpp"

#include <vector>
#include <iterator>



class Ship : public Ship_types
{
private:
	typedef std::vector<std::vector<Ship_struct> > Blocks_type;
//	typedef std::vector<Group_type> Groups_type;			Перенесено в абстрактный класс
	typedef int Block_size_type;
	typedef int Line_number_type;
	typedef int Group_size_type;
	Blocks_type Blocks;
	Groups_type Groups;
	
public:
	Ship(Block_size_type, Group_size_type);
	void AddShipStructInLine(Line_number_type, Ship_struct);
	void Debug_print();
	Groups_type::iterator Return_group(Group_size_type);
};


#endif