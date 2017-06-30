#include "item.hpp"


#include <iostream>

//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
Item::Item
	(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, bool Turn_matter_advance_,
		Durability_type durability_, Base_block_type base_, Advanced_block_type advance_, Turn_item_type turnItem_)
:	name(name_), Weight(Weight_), Size_width(Size_width_), Size_height(Size_height_), Turn_matter_advance(Turn_matter_advance_),
	durability(durability_), base(base_), advance(advance_), turnItem(turnItem_)
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

Item::Name_type Item::getName() const
{
	return name;
};

Base_block_type Item::Get_base() const
{
	return base;
};

Turn_item_type Item::getTurnItem() const
{
	return turnItem;
};

void Item::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. addAttributes " << std::endl;
};
void Item::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. recountAttributes " << std::endl;
};

void Item::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	std::cerr << "ERROR: ABSTRACT_ITEM_CLASS. removeAttributes " << std::endl;
};

bool Item::Get_turn_matter_advance() const
{
	return Turn_matter_advance;
};

Advanced_block_type Item::getAdvanceBlock() const
{
	return advance;
};


void Item::addWeightToAttributes(NewShipAttributes& attributes, Attributes_aAdd_or_aRemove_type action) const
{
	if(action == aAdd)
	{
		attributes.currentWeight += Weight;
	}
	else if(action == aRemove)
	{
		attributes.currentWeight -= Weight;
	}
};

//-------------------------------------------------------------------


//===================================================================
//===============ABSTRACT_EXPLOSIVE_ITEM_CLASS=======================
ExplosiveItem::ExplosiveItem(	Damage_type destroyDamage_, Area_type destroyArea_)
							:	destroyDamage(destroyDamage_), destroyArea(destroyArea_)
{
	
};


ExplosiveItem::~ExplosiveItem()
{
	
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

void ResourceConsumingItem::resourceRecount(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
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
//===============ABSTRACT_WEAPON_ITEM_CLASS==========================
WeaponItem::WeaponItem(	Damage_type damage_, Area_type area_, Speed_type speed_)
					:	damage(damage_), area(area_), speed(speed_)
{
	
};


WeaponItem::~WeaponItem()
{
	
};
//-------------------------------------------------------------------


//===================================================================
//===============ABSTRACT_ONCE_RESOURCE_CONSUMING_ITEM_CLASS=========
OnceResourceConsumingItem::OnceResourceConsumingItem(	Energy_type energyReduction_, Cooling_type heat_)
													:	energyReduction(energyReduction_), heat(heat_)
{
	
};

void OnceResourceConsumingItem::reductionAttributes(NewShipAttributes& attributes)
{
	attributes.overheatNow += heat;
	attributes.energyNow -= energyReduction;
};

OnceResourceConsumingItem::~OnceResourceConsumingItem()
{
	
};
//-------------------------------------------------------------------


//===================================================================
//=====================MAIN_ENGINE===================================
Item_main_engine::Item_main_engine(	Name_type name_,Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_, Damage_type destroyDamage_, Area_type destroyArea_,
									Power_type power_, Max_speed_type maxSpeed_, Acceleration_type acceleration_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, engine_block, not_advance_block, down_turn),
			ExplosiveItem(destroyDamage_, destroyArea_),
			ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_),
			power(power_), maxSpeed(maxSpeed_), acceleration(acceleration_)
{
	
};

//=============Attributes
void Item_main_engine::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
//	attributes.mainPower += power;
//	attributes.permanentAttributes.generalEnginesSpeed += maxSpeed;
//	attributes.permanentAttributes.amountEngines ++;
//	attributes.permanentAttributes.potentialAcceleration += acceleration;
	
	
//	std::cout << "DEBUG: Item_main_engine::addAttributes" << std::endl;
	
};

