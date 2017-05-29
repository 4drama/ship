#include "collector.hpp"



Ship CreateHawkMK1()
{
	Ship Biba_ship(22, 9);
	
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));		
	Biba_ship.AddShipStructInLine(0, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(0, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(1, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(2, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	
	Biba_ship.AddShipStructInLine(3, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(3, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(3, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(3, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	
	Biba_ship.AddShipStructInLine(4, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(4, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(4, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(4, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(5, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(5, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), outside_engine_to_up_block));
	
	Biba_ship.AddShipStructInLine(6, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(6, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(6, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), outside_engine_to_up_block));
	
	Biba_ship.AddShipStructInLine(7, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(7, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(3), cabin_block));
	Biba_ship.AddShipStructInLine(7, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(7, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(8, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(8, Create_block(inside_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(8, Create_block(inside_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(8, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(8, Create_block(citizen_block, Biba_ship.Return_group(3), gate_block));
	Biba_ship.AddShipStructInLine(8, Create_block(citizen_block, Biba_ship.Return_group(3), gate_block));
	Biba_ship.AddShipStructInLine(8, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(8, Create_block(inside_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(8, Create_block(inside_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(8, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(9, Create_block(inside_and_weapon_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(9, Create_block(inside_block, Biba_ship.Return_group(1), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(9, Create_block(inside_block, Biba_ship.Return_group(1), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(citizen_block, Biba_ship.Return_group(3), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(citizen_block, Biba_ship.Return_group(3), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(empty_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(inside_block, Biba_ship.Return_group(2), not_advance_block));
	Biba_ship.AddShipStructInLine(9, Create_block(inside_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(9, Create_block(inside_and_weapon_block, Biba_ship.Return_group(2), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(5), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(10, Create_block(citizen_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(10, Create_block(citizen_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(5), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(10, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));	
	
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(5), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(11, Create_block(citizen_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(11, Create_block(citizen_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(5), outside_engine_to_up_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(11, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(12, Create_block(inside_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), not_advance_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(13, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), outside_engine_to_left_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(4), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_block, Biba_ship.Return_group(5), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), not_advance_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	Biba_ship.AddShipStructInLine(14, Create_block(inside_and_engine_block, Biba_ship.Return_group(6), outside_engine_to_right_block));
	
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(15, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(16, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(17, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(18, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(19, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(20, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(7), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(inside_block, Biba_ship.Return_group(0), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	Biba_ship.AddShipStructInLine(21, Create_block(engine_block, Biba_ship.Return_group(8), not_advance_block));
	
	
//	Biba_ship.Debug_print();
	
	return Biba_ship;
};