#include "new_ship_attributes.hpp"

#include<iostream>
#include<iterator>
#include<algorithm>

void NewShipAttributes::reckonForwardingSpeed()
{	
	if(maxSpeed != 0 && potentialAcceleration != 0)
	{
		double rateWeight = currentWeight/(mainPower*4)*100;
	//	std::cerr << "DEBUG: rateWeight " << rateWeight << std::endl;
		double rateSpeed = (pow((-rateWeight/30.2+1.5),3)/2+3)*21;
	//	std::cerr << "DEBUG: rateSpeed " << rateSpeed << std::endl;
		double potentialSpeed = maxSpeed/(leftMainEngines.size()+middleMainEngines.size()+rightMainEngines.size());
	//	std::cerr << "DEBUG: potentialSpeed " << potentialSpeed << std::endl;
		forwardingSpeed = rateSpeed/100*potentialSpeed;
		forwardingAccelerationSpeed = potentialAcceleration*rateSpeed/100;
	
		if(forwardingSpeed < 0 || forwardingAccelerationSpeed < 0)
		{
	//		std::cerr << "DEBUG: forwardingSpeed " << forwardingSpeed << std::endl;
			forwardingAccelerationSpeed = 0;
			forwardingSpeed = 0;
			return;
		}
	}
	else if(frontEngineSpeed != 0 && frontEnginePower != 0)
	{
		double rateBackward = (1-currentWeight/(frontEnginePower*40))/2;
		double BackwardSpeed = frontEngineSpeed/frontHelpEngines.size()*rateBackward;
		
		forwardingSpeed = -BackwardSpeed;
		
		if(BackwardSpeed > 0)
		{
			forwardingAccelerationSpeed = 0;
			forwardingSpeed = 0;
		}
	}
	else
	{
		forwardingAccelerationSpeed = 0;
		forwardingSpeed = 0;
	}
};

void NewShipAttributes::reckonTurnOrStrafeSpeed()
{
	if(leftFrontSpeed != 0 && rightBackSpeed != 0)
	{
		double diagonal = (rightBackPosition - leftFrontPosition)/2;
	//	std::cerr << "right turn. diagonal = " << diagonal << std::endl;
		double turnRate = (1-currentWeight/((leftFrontPower+rightBackPower)*20))*0.4*diagonal;
	//	std::cerr << "right turn. turnRate = " << turnRate << std::endl;
		double rateSpeed = (leftFrontSpeed+rightBackSpeed)/(leftFrontHelpEngines.size()+rightBackHelpEngines.size())*turnRate;
	//	std::cerr << "right turn. RateSpeed = " << rateSpeed << std::endl;
		if(rateSpeed > 0) 
		{
			strafeSpeed = 0;
			turnRateSpeed = rateSpeed;
			return;
		}
	}
	else if(leftBackSpeed != 0 && rightFrontSpeed != 0)
	{
		double diagonal = (leftBackPosition - rightFrontPosition)/2;
	//	std::cerr << "left turn. diagonal = " << diagonal << std::endl;
		double turnRate = (1-currentWeight/((leftBackPower+rightFrontPower)*20))*0.4*diagonal;
	//	std::cerr << "left turn. turnRate = " << turnRate << std::endl;
		double rateSpeed = (leftBackSpeed+rightFrontSpeed)/(leftBackHelpEngines.size()+rightFrontHelpEngines.size())*turnRate;
	//	std::cerr << "right turn. RateSpeed = " << rateSpeed << std::endl;
		if(rateSpeed > 0) 
		{
			strafeSpeed = 0;
			turnRateSpeed = -rateSpeed;
			return;
		}
	}
	else if(leftFrontSpeed != 0 && leftBackSpeed != 0)
	{
		double strafeRate = (1-currentWeight/((leftFrontPower+leftBackPower)*40))/2;
		double strSpeed = (leftFrontSpeed+leftBackSpeed)/(leftFrontHelpEngines.size()+leftBackHelpEngines.size())*strafeRate;
		if(strSpeed > 0) 
		{
			strafeSpeed = strSpeed;
			turnRateSpeed = 0;
			return;
		}
	}
	else if(rightFrontSpeed != 0 && rightBackSpeed != 0)
	{
		double strafeRate = (1-currentWeight/((rightFrontPower+rightBackPower)*40))/2;
		double strSpeed = (rightFrontSpeed+rightBackSpeed)/(rightFrontHelpEngines.size()+rightBackHelpEngines.size())*strafeRate;
		if(strSpeed > 0) 
		{
			strafeSpeed = -strSpeed;
			turnRateSpeed = 0;
			return;
		}
	}
	else
	{
	strafeSpeed = 0;
	turnRateSpeed = 0;
	}
};

