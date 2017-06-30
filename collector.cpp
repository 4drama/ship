#include "collector.hpp"

Ship CreateHawkMK1()
{
	
	Ship Biba_ship("HawkMK1", 22, 10, 9, 2000, 600, std::make_pair(0,2), std::make_pair(3,6), std::make_pair(7,9), std::make_pair(0,10), std::make_pair(11,21));
	
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));		
	Biba_ship.AddShipStructInLine(0, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(0, Ship_struct(empty_block, 0, not_advance_block));
	
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(1, Ship_struct(empty_block, 0, not_advance_block));
	
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(2, Ship_struct(empty_block, 0, not_advance_block));
	
	Biba_ship.AddShipStructInLine(3, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(inside_and_weapon_block, 3, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(3, Ship_struct(inside_and_weapon_block, 3, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(3, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(3, Ship_struct(empty_block, 0, not_advance_block));
	
	Biba_ship.AddShipStructInLine(4, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(inside_and_weapon_block, 3, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(4, Ship_struct(inside_and_weapon_block, 3, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(4, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(4, Ship_struct(empty_block, 0, not_advance_block));
	
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 4, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(5, Ship_struct(inside_and_weapon_block, 6, outside_engine_block, up_turn));
	
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_and_weapon_block, 4, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(6, Ship_struct(inside_and_weapon_block, 6, outside_engine_block, up_turn));
	
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_and_weapon_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(citizen_block, 3, cabin_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(7, Ship_struct(inside_and_weapon_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_and_weapon_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(citizen_block, 3, gate_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(citizen_block, 3, gate_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(8, Ship_struct(inside_and_weapon_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_and_weapon_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_block, 1, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(empty_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_block, 2, not_advance_block));
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(9, Ship_struct(inside_and_weapon_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 5, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(10, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(10, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 5, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(10, Ship_struct(inside_block, 6, outside_engine_block, right_turn));	
	
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 5, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(11, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(11, Ship_struct(citizen_block, 3, not_advance_block));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 5, outside_engine_block, up_turn));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(11, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(12, Ship_struct(inside_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 4, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 6, not_advance_block));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(13, Ship_struct(inside_and_engine_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 4, outside_engine_block, left_turn));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 4, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_block, 5, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 6, not_advance_block));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 6, outside_engine_block, right_turn));
	Biba_ship.AddShipStructInLine(14, Ship_struct(inside_and_engine_block, 6, outside_engine_block, right_turn));
	
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(15, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(16, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(17, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(18, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(19, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(20, Ship_struct(engine_block, 8, not_advance_block));
	
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 7, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(inside_block, 0, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 8, not_advance_block));
	Biba_ship.AddShipStructInLine(21, Ship_struct(engine_block, 8, not_advance_block));
	
	
//	Biba_ship.Debug_print();
	
	return Biba_ship;
};