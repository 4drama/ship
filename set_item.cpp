#include "set_item.hpp"

//#include <iostream> 

Set_item::Set_item(Ship& Ship_pointer_, Item& Item_pointer_, Turn_item_type Turn_, X_call X_call_, Y_call Y_call_)
				: Ship_pointer(&Ship_pointer_), Item_pointer(&Item_pointer_), Turn(Turn_)
{
	//int X_block;
	//int Y_block;
	
	if (Turn_ == left || Turn_ == right )
	{
		//X_block = X_call_;
		//Y_block = Y_call_;
	}
	else if(Turn_ == up || Turn_ == down)
	{
		//X_block = Y_call_;
		//Y_block = X_call_;
		//std::cout<<"Turn = up or down";
	};
	
//	auto Pointer_to_blocks = Ship_pointer_.Get_blocks();
//	Pointer_to_blocks[X_call_][Y_call_].Struct_set_item(Item_pointer_);
	
//	Ship_pointer_
	
};

Set_item::~Set_item()
{
	
};