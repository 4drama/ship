#ifndef SET_ITEM__
#define SET_ITEM__

#include "item.hpp"
#include "ship_struct.hpp"
#include "ship.hpp"

#include <vector>
//#include <iterator>
#include <utility>



class Set_item
{
private:	
	typedef int X_call;
	typedef int Y_call;
	typedef std::vector<std::pair<int, int> > Cells_type;
	
	Cells_type Cells;
	Ship* Ship_pointer;
	Item* Item_pointer;	
	Turn_item_type Turn;
	
public:
	
	
	Set_item(Ship&, Item&, Turn_item_type, X_call, Y_call);
	~Set_item();
	
	void addKeyingStruct(int, int);
};


#endif