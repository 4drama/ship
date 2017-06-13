#include "ship.hpp"

#include<iostream>
#include<iterator>

#include <algorithm>

Ship::Ship(Name_type name_, Block_size_type bsize_, Group_size_type gsize_, Weight_type weight_, Overheat_lmit_type overheat) : name(name_), itemsList(bsize_*bsize_/2)
{
	Blocks.resize(bsize_);	
	Groups.reserve(gsize_);
	
	for(Group_size_type i = 0; i<gsize_; ++i)
	{
		Groups.push_back(Group_type(i));
	};
	currentAttributes.permanentAttributes.currentWeight += weight_;
	currentAttributes.overheatLimit = overheat;
};

void Ship::Debug_print()
{
	std::cout << std::endl << "==============DEBUG_PRINT:==============" << std::endl;
	
	for(int i = 0, size = Blocks.size(); i<size; ++i)
	{
		for(int b = 0, size = Blocks[i].size(); b<size; ++b)
		{
			
			//auto a1 = Blocks[i][b].Get_group();
			
			
			if( Blocks[i][b].Get_group()->Get_number() != 0) 
			{
				int a1;
				a1 = 0;
				if(!Blocks[i][b].getKey() == 0)
				{
					a1 = 1;
				};
				std::cout<<a1<<Blocks[i][b].Get_group()->Get_number();
			}
			else
			{
				std::cout<<"  ";
			}
			
		};
		std::cout<<std::endl;
	};
	std::cout << "========================================" << std::endl << std::endl;
	currentAttributes.debugAttributes();
//	currentAttributes.recountAttributes();
	currentAttributes.debugPermanentAttributes();
};

std::string Ship::getName() const
{
	return name;
};

void Ship::AddShipStructInLine(Line_number_type Line, Ship_struct Block)
{
	Blocks[Line].push_back(Block);
};

Ship_types::Groups_type::iterator Ship::Return_group(Group_size_type Number)
{
	Ship_types::Groups_type::iterator it;
	it = Groups.begin() + Number;
	return it;
};

/*
Ship::Blocks_type* Ship::Get_blocks()
{
	return &Blocks;
};
*/

bool Ship::Block_check_struct_item(Item& Item_pointer_, Block_size_type X_call_, Block_size_type Y_call_, Turn_item_type Turn_)
{
	if
	(	
		(
			Item_pointer_.Get_base() == Blocks[Y_call_][X_call_].Get_first_type() ||
			Item_pointer_.Get_base() == Blocks[Y_call_][X_call_].Get_second_type() ||
			Item_pointer_.Get_base() == no_matter_block
		)
		&&
		(
			Item_pointer_.getTurnItem() == Turn_ ||
			Item_pointer_.getTurnItem() == no_matter_turn
		)
		&&
		(
			Item_pointer_.getAdvanceBlock() == not_advance_block ||
			Item_pointer_.getAdvanceBlock() == Blocks[Y_call_][X_call_].getFirstAdvance()
		)
		&&
		(
			Item_pointer_.Get_turn_matter_advance() == false ||
			Turn_ == Blocks[Y_call_][X_call_].getTurnTo()
		)
		&&
		(
			Blocks[Y_call_][X_call_].getKey() == 0
		)
	)
	{
		return true;
	};
		
	return false;
};


/*
void Ship::Block_set_struct_item(Set_item& Set_item_pointer_, Block_size_type X_call_, Block_size_type Y_call_)
{	
	Blocks[Y_call_][X_call_].Struct_set_item(Set_item_pointer_);
};
*/




void Ship::Block_reser_struct_item(Block_size_type x, Block_size_type y)
{
//	Blocks[x][y].Reset_ptr();
//	std::cout << "Debug: call destroy key. "<< x <<" " << y << std::endl;
	Blocks[x][y].destroyKey();
};


