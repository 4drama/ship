#ifndef ITEM__
#define ITEM__


#include <utility>


//#include "ship_attributes.hpp"
#include "new_ship_attributes.hpp"

#include "enum_types.hpp"

#include "string"

//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
class Item
{
protected:	
	typedef std::string Name_type;
	typedef int Weight_type;
	typedef int Item_size_type;	
	typedef int Durability_type;
//	typedef int Damage_type;
//	typedef int Area_type;
	
	typedef int Power_type;
	typedef int Max_speed_type;
	typedef int Acceleration_type;
	typedef int Enegry_shield_type;
	typedef int Energy_storage_type;
	
//	typedef int Energy_type;	
//	typedef int Cooling_type;	
	
	
	
private:	
	
	Name_type name;
	Weight_type Weight;
	Item_size_type Size_width;
	Item_size_type Size_height;
	bool Turn_matter_advance;
	
	Durability_type durability;
//	Damage_type destroyDamage;
//	Area_type destroyArea;
	
	Base_block_type base;
	Advanced_block_type advance;
	Turn_item_type turnItem;
	
public:
	virtual ~Item() = 0;
	
	virtual Base_block_type Get_base() const;
	virtual Turn_item_type getTurnItem() const;
	virtual Advanced_block_type getAdvanceBlock() const;
	
	virtual void addAttributes(NewShipAttributes&, Turn_item_type, int) const;
	virtual void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const;
	virtual void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const;
	
	bool Get_turn_matter_advance() const;
	
	Item_size_type Get_width() const;
	Item_size_type Get_height() const;
	Durability_type getDurability() const;
	Name_type getName() const;
	
protected:	
	Item(	Name_type, Weight_type, Item_size_type, Item_size_type, bool, Durability_type,
			Base_block_type = no_matter_block, Advanced_block_type = not_advance_block, Turn_item_type = no_matter_turn);
	
	void addWeightToAttributes(NewShipAttributes&, Attributes_aAdd_or_aRemove_type) const;
};
//-------------------------------------------------------------------


//===================================================================
//===============ABSTRACT_RESOURCE_CONSUMING_ITEM_CLASS==============
class ResourceConsumingItem
{
protected:	
	typedef int Energy_type;
	typedef int Cooling_type;
private:
	
	ItemMode maxMode;
	
	//===Low mode	
	Energy_type energyNeedLow;
	Cooling_type coolingNeedLow;
	
	//===Average mode		
	Energy_type energyNeedAverage;
	Cooling_type coolingNeedAverage;
	
	//===High mode
	Energy_type energyNeedHigh;
	Cooling_type coolingNeedHigh;
	
public:	
	virtual ~ResourceConsumingItem() = 0;	
	
protected:
	ResourceConsumingItem(ItemMode, Energy_type, Cooling_type, Energy_type=0, Cooling_type=0, Energy_type=0, Cooling_type=0);
	
	void resourceRecount(NewShipAttributes&, ItemMode, ItemMode) const;
};
//-------------------------------------------------------------------

//===================================================================
//===============ABSTRACT_ONCE_RESOURCE_CONSUMING_ITEM_CLASS=========
class OnceResourceConsumingItem
{
protected:
	typedef int Energy_type;
	typedef int Cooling_type;
private:
	Energy_type energyReduction;
	Cooling_type heat;
public:	
	virtual ~OnceResourceConsumingItem() = 0;
protected:
	OnceResourceConsumingItem(	Energy_type, Cooling_type);
	void reductionAttributes(	NewShipAttributes&);
};
//-------------------------------------------------------------------


//===================================================================
//===============ABSTRACT_EXPLOSIVE_ITEM_CLASS=======================
class ExplosiveItem
{
protected:
	typedef int Damage_type;
	typedef int Area_type;
private:
	Damage_type destroyDamage;
	Area_type destroyArea;
public:
	virtual ~ExplosiveItem() = 0;
protected:
	ExplosiveItem(	Damage_type, Area_type);
};
//-------------------------------------------------------------------


//===================================================================
//===============ABSTRACT_WEAPON_ITEM_CLASS==========================
class WeaponItem
{
protected:
	typedef int Damage_type;
	typedef int Area_type;
	typedef int Speed_type;
private:
	Damage_type damage;
	Area_type area;
	Speed_type speed;
public:
	virtual ~WeaponItem() = 0;
protected:
	WeaponItem(	Damage_type, Area_type, Speed_type);
};
//-------------------------------------------------------------------


