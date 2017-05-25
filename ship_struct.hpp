#ifndef SHIP_STRUCT__
#define SHIP_STRUCT__

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

class Ship_struct
{
private:
	typedef int Group_type;
	Group_type Group;
	Base_block_type Base;
	Advanced_block_type Advance;
public:
	explicit Ship_struct(Group_type, Base_block_type, Advanced_block_type = not_advance_block);
	
};

#endif