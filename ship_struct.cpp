#include "ship_struct.hpp"

#include <iostream>
	
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

Ship_struct::Ship_struct(Base_block_type Base_, Ship_types::Groups_type::iterator Group_, Advanced_block_type Advance_,  Turn_item_type turnTo_):
Group(Group_), firstAdvance(Advance_), turnTo(turnTo_)
{
	if(Base_ == inside_and_engine_block)
	{
		First_base = inside_block;
		Second_base = engine_block;
	}
	else if(Base_ == inside_and_weapon_block)
	{
		First_base = inside_block;
		Second_base = weapon_block;
	}
	else
	{
		First_base = Base_;
	};

};

Ship_types::Groups_type::iterator Ship_struct::Get_group()
{
	return Group;
};


Base_block_type Ship_struct::Get_first_type() const
{
	return First_base;
};


Base_block_type Ship_struct::Get_second_type() const
{
	return Second_base;
};

Turn_item_type Ship_struct::getTurnTo() const
{
	return turnTo;
};

Advanced_block_type Ship_struct::getFirstAdvance() const
{
	return firstAdvance;
};

void Ship_struct::setKey(int key)
{
	keyItem = key;
};

void Ship_struct::destroyKey()
{
	keyItem = 0;
};

int Ship_struct::getKey() const
{
	return keyItem;
};
