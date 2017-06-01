#include "item.hpp"




//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
Item::Item
(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, bool Turn_matter_advance_)
: Weight(Weight_), Size_width(Size_width_), Size_height(Size_height_), Turn_matter_advance(Turn_matter_advance_)
{
	
};



Item::~Item()
{
	
};

Item::Item_size_type Item::Get_width() const
{
	return Size_width;
};

Item::Item_size_type Item::Get_height() const
{
	return Size_height;
};

Base_block_type Item::Get_base() const
{
	return no_matter_block;
};

Turn_item_type Item::getTurnItem() const
{
	return no_matter_turn;
};

bool Item::Get_turn_matter_advance() const
{
	return Turn_matter_advance;
};

Advanced_block_type Item::getAdvanceBlock() const
{
	return not_advance_block;
};
//-------------------------------------------------------------------


//===================================================================
//=====================MAIN_ENGINE===================================
Item_main_engine::Item_main_engine(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_)
		: Item(Weight_, Size_width_, Size_height_, 0)
{
	
};

Base_block_type Item_main_engine::Get_base() const
{
	return Base;
};

Turn_item_type Item_main_engine::getTurnItem() const
{
	return turnItem;
};
//-------------------------------------------------------------------


//===================================================================
//=====================HELP_ENGINE===================================
Item_help_engine::Item_help_engine(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_)
		: Item(Weight_, Size_width_, Size_height_, 1)
{
	
};

Advanced_block_type Item_help_engine::getAdvanceBlock() const
{
	return Advance;
};
//-------------------------------------------------------------------