//===================================================================
//=====================MAIN_ENGINE===================================
class Item_main_engine final: public Item, public ExplosiveItem, public ResourceConsumingItem 
{
private:

	Power_type power;
	Max_speed_type maxSpeed;
	Acceleration_type acceleration;

public:
	
	Item_main_engine(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type, 
						Damage_type, Area_type, 
						Power_type, Max_speed_type, Acceleration_type,
						Energy_type, Cooling_type,																//Low mode
						Energy_type, Cooling_type);																//Average mode

	void addAttributes (NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
};
//-------------------------------------------------------------------



//===================================================================
//=====================HELP_ENGINE===================================
class Item_help_engine final: public Item, public ResourceConsumingItem
{
private:
	
	Power_type power;
	Max_speed_type maxSpeed;

	void logicAdd(NewShipAttributes&, ItemMode, ItemMode, std::pair<int, int>) const;
	
public:
	
	Item_help_engine(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
						Power_type, Max_speed_type,
						Energy_type, Cooling_type,																//Low mode
						Energy_type, Cooling_type);																//Average mode

	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode, std::pair<int, int>) const;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, std::pair<int, int>) const;
};
//-------------------------------------------------------------------



//===================================================================
//=====================CABIN=========================================
class Item_cabina final: public Item, public ResourceConsumingItem
{
private:


public:

	Item_cabina(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
					Energy_type, Cooling_type);
	
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
	
};
//-------------------------------------------------------------------

//===================================================================
//=====================GATE==========================================
class Item_gate final: public Item
{
private:
	
	Item_size_type gateSize;
	
public:

	Item_gate(		Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
					Item_size_type);

	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;

};
//-------------------------------------------------------------------

//===================================================================
//=====================CARGO_CELL====================================
class Item_cargo_cell final: public Item
{
private:
	
	Item_size_type cargoWidth;
	Item_size_type cargoHeight;
	
public:
	
	Item_cargo_cell(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
						Item_size_type, Item_size_type);
	
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
	
};
//-------------------------------------------------------------------


//===================================================================
//=====================POWER_GENERATOR===============================
class Item_power_generator final: public Item, public ExplosiveItem, public ResourceConsumingItem 
{
private:

public:
	Item_power_generator(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
							Damage_type, Area_type, 
							Energy_type, Cooling_type);
	
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
};
//-------------------------------------------------------------------


//===================================================================
//=====================ENERGY_SHIELD=================================
class Item_energy_shield final: public Item, public ExplosiveItem, public ResourceConsumingItem 
{
private:
	Enegry_shield_type maxShield;
	Enegry_shield_type generateShield;
public:	
	Item_energy_shield(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
						Damage_type, Area_type, 
						Energy_type, Cooling_type,
						Energy_type, Cooling_type,
						Enegry_shield_type, Enegry_shield_type);
						
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
};
//-------------------------------------------------------------------


//===================================================================
//=====================ACTIVE_COOLING================================
class Item_active_cooling final: public Item, public ResourceConsumingItem
{
private:

public:
	Item_active_cooling(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
							Energy_type, Cooling_type,
							Energy_type, Cooling_type);
	
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;								
};
//-------------------------------------------------------------------


//===================================================================
//=====================ENERGY_STORAGE================================
class Item_energy_storage final: public Item, public ExplosiveItem
{
private:
	Energy_storage_type accumulator;
public:	
	Item_energy_storage(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
							Damage_type, Area_type,
							Energy_storage_type);
	
	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
};
//-------------------------------------------------------------------

//===================================================================
//=====================BALLISTIC_WEAPON==============================
class Item_ballistic_weapon final: public Item, public ExplosiveItem, public OnceResourceConsumingItem, public WeaponItem
{
private:
	
public:
	Item_ballistic_weapon(	Name_type, Weight_type, Item_size_type, Item_size_type, Durability_type,
							ExplosiveItem::Damage_type, ExplosiveItem::Area_type,
							Energy_type, Cooling_type,
							WeaponItem::Damage_type, WeaponItem::Area_type, Speed_type);

	void addAttributes(NewShipAttributes&, Turn_item_type, int) const override;
	void recountAttributes(NewShipAttributes&, ItemMode, ItemMode) const override;
	void removeAttributes(NewShipAttributes&, Turn_item_type, ItemMode, int) const override;
};
//-------------------------------------------------------------------
#endif