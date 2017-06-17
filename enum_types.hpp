#ifndef ENUM_TYPES__
#define ENUM_TYPES__

enum Base_block_type{
	empty_block = 0,
	weapon_block = 1,
	inside_block = 2,
	engine_block = 3,
	citizen_block = 4,
	no_matter_block = 5,
	inside_and_weapon_block = 21,
	inside_and_engine_block = 23
};

enum Advanced_block_type{
	not_advance_block = 0,
	gate_block = 1,
	outside_engine_block = 2,
//	outside_engine_to_left_block = 21,
//	outside_engine_to_right_block = 22,
//	outside_engine_to_up_block = 23,
//	outside_engine_to_down_block = 24,
	cabin_block = 3,
//	outside_and_cabin_block = 23
};

enum Turn_item_type{
	left_turn = 1,
	right_turn = 2,
	up_turn = 3,
	down_turn = 4,
	no_matter_turn = 5,
};

enum ItemMode{
	powerOff = 1,
	modeLow = 2,
	modeAverage = 3,
	modeHigh = 4,
};

enum Move_commands_type {
	stayFull = 1,
	stayMove = 2,
	stayTurn = 3,
	moveForward = 4,
	moveBackward = 5,
	moveLeft = 6,
	moveRight = 7,
	turnLeft = 8,
	turnRight = 9,
	strafeLeft = 10,
	strafeRight = 11,
};

enum Attributes_aAdd_or_aRemove_type
{
	aAdd = 1,
	aRemove = 2,
};

#endif