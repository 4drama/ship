#ifndef NEW_SHIP_ATTRIBUTES__
#define NEW_SHIP_ATTRIBUTES__

#include <vector>

#include "enum_types.hpp"
#include "resource_status.hpp"

struct Resource_status;

struct NewShipAttributes
{
	typedef int Key_type;
	typedef std::vector<Key_type> Vector_keys_type;

//======================================================
//=====================KEYS=============================
//============Main_Engines=========
	Vector_keys_type leftMainEngines;
	Vector_keys_type middleMainEngines;
	Vector_keys_type rightMainEngines;
//============Help_Engines=========
	Vector_keys_type frontHelpEngines;
	
	Vector_keys_type leftFrontHelpEngines;
	Vector_keys_type rightBackHelpEngines;
	
	Vector_keys_type leftBackHelpEngines;	
	Vector_keys_type rightFrontHelpEngines;
	
//============Cabin================
	Vector_keys_type cabins;
//============Gate=================
	Vector_keys_type gates;
//============Cargo_cell===========
	Vector_keys_type cargoCells;
//============Power_generator======
	Vector_keys_type powerGenerators;
//============Energy_shield========
	Vector_keys_type energyShields;
//============Active_cooling=======
	Vector_keys_type activeCoolings;
//============Energy_storage=======
	Vector_keys_type enegryStorage;
//============Ballistic_weapon=====
	Vector_keys_type ballisticWeapon;	
//============Radiatiors===========	
	Vector_keys_type radiators;
//------------------------------------------------------

//======================================================
//=====================POSITION_TYPES===================
	std::pair<int, int> leftPos{0, 0};
	std::pair<int, int>	middlePos{0, 0};
	std::pair<int, int>	rightPos{0, 0};
	std::pair<int, int>	frontPos{0, 0};
	std::pair<int, int> backPos{0, 0};
//------------------------------------------------------
	
//======================================================
//=====================ATTRIBUTES=======================
	double currentWeight = 0;				//update in set or delete or power off/on items
	double mainPower = 0;
	double frontEnginePower = 0;
	double leftFrontPower = 0;
	int leftFrontPosition = 0;
	double leftBackPower = 0;
	int leftBackPosition = 0;
	double rightFrontPower = 0;
	int rightFrontPosition = 0;
	double rightBackPower = 0;
	int rightBackPosition = 0;
	
	
	
//=============================
	double leftEngineSpeed = 0;
	double middleEngineSpeed = 0;
	double rightEngineSpeed = 0;
//	double maxSpeed = 0;
	double potentialAcceleration = 0;		//update in change mode
	double frontEngineSpeed = 0;
	double leftFrontSpeed = 0;
	double leftBackSpeed = 0;
	double rightFrontSpeed = 0;
	double rightBackSpeed = 0;

	double mainEngineTurn = 0;
	double helpEngineTurn = 0;	
	
	double forwardingAccelerationSpeed = 0;	
	double forwardingSpeed = 0;
	double strafeSpeed = 0;
	double turnRateSpeed = 0;
//=============================	
	double overheatLimit = 0;
	double overheatNow = 0;
	double overheatChange = -20;
	
	double energyLimit = 0;
	double energyNow = 0;
	double energyChange = 0;
	
	double shieldLimit = 0;
	double shieldNow = 0;
	double shieldChange = 0;
	
	int hpLimit;
	int hpNow;
//------------------------------------------------------

//======================================================
//=====================FUNCTIONS========================
	void reckonForwardingSpeed();
	void reckonTurnOrStrafeSpeed();
	void printDebug() const;
	Resource_status nextStep(int);
//------------------------------------------------------
};

#endif