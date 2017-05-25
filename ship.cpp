#include "ship.hpp"

#include<iostream>
#include<iterator>

Ship::Ship(Block_size_type size)
{
	Blocks.resize(size);
};

void Ship::Debug_print()
{
	for(int i = 0, size = Blocks.size(); i<size; ++i)
	{
		for(int b = 0, size = Blocks[i].size(); b<size; ++b)
		{
			if(Blocks[i][b].Get_group()!=0) 
			{
				std::cout<<"0"<<Blocks[i][b].Get_group();
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