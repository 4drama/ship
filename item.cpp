#include "item.hpp"


#include <iostream>

//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
Item::Item
(Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, bool Turn_matter_advance_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_)
:	name(name_), Weight(Weight_), Size_width(Size_width_), Size_height(Size_height_), Turn_matter_advance(Turn_matter_advance_),
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

Item::Durability_type Item::getDurability() const
{
	return durability;
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


void Item::addWeightToAttributes(ShipAttributes& attributes, Attributes_aAdd_or_aRemove_type action) const
{
	if(action == aAdd)
	{
		attributes.permanentAttributes.currentWeight += Weight;
	}
	else if(action == aRemove)
	{
		attributes.permanentAttributes.currentWeight -= Weight;
	}
};

//-------------------------------------------------------------------

//===================================================================
//===============ABSTRACT_RESOURCE_CONSUMING_ITEM_CLASS==============
ResourceConsumingItem::~ResourceConsumingItem()
{
	
};

ResourceConsumingItem::ResourceConsumingItem(	ItemMode maxMode_, 
												Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
												Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_,
												Energy_type energyNeedHigh_, Cooling_type coolingNeedHigh_)
		: maxMode(maxMode_), energyNeedLow(energyNeedLow_), coolingNeedLow(coolingNeedLow_), energyNeedAverage(energyNeedAverage_), coolingNeedAverage(coolingNeedAverage_),
		energyNeedHigh(energyNeedHigh_), coolingNeedHigh(coolingNeedHigh_)
{
/*	std::cerr << std::endl << "energyNeedLow_" << energyNeedLow_<< std::endl;
	std::cerr << "coolingNeedLow_" << coolingNeedLow_<< std::endl;
	std::cerr << "energyNeedAverage_" << energyNeedAverage_<< std::endl;
	std::cerr << "coolingNeedAverage_" << coolingNeedAverage_<< std::endl;
	std::cerr << "energyNeedHigh_" << energyNeedHigh_<< std::endl;
	std::cerr << "coolingNeedHigh_" << coolingNeedHigh_<< std::endl << std::endl;*/
};

void ResourceConsumingItem::resourceRecount(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
/*	std::cerr << std::endl << "energyNeedLow" << energyNeedLow<< std::endl;
	std::cerr << "coolingNeedLow" << coolingNeedLow<< std::endl;
	std::cerr << "energyNeedAverage" << energyNeedAverage<< std::endl;
	std::cerr << "coolingNeedAverage" << coolingNeedAverage<< std::endl;
	std::cerr << "energyNeedHigh" << energyNeedHigh<< std::endl;
	std::cerr << "coolingNeedHigh" << coolingNeedHigh<< std::endl << std::endl;*/
	
	int energyBefore;
	int energyNow;
	int coolingBefore;
	int coolingNow;
	
	if(newMode > maxMode)
	{
		std::cerr << "ERROR: ABSTRACT_RESOURCE_CONSUMING_ITEM_CLASS. resourceRecount - Wrong mode" << std::endl;
		return;
	}
	
	if(oldMode == powerOff)
	{
		energyBefore = 0;
		coolingBefore = 0;
//		std::cerr << "powerOff energyBefore" << energyBefore<< std::endl;
//		std::cerr << "powerOff coolingBefore" << coolingNeedLow<< std::endl;
	}
	else if(oldMode == modeLow)
	{
		energyBefore = energyNeedLow;
		coolingBefore = coolingNeedLow;
//		std::cerr << "modeLow energyBefore" << energyBefore<< std::endl;
//		std::cerr << "modeLow coolingBefore" << coolingNeedLow<< std::endl;
	}
	else if(oldMode == modeAverage)
	{
		energyBefore = energyNeedAverage;
		coolingBefore = coolingNeedAverage;
//		std::cerr << "modeAverage energyBefore" << energyBefore<< std::endl;
//		std::cerr << "modeAverage coolingBefore" << coolingNeedLow<< std::endl;
	}
	else if(oldMode == modeHigh)
	{
		energyBefore = energyNeedHigh;
		coolingBefore = coolingNeedHigh;
//		std::cerr << "modeHigh energyBefore" << energyBefore<< std::endl;
//		std::cerr << "modeHigh coolingBefore" << coolingNeedLow<< std::endl;
	}
	
	if(newMode == powerOff)
	{
		energyNow = 0;
		coolingNow = 0;
//		std::cerr << "powerOff energyNow" << energyNow<< std::endl;
//		std::cerr << "powerOff coolingNow" << coolingNow<< std::endl;
	}
	else if(newMode == modeLow)
	{
		energyNow = energyNeedLow;
		coolingNow = coolingNeedLow;
//		std::cerr << "modeLow energyNow" << energyNow<< std::endl;
//		std::cerr << "modeLow coolingNow" << coolingNow<< std::endl;
	}
	else if(newMode == modeAverage)
	{
		energyNow = energyNeedAverage;
		coolingNow = coolingNeedAverage;
//		std::cerr << "modeAverage energyNow" << energyNow<< std::endl;
//		std::cerr << "modeAverage coolingNow" << coolingNow<< std::endl;
	}
	else if(newMode == modeHigh)
	{
		energyNow = energyNeedHigh;
		coolingNow = coolingNeedHigh;
//		std::cerr << "modeHigh energyNow" << energyNow<< std::endl;
//		std::cerr << "modeHigh coolingNow" << coolingNow<< std::endl;
	} 
	
	int energyNeedUpdate = energyNow - energyBefore;
	int coolingNeedUpdate = coolingNow - coolingBefore;
	
/*	std::cerr << "energyNeedUpdate" << energyNeedUpdate<< std::endl;
	std::cerr << "coolingNeedUpdate" << coolingNeedUpdate<< std::endl;	
	std::cerr << "energyNow" << energyNow<< std::endl;
	std::cerr << "energyBefore" << energyBefore<< std::endl;	
	std::cerr << "coolingNow" << coolingNow<< std::endl;
	std::cerr << "coolingBefore" << coolingBefore<< std::endl;	*/
	
	attributes.energyChange -= energyNeedUpdate;
	attributes.overheatChange += coolingNeedUpdate;
};

//-------------------------------------------------------------------

//===================================================================
//=====================MAIN_ENGINE===================================
Item_main_engine::Item_main_engine(	Name_type name_,Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_,
									Power_type power_, Max_speed_type maxSpeed_, Acceleration_type acceleration_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, destroyDamage_, destroyArea_),
			ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_),
			power(power_), maxSpeed(maxSpeed_), acceleration(acceleration_)
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
	addWeightToAttributes(attributes, aAdd);
	//attributes.permanentAttributes.currentWeight += Weight;
	attributes.permanentAttributes.engineCapacity += power;
	attributes.permanentAttributes.generalEnginesSpeed += maxSpeed;
	attributes.permanentAttributes.amountEngines ++;
	attributes.permanentAttributes.potentialAcceleration += acceleration;
	
	
