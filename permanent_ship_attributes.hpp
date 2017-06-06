#ifndef PERMANENT_SHIP_ATTRIBUTES__
#define PERMANENT_SHIP_ATTRIBUTES__

#include <vector>
#include <cmath>
#include "enum_types.hpp"


struct MoveEngines
{
	
	typedef int Position_type;
	typedef int Power_type;
	typedef int Speed_type;
	
	int position;
	Turn_item_type turn;
	int power;
	int speed;
	
	MoveEngines(Position_type, Turn_item_type, Power_type, Speed_type);
	
};



struct PermanentShipAttributes
{
	
	int maxHP;
//	int currentHP;

//=====================motion==================================
	double engineCapacity = 3800; //engine capacity(sum all)
	double potentialWeight;
	double currentWeight = 10740;
	
	double generalEnginesSpeed = 1800; // sum engines speed
	int amountEngines = 2; //amount engines
	double potentialAcceleration = 200; // engine acceleration (sum all)
	double maxSpeed;
//	double currentSpeed;
	double accelerationSpeed;
	
	std::vector<MoveEngines> moveEnginesList;
	
	double leftTurnEngineCapacity = 1000; //turn engine capacity (sum LeftDown and RightUp)
	double rightTurnEngineCapacity = 1000; //turn engine capacity (sum LeftUp and RightDown)
	double generalLeftTurnRateEnginesSpeed = 400; //sum turn engines speed need to left turn
	int amountLeftTurnEngines = 2; //amount engines need to left turn
	double generalRightTurnRateEnginesSpeed = 400;
	int amountRightTurnEngines = 2; 
	int leftLongToEngines = 2;
	int rightLongToEngines = 2;
	double leftTurnRate;
	double rightTurnRate;
	
	double leftStrafeEngineCapacity = 1000;	 //turn engine capacity (sum Left engines)
	double rightStrafeEngineCapacity = 1000; //turn engine capacity (sum Right engines)
	double generalLeftStrafeSpeeds = 400; //sum turn engines speed need to Left Strafe
	int amountLeftStrafeEngines = 2; //amount engines need to Left Strafe
	double generalRightStrafeSpeeds = 400;
	int amountRightStrafeEngines = 2;
	double leftStrafeSpeed;
	double rightStrafeSpeed;
	
	double frontEngineCapacity = 500; // front engine capacity(sum all)
	double generalFrontEnginesSpeed = 200;//sum front engines speed
	int amountFrontEngines = 1; //amount front engines
	double brakingSpeed;
//-------------------------------------------------------------	
	

	
	void reckonPotentialWeight();
	void reckonSpeed();
	void reckonTurnRate();
	void reckonStrafeSpeed();
	void reckonBrakingSpeed();
	void reckonAllMotion();
	void motionDebug();
};

#endif