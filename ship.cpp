#include "ship.hpp"

#include<iostream>
#include<iterator>

#include <algorithm>
#include <cmath>

Ship::Ship(	Name_type name_, Block_size_type bsize_, Block_size_type bsize_2, Group_size_type gsize_, Weight_type weight_, Overheat_lmit_type overheat,
			Left_side_type left, Middle_side_type middle, Right_side_type right, Front_side_type front, Back_side_type back)
		: 	name(name_), itemsList(bsize_*bsize_2/2)
{
	Blocks.resize(bsize_);	
	Groups.reserve(gsize_);
	
	for(Group_size_type i = 0; i<gsize_; ++i)
	{
	//	Groups.push_back(Group_type(i)); 
		Groups.push_back(std::make_shared<Group_type>(i));
	};
	currentAttributes.currentWeight += weight_;
	currentAttributes.overheatLimit = overheat;
	
	currentAttributes.leftPos = left;
	currentAttributes.middlePos = middle;
	currentAttributes.rightPos = right;
	currentAttributes.frontPos = front;
	currentAttributes.backPos = back;
	
	boxSize = sqrt(pow(bsize_*0.05,2)+pow(bsize_2*0.05,2))/2;
//	std::cerr << "Ship::Ship" << std::endl;
};

void Ship::Debug_print()
{
	std::cout << std::endl << "==============DEBUG_PRINT:==============" << std::dec << std::endl;
	
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
//	currentAttributes.debugAttributes();
//	currentAttributes.debugPermanentAttributes();
	currentAttributes.printDebug();
	
	std::cout << std::fixed << "Box size : " << boxSize*2 << " x " << boxSize*2 << std::endl;
	std::cout << "Position : x=" << xCurrent << " y=" << yCurrent << std::endl;
	std::cout << "Azimuth : " << azimuth << std::endl;
	std::cout << "Change position : x=" << xChange << " y=" << yChange << std::endl;
};

std::string Ship::getName() const
{
	return name;
};

void Ship::AddShipStructInLine(Line_number_type Line, Ship_struct Block)
{
	Blocks[Line].push_back(Block);
	
	int number = Blocks[Line][(Blocks[Line].size()-1)].groupNumber;
	
	auto it = std::find_if (Groups.begin(), Groups.end(), 
		[number](std::shared_ptr<Group_type> i)
		{return i->Get_number() == number;} );	
	
	Blocks[Line][(Blocks[Line].size()-1)].Group = *it;
};

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



