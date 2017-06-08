#include "permanent_ship_attributes.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>

MoveEngines::MoveEngines(Position_type position_, Turn_item_type turn_, Power_type power_, Speed_type speed_)
						:position(position_), turn(turn_), power(power_), speed(speed_)
{
	
};

void PermanentShipAttributes::recountMoveEnginesList()
{
	leftTurnEngineCapacity = 0; //turn engine capacity (sum LeftDown and RightUp)
	rightTurnEngineCapacity = 0; //turn engine capacity (sum LeftUp and RightDown)
	generalLeftTurnRateEnginesSpeed = 0; //sum turn engines speed need to left turn
	amountLeftTurnEngines = 0; //amount engines need to left turn
	generalRightTurnRateEnginesSpeed = 0;
	amountRightTurnEngines = 0; 
	leftLongToEngines = 0;
	rightLongToEngines = 0;
	
	leftStrafeEngineCapacity = 0;	 //turn engine capacity (sum Left engines)
	rightStrafeEngineCapacity = 0; //turn engine capacity (sum Right engines)
	generalLeftStrafeSpeeds = 0; //sum turn engines speed need to Left Strafe
	amountLeftStrafeEngines = 0; //amount engines need to Left Strafe
	generalRightStrafeSpeeds = 0;
	amountRightStrafeEngines = 0;
	
	frontEngineCapacity = 0; // front engine capacity(sum all)
	generalFrontEnginesSpeed = 0;//sum front engines speed
	amountFrontEngines = 0; //amount front engines
	
	std::vector<MoveEngines> leftEngines;
	std::vector<MoveEngines> rightEngines;
	std::vector<MoveEngines> upEngines;

	int maxLeftPosition = 0;
	int minLeftPosition = 0;
	
	int maxRightPosition = 0;
	int minRightPosition = 0;
	
	for(int i = 0, size = moveEnginesList.size(); i<size; ++i)
	{
		if(moveEnginesList[i].turn == left_turn && maxLeftPosition == 0)
		{
			maxLeftPosition = moveEnginesList[i].position;
			minLeftPosition = moveEnginesList[i].position;
		}
		else if(moveEnginesList[i].turn == right_turn && maxRightPosition == 0)
		{
			maxRightPosition = moveEnginesList[i].position;
			minRightPosition = moveEnginesList[i].position;
		}
		else if(maxLeftPosition != 0 && maxRightPosition != 0)
		{
			break;
		}
	}
		
	for(int i = 0, size = moveEnginesList.size(); i<size; ++i)
	{
		if(moveEnginesList[i].turn == left_turn)
		{
			if(moveEnginesList[i].position > maxLeftPosition)
			{
				maxLeftPosition = moveEnginesList[i].position;
			}
			
			if(moveEnginesList[i].position < minLeftPosition)
			{
				minLeftPosition = moveEnginesList[i].position;
			}
			
			leftEngines.push_back(moveEnginesList[i]);
		}
		else if(moveEnginesList[i].turn == right_turn)
		{
			if(moveEnginesList[i].position > maxRightPosition)
			{
				maxRightPosition = moveEnginesList[i].position;
			}
			
			if(moveEnginesList[i].position < minRightPosition)
			{
				minRightPosition = moveEnginesList[i].position;
			}
			
			rightEngines.push_back(moveEnginesList[i]);
		}
		else if(moveEnginesList[i].turn == up_turn)
		{
			upEngines.push_back(moveEnginesList[i]);
		}
	};
	
	int avarageLeftPosition = (maxLeftPosition + minLeftPosition)/2;
	int avarageRightPosition = (maxRightPosition + minRightPosition)/2;
	
	int avaragePosition = (avarageLeftPosition + avarageRightPosition)/2;
//	std::cerr << " maxLeftPosition:" << maxLeftPosition << " minLeftPosition:" << minLeftPosition << std::endl;
//	std::cerr << " maxRightPosition:" << maxRightPosition << " minRightPosition:" << minRightPosition << std::endl;
	
	std::vector<MoveEngines> leftUpEngines;
	std::vector<MoveEngines> leftDownEngines;
	std::vector<MoveEngines> rightUpEngines;
	std::vector<MoveEngines> rightDownEngines;
	
	for(int i = 0, size = leftEngines.size(); i<size; ++i)
	{
		if(leftEngines[i].position > avaragePosition)
		{
			leftDownEngines.push_back(leftEngines[i]);
		}
		else if(leftEngines[i].position < avaragePosition)
		{
			leftUpEngines.push_back(leftEngines[i]);
		}
	}
	
	for(int i = 0, size = rightEngines.size(); i<size; ++i)
	{
		if(rightEngines[i].position > avaragePosition)
		{
			rightDownEngines.push_back(rightEngines[i]);
		}
		else if(rightEngines[i].position < avaragePosition)
		{
			rightUpEngines.push_back(rightEngines[i]);
		}
	}
	
	int longToRightMax = avarageRightPosition;
	int longToRightMin = avarageRightPosition;
	
	int longToLeftMax = avarageLeftPosition;
	int longToLeftMin = avarageLeftPosition;
	
//	std::cerr << std::endl <<"longToLeftMin " << longToLeftMin << " longToLeftMax " << longToLeftMax << std::endl;
//	std::cerr <<"longToRightMin " << longToRightMin << " longToRightMax " << longToRightMax << std::endl << std::endl;	
	
	for(int i = 0, size = leftUpEngines.size(); i<size; ++i)
	{
		rightTurnEngineCapacity += leftUpEngines[i].power;
		generalRightTurnRateEnginesSpeed += leftUpEngines[i].speed;
		amountRightTurnEngines ++;
		if(leftUpEngines[i].position < longToRightMax)
		{
			longToRightMax = leftUpEngines[i].position;
		}
		
		
		rightStrafeEngineCapacity += leftUpEngines[i].power;
		generalRightStrafeSpeeds += leftUpEngines[i].speed;
		amountRightStrafeEngines++;

	}
	for(int i = 0, size = leftDownEngines.size(); i<size; ++i)
	{
		leftTurnEngineCapacity += leftDownEngines[i].power;
		generalLeftTurnRateEnginesSpeed += leftDownEngines[i].speed;
		amountLeftTurnEngines ++;
		if(leftDownEngines[i].position > longToLeftMin)
		{
			longToLeftMin = leftDownEngines[i].position;
		}
		
		
		rightStrafeEngineCapacity += leftDownEngines[i].power;
		generalRightStrafeSpeeds += leftDownEngines[i].speed;
		amountRightStrafeEngines++;

	}
	for(int i = 0, size = rightUpEngines.size(); i<size; ++i)
	{
		leftTurnEngineCapacity += rightUpEngines[i].power;
		generalLeftTurnRateEnginesSpeed += rightUpEngines[i].speed;
		amountLeftTurnEngines ++;
		if(rightUpEngines[i].position < longToLeftMax)
		{
			longToLeftMax = rightUpEngines[i].position;
		}
		
		leftStrafeEngineCapacity += rightUpEngines[i].power;
		generalLeftStrafeSpeeds += rightUpEngines[i].speed;
		amountLeftStrafeEngines ++;

	}
	for(int i = 0, size = rightDownEngines.size(); i<size; ++i)
	{
		rightTurnEngineCapacity += rightDownEngines[i].power;
		generalRightTurnRateEnginesSpeed += rightDownEngines[i].speed;
		amountRightTurnEngines ++;
		if(rightDownEngines[i].position > longToRightMin)
		{
			longToRightMin = rightDownEngines[i].position;
		}
		
		leftStrafeEngineCapacity += rightDownEngines[i].power;
		generalLeftStrafeSpeeds += rightDownEngines[i].speed;
		amountLeftStrafeEngines ++;

	}
	
	leftLongToEngines = (longToLeftMin-longToLeftMax)/2;
	rightLongToEngines = (longToRightMin-longToRightMax)/2;

//	std::cerr << "longToLeftMin" << longToLeftMin << " longToLeftMax" << longToLeftMax << std::endl;
//	std::cerr << "longToRightMin" << longToRightMin << " longToRightMax" << longToRightMax << std::endl;
	
	for(int i = 0, size = upEngines.size(); i<size; ++i)
	{
	frontEngineCapacity += upEngines[i].power;
	generalFrontEnginesSpeed += upEngines[i].speed;
	amountFrontEngines ++;
	}
	
};

