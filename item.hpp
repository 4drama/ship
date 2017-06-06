#ifndef ITEM__
#define ITEM__

#include "ship_attributes.hpp"
#include "enum_types.hpp"

//===================================================================
//=====================ABSTRACT_ITEM_CLASS===========================
class Item
{
protected:	
	typedef int Weight_type;
	typedef int Item_size_type;	
	typedef int Durability_type;
	typedef int Damage_type;
	typedef int Area_type;
	
	typedef int Power_type;
	typedef int Max_speed_type;
	typedef int Acceleration_type;
	
	typedef int Energy_type;
	typedef int Cooling_type;
	
	Weight_type Weight;
	
private:	
	
	
	Item_size_type Size_width;
	Item_size_type Size_height;
	bool Turn_matter_advance;
	
	int durability;
	int destroyDamage;
	int destroyArea;
	
public:
	virtual ~Item() = 0;
	
	virtual Base_block_type Get_base() const;
	virtual Turn_item_type getTurnItem() const;
	virtual Advanced_block_type getAdvanceBlock() const;
	
	virtual void addAttributes(ShipAttributes&, Turn_item_type, int) const;
	virtual void recountAttributes(ShipAttributes&, ItemMode, ItemMode) const;
	virtual void removeAttributes(ShipAttributes&, Turn_item_type, ItemMode, int) const;
	
	bool Get_turn_matter_advance() const;
	
	Item_size_type Get_width() const;
	Item_size_type Get_height() const;
	
protected:	
	Item(Weight_type, Item_size_type, Item_size_type, bool, Durability_type, Damage_type, Area_type);	
};
//-------------------------------------------------------------------



//===================================================================
//=====================MAIN_ENGINE===================================
class Item_main_engine : public Item
{
private:

	const Base_block_type Base = engine_block;
	const Turn_item_type turnItem = down_turn;
	
	Power_type power;
	Max_speed_type maxSpeed;
	Acceleration_type acceleration;
	
	ItemMode maxMode = modeAverage;
	
	//===Low mode	
	Energy_type energyNeedLow;
	Cooling_type coolingNeedLow;
	
	//===Average mode		
	Energy_type energyNeedAverage;
	Cooling_type coolingNeedAverage;
	
public:
	
	Item_main_engine(	Weight_type, Item_size_type, Item_size_type, Durability_type, Damage_type, Area_type, 
						Power_type, Max_speed_type, Acceleration_type,
						Energy_type, Cooling_type,																//Low mode
						Energy_type, Cooling_type);																//Average mode
						
	Base_block_type Get_base() const;
	Turn_item_type getTurnItem() const;
	
	void addAttributes(ShipAttributes&, Turn_item_type, int) const;
	void recountAttributes(ShipAttributes&, ItemMode, ItemMode) const;
	void removeAttributes(ShipAttributes&, Turn_item_type, ItemMode, int) const;
};
//-------------------------------------------------------------------



//===================================================================
//=====================HELP_ENGINE===================================
class Item_help_engine : public Item
{
private:

	const Advanced_block_type Advance = outside_engine_block;
	
	Power_type power;
	Max_speed_type maxSpeed;
	
	ItemMode maxMode = modeAverage;
	
	//===Low mode	
	Energy_type energyNeedLow;
	Cooling_type coolingNeedLow;
	
	//===Average mode		
	Energy_type energyNeedAverage;
	Cooling_type coolingNeedAverage;	

public:
	
	Item_help_engine(	Weight_type, Item_size_type, Item_size_type, Durability_type, Damage_type, Area_type,
						Power_type, Max_speed_type,
						Energy_type, Cooling_type,																//Low mode
						Energy_type, Cooling_type);																//Average mode
	
	Advanced_block_type getAdvanceBlock() const;
	
	void addAttributes(ShipAttributes&, Turn_item_type, int) const;
	void recountAttributes(ShipAttributes&, ItemMode, ItemMode) const;
	void removeAttributes(ShipAttributes&, Turn_item_type, ItemMode, int) const;
};
//-------------------------------------------------------------------


#endif