void Ship::addOrRemoveItemKeyToAttributes(Key_type key, Item* itemPtr, Block_size_type x, Block_size_type y, Attributes_aAdd_or_aRemove_type action)
{
	std::vector<Key_type>* currentKeysList = nullptr;
	
	if(dynamic_cast<Item_main_engine*>(itemPtr))
	{
		if(x >= currentAttributes.leftPos.first && x <= currentAttributes.leftPos.second)
		{
			currentKeysList = &currentAttributes.leftMainEngines;
		}
		else if(x >= currentAttributes.middlePos.first && x <= currentAttributes.middlePos.second)
		{
			currentKeysList = &currentAttributes.middleMainEngines;
		}
		else if(x >= currentAttributes.rightPos.first && x <= currentAttributes.rightPos.second)
		{
			currentKeysList = &currentAttributes.rightMainEngines;
		}
	}
	else if (dynamic_cast<Item_help_engine*>(itemPtr))
	{
		if(y >= currentAttributes.frontPos.first && y <= currentAttributes.frontPos.second)
		{
			if(x >= currentAttributes.leftPos.first && x <= currentAttributes.leftPos.second)
			{
				currentKeysList = &currentAttributes.leftFrontHelpEngines;
			}
			else if(x >= currentAttributes.middlePos.first && x <= currentAttributes.middlePos.second)
			{
				currentKeysList = &currentAttributes.frontHelpEngines;
			}
			else if(x >= currentAttributes.rightPos.first && x <= currentAttributes.rightPos.second)
			{
				currentKeysList = &currentAttributes.rightFrontHelpEngines;
			}
		}
		else if(y >= currentAttributes.backPos.first && y <= currentAttributes.backPos.second)
		{
			if(x >= currentAttributes.leftPos.first && x <= currentAttributes.leftPos.second)
			{
				currentKeysList = &currentAttributes.leftBackHelpEngines;
			}
			else if(x >= currentAttributes.rightPos.first && x <= currentAttributes.rightPos.second)
			{
				currentKeysList = &currentAttributes.rightBackHelpEngines;
			}
		}
	}
	else if(dynamic_cast<Item_energy_shield*>(itemPtr))
	{
		currentKeysList = &currentAttributes.energyShields;
	}
	else if(dynamic_cast<Item_cabina*>(itemPtr))
	{
		currentKeysList = &currentAttributes.cabins;
	}
	else if(dynamic_cast<Item_gate*>(itemPtr))
	{
		currentKeysList = &currentAttributes.gates;
	}
	else if(dynamic_cast<Item_cargo_cell*>(itemPtr))
	{
		currentKeysList = &currentAttributes.cargoCells;
	}
	else if(dynamic_cast<Item_power_generator*>(itemPtr))
	{
		currentKeysList = &currentAttributes.powerGenerators;
	}
	else if(dynamic_cast<Item_active_cooling*>(itemPtr))
	{
		currentKeysList = &currentAttributes.activeCoolings;
	}
	else if(dynamic_cast<Item_energy_storage*>(itemPtr))
	{
		currentKeysList = &currentAttributes.enegryStorage;
	}
	else if(dynamic_cast<Item_ballistic_weapon*>(itemPtr))
	{
		currentKeysList = &currentAttributes.ballisticWeapon;
	}
	else
	{
		std::cerr << "ERROR: Ship::addOrRemoveItemKeyToAttributes. Invalid type." << std::endl;
	}
	
	if(action == aAdd)
	{
		currentKeysList->push_back(key);
	}
	else if(action == aRemove)
	{
		auto it = std::find_if (currentKeysList->begin(), currentKeysList->end(), 
		[key](int i)
		{return i == key;} );		
		currentKeysList->erase(it);
//		std::cerr << "DELETE :" << key << " " << &it << std::endl;
	}
	
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
	addOrRemoveItemKeyToAttributes(key, Itm, X_call_, Y_call_, aAdd);
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
		auto currentItem = itemsList.find(key);
		auto position = currentItem->getPosition();
		auto item = currentItem->getItem();
		
		addOrRemoveItemKeyToAttributes(key, item, position.first, position.second, aRemove);
		
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

void Ship::itemSetAllMode(ItemMode mode, std::vector<NewShipAttributes::Key_type>& keys)
{
	std::for_each(	keys.begin(), keys.end(), 		
					[this, mode](NewShipAttributes::Key_type key)
					{
						this->itemSetMode(mode, key);
					});
};

void Ship::moveCommand(Move_commands_type command)
{
	
	if (command == stayFull)
	{
		this->itemSetAllMode(modeLow, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightMainEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.frontHelpEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightBackHelpEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.leftBackHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightFrontHelpEngines);
	}
	else if(command == stayMove)
	{
		this->itemSetAllMode(modeLow, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightMainEngines);		
	}
	else if(command == stayTurn)
	{
		this->itemSetAllMode(modeLow, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightBackHelpEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.leftBackHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightFrontHelpEngines);
	}
	else if(command == moveForward)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.rightMainEngines);	
		
		this->itemSetAllMode(modeLow, currentAttributes.frontHelpEngines);	
	}
	else if(command == moveBackward)
	{
		this->itemSetAllMode(modeLow, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightMainEngines);	
		
		this->itemSetAllMode(modeAverage, currentAttributes.frontHelpEngines);		
	}
	else if(command == moveLeft)
	{
		this->itemSetAllMode(modeLow, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.rightMainEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.frontHelpEngines);	
	}
	else if(command == moveRight)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.leftMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.middleMainEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightMainEngines);
		
		this->itemSetAllMode(modeLow, currentAttributes.frontHelpEngines);	
	}
	else if(command == turnLeft)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.leftBackHelpEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.rightFrontHelpEngines);	

		this->itemSetAllMode(modeLow, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightBackHelpEngines);			
	}
	else if(command == turnRight)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.rightBackHelpEngines);	

		this->itemSetAllMode(modeLow, currentAttributes.leftBackHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightFrontHelpEngines);	
	}
	else if(command == strafeLeft)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.rightFrontHelpEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.rightBackHelpEngines);	

		this->itemSetAllMode(modeLow, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.leftBackHelpEngines);			
	}
	else if(command == strafeRight)
	{
		this->itemSetAllMode(modeAverage, currentAttributes.leftFrontHelpEngines);
		this->itemSetAllMode(modeAverage, currentAttributes.leftBackHelpEngines);	

		this->itemSetAllMode(modeLow, currentAttributes.rightFrontHelpEngines);
		this->itemSetAllMode(modeLow, currentAttributes.rightBackHelpEngines);					
	}
	else
	{
		std::cerr << "ERROR: Ship::moveCommand. Invalid command" << std::endl;
	}
};


