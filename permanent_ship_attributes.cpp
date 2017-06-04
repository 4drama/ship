#include "permanent_ship_attributes.hpp"

#include <iostream>
	
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
	double rightSpeedRate = (1-currentWeight/(rightTurnEngineCapacity*20))*0.4*rightLongToEngines;
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
	std::cout << "Max speed: " << maxSpeed << std::endl;
	std::cout << "Acceleration speed: " << accelerationSpeed << std::endl;
	std::cout << "Left turn rate: " << leftTurnRate << std::endl;
	std::cout << "Right turn rate: " << rightTurnRate << std::endl;
	std::cout << "Left strafe speed: " << leftStrafeSpeed << std::endl;
	std::cout << "Right strafe speed: " << rightStrafeSpeed << std::endl;
	std::cout << "Braking speed: " << brakingSpeed << std::endl;
};