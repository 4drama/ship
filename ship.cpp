#include "ship.hpp"

#include<iostream>



Ship::Ship(Block_size_type bsize_, Group_size_type gsize_)
{
	Blocks.resize(bsize_);
//	Groups.resize(gsize_);
	for(Group_size_type i = 0; i<gsize_; ++i)
		{
			Groups.push_back(Group_type(i));
		};
};

void Ship::Debug_print()
{
	
	for(int i = 0, size = Blocks.size(); i<size; ++i)
	{
		for(int b = 0, size = Blocks[i].size(); b<size; ++b)
		{
			
			//auto a1 = Blocks[i][b].Get_group();
			
			
			if( Blocks[i][b].Get_group()->Get_number() != 0) 
			{
				int a1;
				a1 = 0;
				if(!Blocks[i][b].Struct_get_item() == 0)
				{
					a1 = 1;
				};
				std::cout<<a1<<Blocks[i][b].Get_group()->Get_number();
			}
			else
			{
				std::cout<<"  ";
			}
			
		};
		std::cout<<std::endl;
	};
};

void Ship::AddShipStructInLine(Line_number_type Line, Ship_struct Block)
{
	Blocks[Line].push_back(Block);
};

Ship_types::Groups_type::iterator Ship::Return_group(Group_size_type Number)
{
	Ship_types::Groups_type::iterator it;
	it = Groups.begin() + Number;
	return it;
};

/*
Ship::Blocks_type* Ship::Get_blocks()
{
	return &Blocks;
};
*/

bool Ship::Block_check_struct_item(Item& Item_pointer_, Block_size_type X_call_, Block_size_type Y_call_, Turn_item_type Turn_)
{
	if(	   Item_pointer_.Get_base() == Blocks[Y_call_][X_call_].Get_first_type()
		|| Item_pointer_.Get_base() == Blocks[Y_call_][X_call_].Get_second_type()
		|| Item_pointer_.Get_base() == no_matter_block)
	{
		return true;
	};
		
	return false;
};

void Ship::Block_set_struct_item(Set_item& Set_item_pointer_, Block_size_type X_call_, Block_size_type Y_call_)
{
	Blocks[Y_call_][X_call_].Struct_set_item(Set_item_pointer_);
};

void Ship::Block_reser_struct_item(Block_size_type x, Block_size_type y)
{
	Blocks[x][y].Reset_ptr();
};