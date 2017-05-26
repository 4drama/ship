#ifndef SHIP_STRUCT__
#define SHIP_STRUCT__

#include <vector>
#include <iterator>


enum Base_block_type{
	empty_block = 0,
	weapon_block = 1,
	inside_block = 2,
	engine_block = 3,
	inside_and_weapon_block = 21,
	inside_and_engine_block = 23
};

enum Advanced_block_type{
	not_advance_block = 0,
	gate_block = 1,
	outside_block = 2,
	cabin_block = 3,
	outside_and_cabin_block = 23
};

class Group_type;

class Ship_types
{
public:
	virtual ~Ship_types() = 0;
protected:

	typedef std::vector<Group_type> Groups_type;
	
};

class Group_type : public Ship_types
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
	Base_block_type Base;
	Groups_type::iterator Group;
	Advanced_block_type Advance;
public:
	explicit Ship_struct(Base_block_type, Groups_type::iterator, Advanced_block_type);
	Groups_type::iterator Get_group();
	friend Ship_struct Create_block(Base_block_type, Groups_type::iterator, Advanced_block_type);
};

Ship_struct Create_block(Base_block_type, Ship_struct::Groups_type::iterator , Advanced_block_type);

#endif