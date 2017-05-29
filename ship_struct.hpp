#ifndef SHIP_STRUCT__
#define SHIP_STRUCT__

#include <vector>

class Ship;
class Ship_struct;
class Group_type;
class Ship_types;
class Set_item;

class Ship_types
{
public:
	virtual ~Ship_types() = 0;
protected:

	typedef std::vector<Group_type> Groups_type;
	
};

#include "item.hpp"
#include "set_item.hpp"


#include <iterator>

/*
enum Base_block_type{
	empty_block = 0,
	weapon_block = 1,
	inside_block = 2,
	engine_block = 3,
	citizen_block = 4,
	inside_and_weapon_block = 21,
	inside_and_engine_block = 23
};

enum Advanced_block_type{
	not_advance_block = 0,
	gate_block = 1,
//	outside_block = 2,
	outside_engine_to_left_block = 21,
	outside_engine_to_right_block = 22,
	outside_engine_to_up_block = 23,
	outside_engine_to_down_block = 24,
	cabin_block = 3,
//	outside_and_cabin_block = 23
};*/


/*
class Ship_types
{
public:
	virtual ~Ship_types() = 0;
protected:

	typedef std::vector<Group_type> Groups_type;
	
};
*/

class Group_type : private Ship_types
{
private:
	typedef int Number_type;
	Number_type Number;
	bool Cover = false;
public:
	explicit Group_type(int);
	Number_type Get_number();
};

class Ship_struct : public Ship_types
{
private:
	Base_block_type First_base;
	Base_block_type Second_base = empty_block;
	
	Groups_type::iterator Group;
	
	Advanced_block_type firstAdvance;
//	Advanced_block_type secondAdvance = not_advance_block;
	Turn_item_type turnTo = no_matter_turn;
	
	Set_item* Set_item_pointer = nullptr;
public:
	explicit Ship_struct(Base_block_type, Groups_type::iterator, Advanced_block_type);
	
	friend Ship_struct Create_block(Base_block_type, Groups_type::iterator, Advanced_block_type);
	
	Groups_type::iterator Get_group();
	void Struct_set_item(Set_item&);
	void Struct_destroy_item();
	Set_item* Struct_get_item();
	void Reset_ptr();
	
	Base_block_type Get_first_type() const;
	Base_block_type Get_second_type() const;
	Turn_item_type getTurnTo() const;
	Advanced_block_type getFirstAdvance() const;
};

Ship_struct Create_block(Base_block_type, Ship_struct::Groups_type::iterator , Advanced_block_type);



#endif