#include "ship_attributes.hpp"

#include <iostream>

void ShipAttributes::recountAttributes()
{
	permanentAttributes.reckonAllMotion();
};

void ShipAttributes::nextStep()
{
	
//=================position================


//================speed====================	
	if(actionNow == forwardMovement)
	{
		speedNow += accelerationNow;
	}
	else if(actionNow == backwardMovement)
	{
	speedNow += -brakingSpeedNow;
	}
	else if(actionNow == idle)
	{
		
	}
	
	accelerationNow = (1-(speedNow/permanentAttributes.maxSpeed))*permanentAttributes.accelerationSpeed;
	
//==============overheat===================	
	overheatNow += overheatChange;	
	if(overheatNow < 0)
	{
		overheatNow = 0;
	}
	else if(overheatNow > overheatLimit)
	{
		overheatNow = overheatLimit;
		//OVERHEATING
	}

//==============energy=====================	
	energyNow += energyChange;	
	if(energyNow < 0)
	{
		energyNow = 0;
		//POWER OFF
	}
	else if(energyNow > energyLimit)
	{
		energyNow = energyLimit;
	}

//=============shield=====================	
	shieldNow += shieldChange;	
	if(shieldNow < 0)
	{
		shieldNow = 0;
	}
	else if(shieldNow > shieldLimit)
	{
		shieldNow = shieldLimit;
	}
	
};

void ShipAttributes::debugAttributes()
{
	std::cout << std::endl;
	
	std::cout << "Speed: " << speedNow;
	
	if(actionNow == forwardMovement)
	{
		std::cout << " + " << accelerationNow << std::endl;
	}
	else if(actionNow == backwardMovement)
	{
		std::cout << " - " << brakingSpeedNow << std::endl;
	}
	else if(actionNow == idle)
	{
		std::cout << std::endl;
	}
	
	std::cout << "Overheat: " << overheatNow << "/" << overheatLimit;
	if(overheatChange > 0)
	{
		std::cout << " +" << overheatChange << std::endl;
	}
	else if(overheatChange < 0)
	{
		std::cout << " " << overheatChange << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
	
	std::cout << "Energy: " << energyNow << "/" << energyLimit;
	if(energyChange > 0)
	{
		std::cout << " +" << energyChange << std::endl;
	}
	else if(energyChange < 0)
	{
		std::cout << " " << energyChange << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
	
	std::cout << "Shield: " << shieldNow << "/" << shieldLimit << " +" << shieldChange << std::endl;
	
	std::cout << std::endl;
};

void ShipAttributes::debugPermanentAttributes()
{
	permanentAttributes.motionDebug();
};




