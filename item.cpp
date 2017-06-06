#include "item.hpp"


#include <iostream>

//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
Item::Item
(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, bool Turn_matter_advance_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_)
:	Weight(Weight_), Size_width(Size_width_), Size_height(Size_height_), Turn_matter_advance(Turn_matter_advance_),
	durability(durability_), destroyDamage(destroyDamage_), destroyArea(destroyArea_)
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

void Item::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. addAttributes " << std::endl;
};
void Item::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. recountAttributes " << std::endl;
};

void Item::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. removeAttributes " << std::endl;
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
Item_main_engine::Item_main_engine(	Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_,
									Power_type power_, Max_speed_type maxSpeed_, Acceleration_type acceleration_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		: Item(Weight_, Size_width_, Size_height_, 0, durability_, destroyDamage_, destroyArea_),
		power(power_), maxSpeed(maxSpeed_), acceleration(acceleration_), energyNeedLow(energyNeedLow_), coolingNeedLow(coolingNeedLow_), energyNeedAverage(energyNeedAverage_), coolingNeedAverage(coolingNeedAverage_)
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


//=============Attributes
void Item_main_engine::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	attributes.permanentAttributes.currentWeight += Weight;
	attributes.permanentAttributes.engineCapacity += power;
	attributes.permanentAttributes.generalEnginesSpeed += maxSpeed;
	attributes.permanentAttributes.amountEngines ++;
	attributes.permanentAttributes.potentialAcceleration += acceleration;
	
};

void Item_main_engine::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	int energyBefore;
	int energyNow;
	int coolingBefore;
	int coolingNow;
	
	if(oldMode == powerOff)
	{
		energyBefore = 0;
		coolingBefore = 0;
	}
	else if(oldMode == modeLow)
	{
		energyBefore = energyNeedLow;
		coolingBefore = coolingNeedLow;
	}
	else if(oldMode == modeAverage)
	{
		energyBefore = energyNeedAverage;
		coolingBefore = coolingNeedAverage;
	}
	
	if(newMode == powerOff)
	{
		energyNow = 0;
		coolingNow = 0;
	}
	else if(newMode == modeLow)
	{
		energyNow = energyNeedLow;
		coolingNow = coolingNeedLow;
	}
	else if(newMode == modeAverage)
	{
		energyNow = energyNeedAverage;
		coolingNow = coolingNeedAverage;
	}
	
	int energyNeedUpdate = energyNow - energyBefore;
	int coolingNeedUpdate = coolingNow - coolingBefore;
	
	attributes.energyChange -= energyNeedUpdate;
	attributes.overheatChange += coolingNeedUpdate;
};

void Item_main_engine::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	int energyNeedUpdate;
	int coolingNeedUpdate;
	
	if(oldMode == powerOff)
	{
		energyNeedUpdate = 0;
		coolingNeedUpdate = 0;
	}
	else if(oldMode == modeLow)
	{
		energyNeedUpdate = energyNeedLow;
		coolingNeedUpdate = coolingNeedLow;
	}
	else if(oldMode == modeAverage)
	{
		energyNeedUpdate = energyNeedAverage;
		coolingNeedUpdate = coolingNeedAverage;
	}
	
	attributes.energyChange += energyNeedUpdate;
	attributes.overheatChange -= coolingNeedUpdate;
	
	attributes.permanentAttributes.currentWeight -= Weight;
	attributes.permanentAttributes.engineCapacity -= power;
	attributes.permanentAttributes.generalEnginesSpeed -= maxSpeed;
	attributes.permanentAttributes.amountEngines --;
	attributes.permanentAttributes.potentialAcceleration -= acceleration;
	
};
//=====================




//-------------------------------------------------------------------


//===================================================================
//=====================HELP_ENGINE===================================
Item_help_engine::Item_help_engine(Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_,
									Power_type power_, Max_speed_type maxSpeed_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		: Item(Weight_, Size_width_, Size_height_, 1, durability_, destroyDamage_, destroyArea_),
		power(power_), maxSpeed(maxSpeed_), energyNeedLow(energyNeedLow_), coolingNeedLow(coolingNeedLow_), energyNeedAverage(energyNeedAverage_), coolingNeedAverage(coolingNeedAverage_)
{
	
};

Advanced_block_type Item_help_engine::getAdvanceBlock() const
{
	return Advance;
};

//=============Attributes
void Item_help_engine::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	
};

void Item_help_engine::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	
};

void Item_help_engine::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	
};
//=======================



//-------------------------------------------------------------------