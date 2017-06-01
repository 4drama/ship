#ifndef ITEM__
#define ITEM__

enum Base_block_type{
	empty_block = 0,
	weapon_block = 1,
	inside_block = 2,
	engine_block = 3,
	citizen_block = 4,
	no_matter_block = 5,
	inside_and_weapon_block = 21,
	inside_and_engine_block = 23
};

enum Advanced_block_type{
	not_advance_block = 0,
	gate_block = 1,
	outside_engine_block = 2,
//	outside_engine_to_left_block = 21,
//	outside_engine_to_right_block = 22,
//	outside_engine_to_up_block = 23,
//	outside_engine_to_down_block = 24,
	cabin_block = 3,
//	outside_and_cabin_block = 23
};

enum Turn_item_type{
	left_turn = 1,
	right_turn = 2,
	up_turn = 3,
	down_turn = 4,
	no_matter_turn = 5,
};




//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
class Item
{
protected:	
	typedef int Weight_type;
	typedef int Item_size_type;	
	
private:	
	Weight_type Weight;
	Item_size_type Size_width;
	Item_size_type Size_height;
	bool Turn_matter_advance;
	
public:
	virtual ~Item() = 0;
	
	virtual Base_block_type Get_base() const;
	virtual Turn_item_type getTurnItem() const;
	virtual Advanced_block_type getAdvanceBlock() const;
	
	bool Get_turn_matter_advance() const;
	
	Item_size_type Get_width() const;
	Item_size_type Get_height() const;
	
protected:	
	Item(Weight_type, Item_size_type, Item_size_type, bool);
	
	
};
//-------------------------------------------------------------------



//===================================================================
//=====================MAIN_ENGINE===================================
class Item_main_engine : public Item
{
private:

	const Base_block_type Base = engine_block;
	const Turn_item_type turnItem = down_turn;
	
public:

	Base_block_type Get_base() const;
	Turn_item_type getTurnItem() const;
	
	Item_main_engine(Weight_type, Item_size_type, Item_size_type);
	
};
//-------------------------------------------------------------------


//===================================================================
//=====================HELP_ENGINE===================================
class Item_help_engine : public Item
{
private:

	const Advanced_block_type Advance = outside_engine_block;
	
	
public:
	
	Item_help_engine(Weight_type, Item_size_type, Item_size_type);
	
	Advanced_block_type getAdvanceBlock() const;
};
//-------------------------------------------------------------------


#endif