void PermanentShipAttributes::removeFromMoveEnginesList(int positionDel, Turn_item_type turnDel)
{
	auto it = std::find_if (moveEnginesList.begin(), moveEnginesList.end(), 
		[positionDel, turnDel](MoveEngines i)
		{return i.position == positionDel && i.turn == turnDel;} );
	moveEnginesList.erase(it);
};
	
void PermanentShipAttributes::reckonPotentialWeight()
{
	potentialWeight = 4*engineCapacity;
};

void PermanentShipAttributes::reckonSpeed()
{
	double rateWeight = currentWeight/potentialWeight*100;
	double rateSpeed = (pow((-rateWeight/30.2+1.5),3)/2+3)*21;
	double potentialSpeed = generalEnginesSpeed/amountEngines;
	maxSpeed = rateSpeed/100*potentialSpeed;
	accelerationSpeed = potentialAcceleration*rateSpeed/100;
};

void PermanentShipAttributes::reckonTurnRate()
{
	double leftSpeedRate = (1-currentWeight/(leftTurnEngineCapacity*20))*0.4*leftLongToEngines;
	if(leftSpeedRate < 0) {leftSpeedRate = 0;}
	//std::cerr << "leftSpeedRate" << leftSpeedRate << " leftTurnEngineCapacity" << leftTurnEngineCapacity << " leftLongToEngines"<< leftLongToEngines <<std::endl;
	double rightSpeedRate = (1-currentWeight/(rightTurnEngineCapacity*20))*0.4*rightLongToEngines;
	if(rightSpeedRate < 0) {rightSpeedRate=0;}
	//std::cerr << "rightSpeedRate" << rightSpeedRate << " rightTurnEngineCapacity" << rightTurnEngineCapacity << " rightLongToEngines"<< rightLongToEngines <<std::endl;
	double potentialLeftTurnRate = generalLeftTurnRateEnginesSpeed/amountLeftTurnEngines;
	double potentialRightTurnRate = generalRightTurnRateEnginesSpeed/amountRightTurnEngines;
	leftTurnRate = potentialLeftTurnRate * leftSpeedRate;
	rightTurnRate = potentialRightTurnRate * rightSpeedRate;
};

