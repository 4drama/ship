#ifndef SHIP_ATTRIBUTES__
#define SHIP_ATTRIBUTES__

#include "permanent_ship_attributes.hpp"
#include "enum_types.hpp"

struct ShipAttributes
{
	PermanentShipAttributes permanentAttributes;
	
	double positionX;
	double positionY;
	double positionTurn;
	
	double leftEnginesPower;
	double rightEnginesPower;
	
	Action_type actionNow = forwardMovement;
	double speedNow = 0;	//
	double accelerationNow = 0;	//(1-(speedNow/permanentAttributes.currentSpeed))*permanentAttributes.accelerationSpeed
	double brakingSpeedNow = 0;	//speedNow-permanentAttributes.brakingSpeed
	
	int overheatLimit = 0;		//
	int overheatNow = 0;	//
	int overheatChange = 0;		//
	
	int energyLimit = 0;		//
	int energyNow = 0;		//
	int energyChange = 0;		//
	
	int shieldLimit = 0;		//
	int shieldNow = 0;		//
	int shieldChange = 0;		//
	
	int hpLimit;
	int hpNow;
//	int hpChange;

//	void recountPosition();
	void recountAttributes();
	void nextStep();
	void debugAttributes();
	void debugPermanentAttributes();
};

#endif