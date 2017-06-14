#ifndef SHIP__
#define SHIP__

#include "ship_struct.hpp"
#include "keylist.hpp"

#include <vector>
#include <iterator>
#include <string>

#include <utility>

#include "new_ship_attributes.hpp"
//#include "ship_attributes.hpp"
#include "enum_types.hpp"


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
	typedef int Overheat_lmit_type;
	
	typedef int Key_type;
	typedef int Position_type;
	
	Name_type name;
	
	Blocks_type Blocks;
	Groups_type Groups;
	
	ml1::KeyList<Set_item> itemsList;
	bool keyFlag = false;
	
//	ShipAttributes currentAttributes;
	NewShipAttributes currentAttributes;
	
	void addItemKeyToAttributes(Key_type, Item*, Block_size_type, Block_size_type);
	void deleteItemKeyToAttributes(Key_type, Item*);
	
public:

	Ship(Name_type, Block_size_type, Group_size_type, Weight_type, Overheat_lmit_type);
	
	void AddShipStructInLine(Line_number_type, Ship_struct);
	Groups_type::iterator Return_group(Group_size_type);
	void setStatus();
	bool Block_check_struct_item(Item&, Block_size_type, Block_size_type, Turn_item_type);
	void Block_reser_struct_item(Block_size_type, Block_size_type);
	
	std::string getName() const;
	
	void Debug_print();	
	void showItems() const;	
	
	void powerOn();
	void powerOff();
	
	void setItem(Item*, Turn_item_type, Block_size_type, Block_size_type);
	
	void removeItem(Key_type);
	void removeItem(Block_size_type, Block_size_type);

	void itemSetMode(ItemMode, Key_type);
	void itemSetMode(ItemMode, Position_type, Position_type);

	void nextStep(int);
//	void action(Action_type);
	
	~Ship();
};



#endif