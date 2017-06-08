#include "ship_preset.hpp"
#include <string>

void HawkMK1preset1(Ship& ship, ItemList& list)
{
	if(ship.getName() == "HawkMK1")
	{
		ship.setItem(list(1001), down_turn, 0, 13);
		ship.setItem(list(1001), down_turn, 7, 13);		
		ship.setItem(list(1101), left_turn, 0, 7);
		ship.setItem(list(1101), left_turn, 0, 11);
		ship.setItem(list(1101), right_turn, 8, 7);
		ship.setItem(list(1101), right_turn, 8, 11);
		ship.setItem(list(1101), up_turn, 4, 3);
	}
};