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

Base_block_type Item::Get_base() const
{
	return base;
};

Turn_item_type Item::getTurnItem() const
{
	return turnItem;
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
	return advance;
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

void OnceResourceConsumingItem::reductionAttributes(ShipAttributes& attributes)
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




//===================================================================
//=====================CABIN=========================================
Item_cabina::Item_cabina(	Name_type name_, Weight_type Weight_, Item_size_type Size_width_, Item_size_type Size_height_, Durability_type durability_,
							Energy_type energyNeedLow_, Cooling_type coolingNeedLow_)
						:	Item(name_, Weight_, Size_width_, Size_height_, 0, durability_, citizen_block, cabin_block, up_turn),
							ResourceConsumingItem(modeLow, energyNeedLow_, coolingNeedLow_)
{
	
};
	
void Item_cabina::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
};
	
void Item_cabina::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	resourceRecount(attributes, oldMode, newMode);
};
	
void Item_cabina::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
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

void Item_gate::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_gate::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	
};

void Item_gate::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
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

void Item_cargo_cell::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_cargo_cell::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	
};

void Item_cargo_cell::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
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

void Item_power_generator::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);	
};

void Item_power_generator::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	resourceRecount(attributes, oldMode, newMode);
};

void Item_power_generator::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
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

void Item_energy_shield::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.shieldLimit += maxShield;
};

void Item_energy_shield::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
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

void Item_energy_shield::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	recountAttributes(attributes, oldMode, powerOff);
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

void Item_active_cooling::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
};

void Item_active_cooling::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	resourceRecount(attributes, oldMode, newMode);
};

void Item_active_cooling::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	recountAttributes(attributes, oldMode, powerOff);
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

void Item_energy_storage::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
	attributes.energyLimit += accumulator;
};

void Item_energy_storage::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	
};

void Item_energy_storage::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
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

void Item_ballistic_weapon::addAttributes(ShipAttributes& attributes, Turn_item_type turn, int position) const
{
	addWeightToAttributes(attributes, aAdd);
};

void Item_ballistic_weapon::recountAttributes(ShipAttributes& attributes, ItemMode oldMode, ItemMode newMode) const
{
	
};

void Item_ballistic_weapon::removeAttributes(ShipAttributes& attributes, Turn_item_type turn, ItemMode oldMode, int position) const
{
	addWeightToAttributes(attributes, aRemove);
};
//-------------------------------------------------------------------