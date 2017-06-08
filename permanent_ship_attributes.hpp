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
	double engineCapacity = 0; //engine capacity(sum all)
	double potentialWeight;
	double currentWeight = 0;
	
	double generalEnginesSpeed = 0; // sum engines speed
	int amountEngines = 0; //amount engines
	double potentialAcceleration = 0; // engine acceleration (sum all)
	double maxSpeed;
//	double currentSpeed;
	double accelerationSpeed;
	
	std::vector<MoveEngines> moveEnginesList;
	
	double leftTurnEngineCapacity = 0; //turn engine capacity (sum LeftDown and RightUp)
	double rightTurnEngineCapacity = 0; //turn engine capacity (sum LeftUp and RightDown)
	double generalLeftTurnRateEnginesSpeed = 0; //sum turn engines speed need to left turn
	int amountLeftTurnEngines = 0; //amount engines need to left turn
	double generalRightTurnRateEnginesSpeed = 0;
	int amountRightTurnEngines = 0; 
	int leftLongToEngines = 0;
	int rightLongToEngines = 0;
	double leftTurnRate;
	double rightTurnRate;
	
	double leftStrafeEngineCapacity = 0;	 //turn engine capacity (sum Left engines)
	double rightStrafeEngineCapacity = 0; //turn engine capacity (sum Right engines)
	double generalLeftStrafeSpeeds = 0; //sum turn engines speed need to Left Strafe
	int amountLeftStrafeEngines = 0; //amount engines need to Left Strafe
	double generalRightStrafeSpeeds = 0;
	int amountRightStrafeEngines = 0;
	double leftStrafeSpeed;
	double rightStrafeSpeed;
	
	double frontEngineCapacity = 0; // front engine capacity(sum all)
	double generalFrontEnginesSpeed = 0;//sum front engines speed
	int amountFrontEngines = 0; //amount front engines
	double brakingSpeed;
//-------------------------------------------------------------	
	
	void recountMoveEnginesList();
	void removeFromMoveEnginesList(int, Turn_item_type);
	
	void reckonPotentialWeight();
	void reckonSpeed();
	void reckonTurnRate();
	void reckonStrafeSpeed();
	void reckonBrakingSpeed();
	void reckonAllMotion();
	void motionDebug();
};

#endif