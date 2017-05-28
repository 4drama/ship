#include "item.hpp"





Item::Item(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, bool Turn_matter_)
		: Weight(Weight_), Size_width(Size_width_), Size_height(Size_height_), Turn_matter(Turn_matter_)
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

bool Item::Get_turn_matter() const
{
	return Turn_matter;
};

Item_main_engine::Item_main_engine(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_)
		: Item(Weight_, Size_width_, Size_height_, 0)
{
	
};

Base_block_type Item_main_engine::Get_base() const
{
	return Base;
};

Item_help_engine::Item_help_engine(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_)
		: Item(Weight_, Size_width_, Size_height_, 1)
{
	
};