void Item_main_engine::logicAdd(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	double* speedPtr = nullptr;
	
	if(position.first >= attributes.leftPos.first && position.first <= attributes.leftPos.second)
	{
		speedPtr = &attributes.leftEngineSpeed;
	}
	else if(position.first >= attributes.middlePos.first && position.first <= attributes.middlePos.second)
	{
		speedPtr = &attributes.middleEngineSpeed;
	}
	else if(position.first >= attributes.rightPos.first && position.first <= attributes.rightPos.second)
	{
		speedPtr = &attributes.rightEngineSpeed;
	}
	else
	{
		std::cerr << "ERROR: Item_main_engine::logicAdd std::pair<" << position.first << ", " << position.second << "> position" << std::endl;
		return;
	}
	
	if((oldMode == powerOff || oldMode == modeLow) && newMode == modeAverage)
	{
		*speedPtr += maxSpeed;
		attributes.potentialAcceleration += acceleration;
	}
	else if(oldMode == modeAverage && (newMode == powerOff || newMode == modeLow))
	{
		*speedPtr -= maxSpeed;
		attributes.potentialAcceleration -= acceleration;
	}
	
	
	if(oldMode == powerOff)
	{
		attributes.mainPower += power;
	}
	else if(newMode == powerOff)
	{
		attributes.mainPower -= power;
	}
};

void Item_main_engine::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, newMode);
	
	logicAdd(attributes, oldMode, newMode, position);
	
	attributes.reckonForwardingSpeed();
};

void Item_main_engine::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, powerOff);
	if(oldMode != powerOff)
	{
		attributes.mainPower -= power;
	}
	addWeightToAttributes(attributes, aRemove);

//	attributes.mainPower -= power;
//	attributes.permanentAttributes.generalEnginesSpeed -= maxSpeed;
//	attributes.permanentAttributes.amountEngines --;
//	attributes.permanentAttributes.potentialAcceleration -= acceleration;
	
//	std::cout << "DEBUG: Item_main_engine::removeAttributes" << std::endl;
};
//=====================
//-------------------------------------------------------------------


//===================================================================
//=====================HELP_ENGINE===================================
Item_help_engine::Item_help_engine(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
									Power_type power_, Max_speed_type maxSpeed_,
									Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
									Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
		:	Item(name_, Weight_, Size_width_, Size_height_, 1, durability_, no_matter_block, outside_engine_block),
			ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_),
			power(power_), maxSpeed(maxSpeed_)
{
	
};

//=============Attributes
void Item_help_engine::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
	
//	std::cerr << this << std::endl;
	
//	attributes.permanentAttributes.moveEnginesList.push_back(MoveEngines(position, turn, power, maxSpeed));	
//	attributes.permanentAttributes.recountMoveEnginesList();
};

void Item_help_engine::logicAdd(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{	
	double* speedPtr = nullptr;
	double* powerPtr = nullptr;
	int* positionPtr = nullptr;
	
	if(position.second >= attributes.frontPos.first && position.second <= attributes.frontPos.second)
	{
		if(position.first >= attributes.leftPos.first && position.first <= attributes.leftPos.second)
		{
			speedPtr = &attributes.leftFrontSpeed;
			powerPtr = &attributes.leftFrontPower;
			positionPtr = &attributes.leftFrontPosition;
		}
		else if(position.first >= attributes.middlePos.first && position.first <= attributes.middlePos.second)
		{
			speedPtr = &attributes.frontEngineSpeed;
			powerPtr = &attributes.frontEnginePower;
		}
		else if(position.first >= attributes.rightPos.first && position.first <= attributes.rightPos.second)
		{
			speedPtr = &attributes.rightFrontSpeed;
			powerPtr = &attributes.rightFrontPower;
			positionPtr = &attributes.rightFrontPosition;
		}
		else
		{
			std::cerr << "ERROR: Item_help_engine::logicAdd Front std::pair<" << position.first << ", " << position.second << "> position" << std::endl;
			return;
		}
	}
	else if(position.second >= attributes.backPos.first && position.second <= attributes.backPos.second)
	{
		if(position.first >= attributes.leftPos.first && position.first <= attributes.leftPos.second)
		{
			speedPtr = &attributes.leftBackSpeed;
			powerPtr = &attributes.leftBackPower;
			positionPtr = &attributes.leftBackPosition;
		}
		else if(position.first >= attributes.rightPos.first && position.first <= attributes.rightPos.second)
		{
			speedPtr = &attributes.rightBackSpeed;
			powerPtr = &attributes.rightBackPower;
			positionPtr = &attributes.rightBackPosition;
		}
		else
		{
			std::cerr << "ERROR: Item_help_engine::logicAdd Back std::pair<" << position.first << ", " << position.second << "> position" << std::endl;
			return;
		}
	}
	else
	{
		std::cerr << "ERROR: Item_help_engine::logicAdd All" << std::endl;
		return;
	}
	
	if(oldMode == powerOff && (newMode == modeLow || newMode == modeAverage) )
	{
		*powerPtr += power;
		if(positionPtr != nullptr)
		{
			*positionPtr = position.second;
		}
	}
	else if(newMode == powerOff && (oldMode == modeLow || oldMode == modeAverage) )
	{
		*powerPtr -= power;
		if(positionPtr != nullptr)
		{
			*positionPtr = attributes.frontPos.second;
		}
	}
	
	if(newMode == modeAverage && (oldMode == modeLow || oldMode == powerOff) )
	{
		*speedPtr += maxSpeed;
	}
	else if(oldMode == modeAverage && (newMode == modeLow || newMode == powerOff) )
	{
		*speedPtr -= maxSpeed;
	}
	
};

void Item_help_engine::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, newMode);	
	logicAdd(attributes, oldMode, newMode, position);
	attributes.reckonTurnOrStrafeSpeed();
	attributes.reckonForwardingSpeed();
};

