#ifndef SHIP__
#define SHIP__

#include "ship_struct.hpp"
#include "keylist.hpp"

#include <vector>
#include <iterator>
#include <string>

#include "ship_attributes.hpp"

class Ship : private Ship_types
{
private:
	typedef std::string Name_type;
	typedef int Weight_type;
	typedef std::vector<std::vector<Ship_struct> > Blocks_type;
//	typedef std::vector<Group_type> Groups_type;//			Перенесено в абстрактный класс
	typedef int Block_size_type;
	typedef int Line_number_type;
	typedef int Group_size_type;
	
	Name_type name;
	
	Blocks_type Blocks;
	Groups_type Groups;
	
	ml1::KeyList<Set_item> itemsList;
	bool keyFlag = false;
	
	ShipAttributes currentAttributes;
	
public:

	Ship(Name_type, Block_size_type, Group_size_type, Weight_type);
	void AddShipStructInLine(Line_number_type, Ship_struct);
	
	void Debug_print();
	std::string getName() const;
	
	Groups_type::iterator Return_group(Group_size_type);
//	Blocks_type* Get_blocks();
	bool Block_check_struct_item(Item&, Block_size_type, Block_size_type, Turn_item_type);
	
//	void Block_set_struct_item(Set_item&, Block_size_type, Block_size_type);
	
	void Block_reser_struct_item(Block_size_type, Block_size_type);
	
	void powerOn();
	void setItem(Item*, Turn_item_type, Block_size_type, Block_size_type);
	void removeItem(Block_size_type, Block_size_type);
	
	void setStatus();
	
	~Ship();
};



#endif