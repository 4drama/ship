#include "new_ship_attributes.hpp"

#include<iostream>
#include<iterator>
#include<algorithm>

void NewShipAttributes::reckonForwardingSpeed()
{	
	if(	(leftEngineSpeed != 0 || middleEngineSpeed != 0 || rightEngineSpeed != 0 ) &&
		potentialAcceleration != 0)
	{
		double rateWeight = currentWeight/(mainPower*4)*100;
	//	std::cerr << "DEBUG: rateWeight " << rateWeight << std::endl;
		double rateSpeed = (pow((-rateWeight/30.2+1.5),3)/2+3)*21;
	//	std::cerr << "DEBUG: rateSpeed " << rateSpeed << std::endl;
		double potentialSpeed = (leftEngineSpeed+middleEngineSpeed+rightEngineSpeed)/(leftMainEngines.size()+middleMainEngines.size()+rightMainEngines.size());
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

		if(BackwardSpeed < 0)
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
	
	if(leftEngineSpeed != 0 && rightEngineSpeed == 0)
	{
		double turnRate = (1-currentWeight/((mainPower)*20))*0.05;
		double rateSpeed = (leftEngineSpeed)/(leftMainEngines.size())*turnRate;
		if(rateSpeed > 0) 
		{
			mainEngineTurn = rateSpeed;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
			return;
		}
	}
	else if(rightEngineSpeed != 0 && leftEngineSpeed == 0)
	{
		double turnRate = (1-currentWeight/((mainPower)*20))*0.05;
		double rateSpeed = (rightEngineSpeed)/(rightMainEngines.size())*turnRate;
		if(-rateSpeed < 0) 
		{
			mainEngineTurn = -rateSpeed;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
			return;
		}
	}
	else
	{
		mainEngineTurn = 0;
		turnRateSpeed = helpEngineTurn+mainEngineTurn;
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
			helpEngineTurn = rateSpeed;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
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
			helpEngineTurn = -rateSpeed;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
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
			helpEngineTurn = 0;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
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
			helpEngineTurn = 0;
			turnRateSpeed = helpEngineTurn+mainEngineTurn;
			return;
		}
	}
	else
	{
	strafeSpeed = 0;
	helpEngineTurn = 0;
	turnRateSpeed = helpEngineTurn+mainEngineTurn;
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
	std::cout << "Max speed: " << leftEngineSpeed+middleEngineSpeed+rightEngineSpeed << std::endl;
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

Resource_status NewShipAttributes::nextStep(int divider)
{
	
	Resource_status status;
	status.shieldKeys = &energyShields;
//=============shield=====================	
	shieldNow += shieldChange/divider;	
	if(shieldNow < 0)
	{
		shieldNow = 0;
		status.shieldStatus =  Resource_status::Shield_status_type::shieldStatusNotFull;
	}
	else if(shieldNow > shieldLimit)
	{
		shieldNow = shieldLimit;
		status.shieldStatus = Resource_status::Shield_status_type::shieldStatusFull;
	}

//==============overheat===================	
	overheatNow += overheatChange/divider;	
	if(overheatNow < 0)
	{
		overheatNow = 0;
		status.overheatStatus = Resource_status::Overheat_status_type::overheatStatusGood;
	}
	else if(overheatNow > overheatLimit)
	{
		overheatNow = overheatLimit;
		status.overheatStatus = Resource_status::Overheat_status_type::overheatStatusBad;
	}

//==============energy=====================	
	energyNow += energyChange/divider;	
	if(energyNow < 0)
	{
		energyNow = 0;
		status.energyStatus = Resource_status::Energy_status_type::energyStatusBad;
	}
	else if(energyNow > energyLimit)
	{
		energyNow = energyLimit;
		status.energyStatus = Resource_status::Energy_status_type::energyStatusGood;
	}

	return status;
};

