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

	int keyItem = 0;
public:
	explicit Ship_struct(Base_block_type, Groups_type::iterator, Advanced_block_type, Turn_item_type = no_matter_turn);
	
	
	Groups_type::iterator Get_group();

	void setKey(int);
	void destroyKey();
	int getKey() const;

	Base_block_type Get_first_type() const;
	Base_block_type Get_second_type() const;
	Turn_item_type getTurnTo() const;
	Advanced_block_type getFirstAdvance() const;
};




#endif