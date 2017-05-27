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

Ship::Blocks_type* Ship::Get_blocks()
{
	return &Blocks;
};