void NewShipAttributes::printDebug() const
{
/*	std::cout << "frontHelpEngines size = " << frontHelpEngines.size() << std::endl;
	std::cout << "leftFrontHelpEngines size = " << leftFrontHelpEngines.size() << std::endl;
	std::cout << "rightBackHelpEngines size = " << rightBackHelpEngines.size() << std::endl;
	std::cout << "leftBackHelpEngines size = " << leftBackHelpEngines.size() << std::endl;
	std::cout << "rightFrontHelpEngines size = " << rightFrontHelpEngines.size() << std::endl;
*/	std::cout << std::endl;
	std::cout << "     Static attributes:" << std::endl;
	std::cout << "Current weight: " << currentWeight << std::endl;
	std::cout << "Main power: " << mainPower << std::endl;
	std::cout << "Front engines power: " << frontEnginePower << std::endl;
	std::cout << "Left front engines power: " << leftFrontPower << std::endl;
	std::cout << "Left front engines position: " << leftFrontPosition << std::endl;
	std::cout << "Left back engines power: " << leftBackPower << std::endl;
	std::cout << "Left back engines position: " << leftBackPosition << std::endl;
	std::cout << "Right front engines power: " << rightFrontPower << std::endl;
	std::cout << "Right front engines position: " << rightFrontPosition << std::endl;
	std::cout << "Right back engines power: " << rightBackPower << std::endl;
	std::cout << "Right back engines position: " << rightBackPosition << std::endl;
	std::cout << std::endl;
	std::cout << "     Used attributes:" << std::endl;
	std::cout << "Max speed: " << maxSpeed << std::endl;
	std::cout << "Potential acceleration: " << potentialAcceleration << std::endl;
	std::cout << "Front engines speed: " << frontEngineSpeed << std::endl;
	std::cout << "Left front engines speed: " << leftFrontSpeed << std::endl;
	std::cout << "Left back engines speed: " << leftBackSpeed << std::endl;	
	std::cout << "Right front engines speed: " << rightFrontSpeed << std::endl;	
	std::cout << "Right back engines speed: " << rightBackSpeed << std::endl;		
	std::cout << std::endl;	
	std::cout << "     Status:" << std::endl;
	std::cout << "Forwarding acceleration speed: " << forwardingAccelerationSpeed << std::endl;	
	std::cout << "Forwarding speed: " << forwardingSpeed << std::endl;
	std::cout << "Strafe speed: " << strafeSpeed << std::endl;
	std::cout << "Turn rate speed: " << turnRateSpeed << std::endl;
	std::cout << std::endl;
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

void NewShipAttributes::nextStep()
{
	//=================position================


//================speed====================	
/*	if(actionNow == forwardMovement)
	{
		speedNow += accelerationNow;
	}
	else if(actionNow == backwardMovement)
	{
	speedNow += -brakingSpeedNow;
	}
	else if(actionNow == idle && speedNow < 0)
	{
		speedNow = 0;
	}
	
	accelerationNow = (1-(speedNow/permanentAttributes.maxSpeed))*permanentAttributes.accelerationSpeed;
*/	
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

