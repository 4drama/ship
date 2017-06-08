#ifndef SET_ITEM__
#define SET_ITEM__

#include "item.hpp"
#include "ship_struct.hpp"
#include "ship.hpp"

#include <vector>
//#include <iterator>
#include <utility>

#include "enum_types.hpp"
#include "ship_attributes.hpp"

class Set_item
{
private:	
	typedef int X_call;
	typedef int Y_call;
	typedef std::vector<std::pair<int, int> > Cells_type;
	
	Cells_type Cells;
	Ship* Ship_pointer;
	Item* Item_pointer;
	ShipAttributes* attributesPtr;
	Turn_item_type Turn;
	
	ItemMode mode = powerOff;
	int currectDurability;
	int position;
	
public:
	
	Set_item(const Set_item&) = delete ;
	
	Set_item(Ship&, Item&, ShipAttributes&, Turn_item_type, X_call, Y_call);
	~Set_item();
	
	void addKeyingStruct(int, int);
	void swithMode(ItemMode);
};


#endif