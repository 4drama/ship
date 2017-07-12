#ifndef SHIP__
#define SHIP__

#include "ship_struct.hpp"
#include "keylist.hpp"

#include <vector>
#include <iterator>
#include <string>

#include <utility>

#include "new_ship_attributes.hpp"
#include "enum_types.hpp"

#include "space_object.hpp"

//extern int update_frequency;
//extern double shipCellSize;

class Set_item;

class Ship : private Ship_types, public SpaceObject
{
private:
	typedef std::string Name_type;
	typedef int Weight_type;
	typedef std::vector<std::vector<Ship_struct> > Blocks_type;
	typedef int Block_size_type;
	typedef int Line_number_type;
	typedef int Group_size_type;
	typedef int Overheat_lmit_type;
	
	typedef int Key_type;
	typedef int Position_type;
	
	typedef std::pair<int, int> Left_side_type;
	typedef std::pair<int, int> Middle_side_type;
	typedef std::pair<int, int> Right_side_type;
	
	typedef std::pair<int, int> Front_side_type;
	typedef std::pair<int, int> Back_side_type;
	
	Name_type name;
	Block_size_type height;
	Block_size_type width;
		
	Blocks_type Blocks;
	Groups_type Groups;
	
	ml1::KeyList<Set_item> itemsList;
	bool keyFlag = false;
	bool collReadyFlag = false;
	
	NewShipAttributes currentAttributes;
	
	void addOrRemoveItemKeyToAttributes(Key_type, Item*, Block_size_type, Block_size_type, Attributes_aAdd_or_aRemove_type);
	
	friend Set_item;	
	void setStatus();
	bool Block_check_struct_item(Item&, Block_size_type, Block_size_type, Turn_item_type);
	void Block_reser_struct_item(Block_size_type, Block_size_type);	
	void itemSetAllMode(ItemMode, std::vector<NewShipAttributes::Key_type>&);
	
	
public:

	Ship(Name_type, Block_size_type, Block_size_type, Group_size_type, Weight_type, Overheat_lmit_type, Left_side_type, Middle_side_type, Right_side_type, Front_side_type, Back_side_type);
	
	void AddShipStructInLine(Line_number_type, Ship_struct);

	
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

	void moveCommand(Move_commands_type);
	
//	void nextStep(int) override;
	void coordinateReckon() override;
	void attributesReckon() override;
	void prepareCollision() override;
	bool cellEmpty(const Index&) const override;
	
	double getWeight() const override;
	
	~Ship();
};



#endif