void Item_help_engine::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
//	std::cerr << "DEBUG: Item_help_engine::removeAttributes" << std::endl;
	resourceRecount(attributes, oldMode, powerOff);
	if(oldMode != powerOff)
	{
		logicAdd(attributes, oldMode, powerOff, position);
		attributes.reckonTurnOrStrafeSpeed();
		attributes.reckonForwardingSpeed();
	}
	addWeightToAttributes(attributes, aRemove);
//	attributes.permanentAttributes.removeFromMoveEnginesList(position, turn);	
//	attributes.permanentAttributes.recountMoveEnginesList();
};
//=======================
//-------------------------------------------------------------------




//===================================================================
//=====================CABIN=========================================
Item_cabina::Item_cabina(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
							Energy_type energyNeedLow_, Cooling_type coolingNeedLow_)
						:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, citizen_block, cabin_block, up_turn),
							ResourceConsumingItem(modeLow, energyNeedLow_, coolingNeedLow_)
{
	
};
	
void Item_cabina::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
};
	
void Item_cabina::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, newMode);
};
	
void Item_cabina::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, powerOff);
	addWeightToAttributes(attributes, aRemove);
};

//-------------------------------------------------------------------


//===================================================================
//=====================GATE==========================================
Item_gate::Item_gate(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_,
						Durability_type durability_, Item_size_type gateSize_)
					:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, citizen_block, gate_block),
						gateSize(gateSize_)
{
	
};

void Item_gate::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_gate::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	
};

void Item_gate::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aRemove);	
};
//-------------------------------------------------------------------

//===================================================================
//=====================CARGO_CELL====================================
Item_cargo_cell::Item_cargo_cell(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_,
									Durability_type durability_, Item_size_type cargoWidth_, Item_size_type cargoHeight_)
								:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, citizen_block, not_advance_block, no_matter_turn),
									cargoWidth(cargoWidth_), cargoHeight(cargoHeight_)
{
		
};

void Item_cargo_cell::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_cargo_cell::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	
};

void Item_cargo_cell::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aRemove);		
};
//-------------------------------------------------------------------

//===================================================================
//=====================POWER_GENERATOR===============================
Item_power_generator::Item_power_generator(		Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
												Damage_type destroyDamage_, Area_type destroyArea_,
												Energy_type energyNeedLow_, Cooling_type coolingNeedLow_)
											:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, inside_block, not_advance_block, no_matter_turn),
												ExplosiveItem(destroyDamage_, destroyArea_),
												ResourceConsumingItem(modeLow, energyNeedLow_, coolingNeedLow_)
{
	
};

void Item_power_generator::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_power_generator::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, newMode);
};

void Item_power_generator::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, powerOff);
	addWeightToAttributes(attributes, aRemove);			
};
//-------------------------------------------------------------------


//===================================================================
//=====================ENERGY_SHIELD=================================
Item_energy_shield::Item_energy_shield(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
										Damage_type destroyDamage_, Area_type destroyArea_,
										Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
										Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_,
										Enegry_shield_type maxShield_, Enegry_shield_type generateShield_)
									:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, inside_block, not_advance_block, no_matter_turn),
										ExplosiveItem(destroyDamage_, destroyArea_),
										ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_),
										maxShield(maxShield_), generateShield(generateShield_)
{
	
};