void Ship::powerOn()
{
	for ( auto it = itemsList.valueList.begin(); it!=itemsList.valueList.end(); it++ )
	{
		it->second->swithMode(modeLow);
	}
	
};

void Ship::powerOff()
{
	std::for_each(	itemsList.valueList.begin(), itemsList.valueList.end(), 		
					[](std::pair<int, Set_item*> i)
					{
						i.second->swithMode(ItemMode::powerOff);
					});
};

void Ship::setItem(Item* Itm, Turn_item_type Turn_, Block_size_type X_call_, Block_size_type Y_call_)
{
//	std::cout << "Debug: Ship::setItem begin" <<std::endl;
	int key = itemsList.add(new Set_item(*this, *Itm, currentAttributes, Turn_, X_call_, Y_call_));

	if(!keyFlag)
	{
		itemsList.erase(key);
		return;
	};
//	std::cout << "Debug: Ship::setItem step 1" << std::endl;
	auto width = Itm->Get_width();
	auto height = Itm->Get_height();
//	std::cout << "Debug: Ship::setItem step 2" << std::endl;
	auto* a1 = itemsList.find(key);
	
	if (Turn_ == left_turn || Turn_ == right_turn )
	{
		for(int x=X_call_, xto=X_call_+height; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+width; y<yto; ++y)
			{
				a1->addKeyingStruct(x, y);
				Blocks[y][x].setKey(key);
			};						
		};
	}
	else if(Turn_ == up_turn || Turn_ == down_turn)
	{
		for(int x=X_call_, xto=X_call_+width; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+height; y<yto; ++y)
			{
				a1->addKeyingStruct(x, y);
				Blocks[y][x].setKey(key);
			};						
		};
	}
	
	keyFlag = false;
//	std::cout << "Debug: Ship::setItem end" <<std::endl;
	//new Set_item(*this, Itm, Tu, x, y);
};

void Ship::removeItem(Key_type key)
{
	if(key != 0)
	{
		itemsList.erase(key);
	}
};

void Ship::removeItem(Block_size_type x, Block_size_type y)
{	
	int key = Blocks[y][x].getKey();
	this->removeItem(key);
};
	
void Ship::setStatus()
{
	keyFlag = true;
};

void Ship::showItems() const
{
	std::cout << std::endl;
	
	std::for_each(	itemsList.valueList.begin(), itemsList.valueList.end(), 		
					[](std::pair<int, Set_item*> i)
					{
						std::cout 	<< "Key: " << i.first << ". Name: " << i.second->getName() << ". Position: " 
									<< i.second->getPosition().first << " " << i.second->getPosition().second << "." << std::endl;
					});
	
	std::cout << std::endl;
};

void Ship::itemSetMode(ItemMode mode, Key_type key)
{
	auto* setItem = itemsList.find(key);
	setItem->swithMode(mode);
};

void Ship::itemSetMode(ItemMode mode, Position_type x, Position_type y)
{
	int key = Blocks[y][x].getKey();
	this->itemSetMode(mode, key);
};

void Ship::nextStep(int amount)
{
	while(amount--)
	{
		currentAttributes.nextStep();
	}

};

void Ship::action(Action_type action)
{
	std::for_each(	itemsList.valueList.begin(), itemsList.valueList.end(), 		
					[action, this](std::pair<int, Set_item*> i)
					{
						if(dynamic_cast<Item_main_engine*>(i.second->getItem()))
						{
							if(action == forwardMovement)
							{
								this->itemSetMode(modeAverage, i.first);
							}
							else if(action == idle)
							{
								this->itemSetMode(modeLow, i.first);
							}
							else if(action == backwardMovement)
							{
								this->itemSetMode(modeLow, i.first);
								//+frontengine
							}
						}
					});
	currentAttributes.actionNow = action;
};

Ship::~Ship()
{
/*	for(int i = 0, size = itemsList.size(); i<size; ++i)
	{
		itemsList.valueList.erase(i);
	}	*/
};