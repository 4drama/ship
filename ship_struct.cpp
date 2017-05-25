#include "ship_struct.hpp"


	//#include <iostream> //debug

Ship_struct::Ship_struct(Base_block_type Base_, Group_type Group_, Advanced_block_type Advance_):
Base(Base_), Group(Group_), Advance(Advance_)
{
	//std::cout << Group;	//debug
};

Ship_struct::Group_type Ship_struct::Get_group() const
{
	return Ship_struct::Group;
};

Ship_struct Create_block(Base_block_type Base_, Ship_struct::Group_type Group_, Advanced_block_type Advance_)
{
	
	return Ship_struct(Base_, Group_, Advance_);
};