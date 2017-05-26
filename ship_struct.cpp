#include "ship_struct.hpp"


	//#include <iostream> //debug
	
Ship_types::~Ship_types()
{
	
};
	
Group_type::Group_type(Number_type Number_):
Number(Number_)
{
	
};

Group_type::Number_type Group_type::Get_number()
{
	return Number;
};

Ship_struct::Ship_struct(Base_block_type Base_, Ship_types::Groups_type::iterator Group_, Advanced_block_type Advance_):
Base(Base_), Group(Group_), Advance(Advance_)
{
	//std::cout << Group;	//debug
};

Ship_types::Groups_type::iterator Ship_struct::Get_group()
{
	return Group;
};

Ship_struct Create_block(Base_block_type Base_, Ship_types::Groups_type::iterator Group_, Advanced_block_type Advance_)
{
	
	return Ship_struct(Base_, Group_, Advance_);
};