void Item_energy_shield::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.shieldLimit += maxShield;
};

void Item_energy_shield::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	if(oldMode == newMode)
	{
		return;
	}

	resourceRecount(attributes, oldMode, newMode);
	if(newMode == powerOff)
	{
		attributes.shieldNow -= maxShield;
		if(attributes.shieldNow < 0)
		{
			attributes.shieldNow = 0;
		}
		if(oldMode == modeAverage)
		{
			attributes.shieldChange -= generateShield;
		}		
	}
	else if(newMode == modeLow && oldMode == modeAverage)
	{
		attributes.shieldChange -= generateShield;
	}
	else if(newMode == modeAverage)
	{
		attributes.shieldChange += generateShield;
	}

};

void Item_energy_shield::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	recountAttributes(attributes, oldMode, powerOff, position);
	addWeightToAttributes(attributes, aRemove);
	attributes.shieldLimit -= maxShield;
};
//-------------------------------------------------------------------


//===================================================================
//=====================ACTIVE_COOLING================================
Item_active_cooling::Item_active_cooling(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
											Energy_type energyNeedLow_, Cooling_type coolingNeedLow_,
											Energy_type energyNeedAverage_, Cooling_type coolingNeedAverage_)
										:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, inside_block, not_advance_block, no_matter_turn),
											ResourceConsumingItem(modeAverage, energyNeedLow_, coolingNeedLow_, energyNeedAverage_, coolingNeedAverage_)
{
	
};

void Item_active_cooling::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
};

void Item_active_cooling::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	resourceRecount(attributes, oldMode, newMode);
};

void Item_active_cooling::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	recountAttributes(attributes, oldMode, powerOff, position);
	addWeightToAttributes(attributes, aRemove);
};

//-------------------------------------------------------------------


//===================================================================
//=====================ENERGY_STORAGE================================
Item_energy_storage::Item_energy_storage(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
											Damage_type destroyDamage_, Area_type destroyArea_,
											Energy_storage_type accumulator_)
										:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, inside_block, not_advance_block, no_matter_turn),
											ExplosiveItem(destroyDamage_, destroyArea_),
											accumulator(accumulator_)
{
	
};

void Item_energy_storage::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.energyLimit += accumulator;
};

void Item_energy_storage::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	
};

void Item_energy_storage::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aRemove);
	attributes.energyLimit -= accumulator;
};
//-------------------------------------------------------------------


//===================================================================
//=====================BALLISTIC_WEAPON==============================
Item_ballistic_weapon::Item_ballistic_weapon(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
												ExplosiveItem::Damage_type destroyDamage_, ExplosiveItem::Area_type destroyArea_,
												Energy_type energyReduction_, Cooling_type heat_,
												WeaponItem::Damage_type damage_, WeaponItem::Area_type area_, Speed_type speed_)
											:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, weapon_block, not_advance_block, no_matter_turn),
												ExplosiveItem(destroyDamage_, destroyArea_),
												OnceResourceConsumingItem(energyReduction_, heat_),
												WeaponItem(damage_, area_, speed_)
{
	
};

void Item_ballistic_weapon::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
};

void Item_ballistic_weapon::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	
};

void Item_ballistic_weapon::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aRemove);
};
//-------------------------------------------------------------------

//===================================================================
//=====================RADIATOR======================================
Item_radiator::Item_radiator(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
											Cooling_storage_type heat_)
										:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, inside_block, not_advance_block, no_matter_turn),
											heat(heat_)
{
	
};

void Item_radiator::addAttributes(NewShipAttributes& attributes, Turn_item_type turn, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.overheatLimit += heat;
};

void Item_radiator::recountAttributes(NewShipAttributes& attributes, ItemMode oldMode, ItemMode newMode, std::pair<int, int> position) const
{
	
};

void Item_radiator::removeAttributes(NewShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, std::pair<int, int> position) const
{
	addWeightToAttributes(attributes, aRemove);
	attributes.overheatLimit -= heat;
};
//-------------------------------------------------------------------