//	std::cout << "DEBUG: Item_main_engine::addAttributes" << std::endl;
	
};

void Item_main_engine::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	resourceRecount(attributes, oldMode, newMode);
	
};

void Item_main_engine::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	resourceRecount(attributes, oldMode, powerOff);

	addWeightToAttributes(attributes, aRemove);

	attributes.permanentAttributes.engineCapacity -= power;
	attributes.permanentAttributes.generalEnginesSpeed -= maxSpeed;
	attributes.permanentAttributes.amountEngines --;
	attributes.permanentAttributes.potentialAcceleration -= acceleration;
	
//	std::cout << "DEBUG: Item_main_engine::removeAttributes" << std::endl;
};
//=====================




//-------------------------------------------------------------------


//===================================================================
//=====================HELP_ENGINE===================================
Item_help_engine::Item_help_engine(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_,
									Power_type power_, Max_speed_type maxSpeed_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		:	Item(name_, Weight_, Size_width_, Size_height_, 1, durability_, destroyDamage_, destroyArea_),
			ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_),
			power(power_), maxSpeed(maxSpeed_)
{
	
};

Advanced_block_type Item_help_engine::getAdvanceBlock() const
{
	return Advance;
};

//=============Attributes
void Item_help_engine::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.permanentAttributes.moveEnginesList.push_back(MoveEngines(position, turn, power, maxSpeed));	
	attributes.permanentAttributes.recountMoveEnginesList();
};

void Item_help_engine::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	resourceRecount(attributes, oldMode, newMode);
};

void Item_help_engine::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	resourceRecount(attributes, oldMode, powerOff);
	addWeightToAttributes(attributes, aRemove);
	attributes.permanentAttributes.removeFromMoveEnginesList(position, turn);	
	attributes.permanentAttributes.recountMoveEnginesList();
};
//=======================



//-------------------------------------------------------------------