void PermanentShipAttributes::reckonStrafeSpeed()
{
	double leftStrafeRate = (1-currentWeight/(leftStrafeEngineCapacity*40))/2;
	double rightStrafeRate = (1-currentWeight/(rightStrafeEngineCapacity*40))/2;
	double potentialLeftStrafeSpeed = generalLeftStrafeSpeeds/amountLeftStrafeEngines;
	double potentialRightStrafeSpeed = generalRightStrafeSpeeds/amountRightStrafeEngines;
	leftStrafeSpeed = leftStrafeRate * potentialLeftStrafeSpeed;
	rightStrafeSpeed = rightStrafeRate * potentialRightStrafeSpeed;
};

void PermanentShipAttributes::reckonBrakingSpeed()
{
	double rateBrakingSpeed = (1-currentWeight/(frontEngineCapacity*40))/2;
	double potentialFrontEngineSpeed = generalFrontEnginesSpeed/amountFrontEngines;
	brakingSpeed = rateBrakingSpeed * potentialFrontEngineSpeed;
};

void PermanentShipAttributes::reckonAllMotion()
{
	reckonPotentialWeight();
	reckonSpeed();
	reckonTurnRate();
	reckonStrafeSpeed();
	reckonBrakingSpeed();
};

void PermanentShipAttributes::motionDebug()
{
	std::cout << "Weight: " << currentWeight << "/" << potentialWeight << std::endl << std::endl;
	
	std::cout << "Max speed: " << maxSpeed << std::endl;
	std::cout << "Acceleration speed: " << accelerationSpeed << std::endl;
	std::cout << "Left turn rate: " << leftTurnRate << std::endl;
	std::cout << "Right turn rate: " << rightTurnRate << std::endl;
	std::cout << "Left strafe speed: " << leftStrafeSpeed << std::endl;
	std::cout << "Right strafe speed: " << rightStrafeSpeed << std::endl;
	std::cout << "Braking speed: " << brakingSpeed << std::endl;
};