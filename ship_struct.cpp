#include "ship_struct.hpp"
	
	
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
Group(Group_), Advance(Advance_)
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

Ship_struct Create_block(Base_block_type Base_, Ship_struct::Groups_type::iterator Group_, Advanced_block_type Advance_)
{
	
	return Ship_struct(Base_, Group_, Advance_);
};

void Ship_struct::Struct_set_item(Set_item& set)
{
	Ship_struct::Set_item_pointer = &set;
};
	
void Ship_struct::Struct_destroy_item()
{
	Ship_struct::Set_item_pointer = nullptr;	
};

Set_item* Ship_struct::Struct_get_item()
{
	return Ship_struct::Set_item_pointer;
};

Base_block_type Ship_struct::Get_first_type() const
{
	return First_base;
};


Base_block_type Ship_struct::Get_second_type() const
{
	return Second_base;
};

void Ship_struct::Reset_ptr()
{
	Set_item_pointer = nullptr;
};