void Ship::coordinateReckon()
{
	double oldSpeed = this->getSpeed();
	
	double forwardingSpeed = currentAttributes.forwardingSpeed;
	
	double accelerationSpeed;
	
	if(forwardingSpeed == 0)
	{
		accelerationSpeed = 0;
	}
	else
	{
		accelerationSpeed = (1-(oldSpeed/forwardingSpeed))*currentAttributes.forwardingAccelerationSpeed;
	}
	
	const double pi = 3.14159265358979323846;
	
	double horizontallyXChange = ((accelerationSpeed/1000)/update_frequency)*cos((90-azimuth)* pi / 180);
	double horizontallyYChange = ((accelerationSpeed/1000)/update_frequency)*sin((90-azimuth)* pi / 180);
	
	double verticallyXChange = ((currentAttributes.strafeSpeed/1000)/update_frequency)*cos((90-(90-azimuth))* pi / 180);
	double verticallyYChange = ((currentAttributes.strafeSpeed/1000)/update_frequency)*sin((90-(90-azimuth))* pi / 180)*-1;
	
	double oldXChange = xChange;
	double oldYChange = yChange;
	
	xChange = horizontallyXChange+verticallyXChange+(oldXChange*(1-0.1/update_frequency));
	yChange = horizontallyYChange+verticallyYChange+(oldYChange*(1-0.1/update_frequency));
	
	xCurrent += xChange;
	yCurrent += yChange;
	
	azimuth = static_cast<int>(azimuth + (currentAttributes.turnRateSpeed/1.5)/update_frequency)%360;

/*	std::cerr <<"forwardingSpeed " << currentAttributes.forwardingSpeed <<std::endl;
	std::cerr <<"forwardingAccelerationSpeed " << currentAttributes.forwardingAccelerationSpeed << std::endl;
	
	std::cerr <<"oldSpeed " << oldSpeed << std::endl;	
	std::cerr <<"accelerationSpeed " << accelerationSpeed << std::endl; 

	std::cerr <<"horizontallyXChange " << horizontallyXChange << std::endl; 
	std::cerr <<"horizontallyYChange " << horizontallyYChange << std::endl;
	
	std::cerr <<"verticallyXChange " << verticallyXChange << std::endl; 
	std::cerr <<"verticallyYChange " << verticallyYChange << std::endl;
	
	std::cerr <<"oldXChange " << oldXChange << std::endl; 
	std::cerr <<"oldYChange " << oldYChange << std::endl;
	
	std::cerr <<"xChange " << xChange << std::endl; 
	std::cerr <<"yChange " << yChange << std::endl; 	

	std::cerr <<"xCurrent " << xCurrent << std::endl; 
	std::cerr <<"yCurrent " << yCurrent << std::endl; 

	std::cerr <<"azimuth " << azimuth << std::endl << std::endl; */
	
};

void Ship::nextStep(int amount)
{
	
	while(amount--)
	{
		Resource_status status = currentAttributes.nextStep(update_frequency);
		if(	status.overheatStatus == Resource_status::Overheat_status_type::overheatStatusBad ||
			status.energyStatus == Resource_status::Energy_status_type::energyStatusBad)
		{
			this->powerOff();
		}
		
		if(status.shieldStatus == Resource_status::Shield_status_type::shieldStatusFull)
		{
			std::for_each(	status.shieldKeys->begin(), status.shieldKeys->end(),
			[this](int key)
			{
				this->itemSetMode(modeLow, key);
			});
		}
		
		this->coordinateReckon();
	}

};
/*
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
//	currentAttributes.actionNow = action;
};*/

Ship::~Ship()
{
/*	for(int i = 0, size = itemsList.size(); i<size; ++i)
	{
		itemsList.valueList.erase(i);
	}	*/
};