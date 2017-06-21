#include "ship_preset.hpp"
#include <string>

void HawkMK1preset1(Ship& ship, ItemList& list)
{
	if(ship.getName() == "HawkMK1")
	{
		ship.setItem(list(1150), down_turn, 0, 13);
		ship.setItem(list(1150), down_turn, 7, 13);	
		ship.setItem(list(1450), left_turn, 0, 7);
		ship.setItem(list(1450), left_turn, 0, 11);
		ship.setItem(list(1450), right_turn, 8, 7);
		ship.setItem(list(1450), right_turn, 8, 11);
		ship.setItem(list(1450), up_turn, 4, 3);
		ship.setItem(list(1750), up_turn, 4, 5);
		ship.setItem(list(2050), up_turn, 4, 8);
		ship.setItem(list(2350), down_turn, 4, 9);
		ship.setItem(list(2650), up_turn, 0, 9);
		ship.setItem(list(2650), up_turn, 2, 10);
		ship.setItem(list(2650), up_turn, 6, 10);
		ship.setItem(list(2650), up_turn, 8, 9);
		ship.setItem(list(2950), up_turn, 3, 13);
		ship.setItem(list(3250), up_turn, 5, 13);
		ship.setItem(list(3550), up_turn, 0, 5);
		ship.setItem(list(3550), left_turn, 1, 6);
		ship.setItem(list(3550), left_turn, 7, 6);
		ship.setItem(list(3550), up_turn, 9, 5);
		ship.setItem(list(3551), up_turn, 2, 7);
		ship.setItem(list(3551), up_turn, 7, 7);
		ship.setItem(list(3551), left_turn, 2, 12);
		ship.setItem(list(3551), left_turn, 5, 12);
		ship.setItem(list(3851), up_turn, 1, 0);
		ship.setItem(list(3851), up_turn, 7, 0);
	}
};

void HawkMK1preset1(Ship* ship, ItemList& list)
{
	if(ship->getName() == "HawkMK1")
	{
		ship->setItem(list(1150), down_turn, 0, 13);
		ship->setItem(list(1150), down_turn, 7, 13);	
		ship->setItem(list(1450), left_turn, 0, 7);
		ship->setItem(list(1450), left_turn, 0, 11);
		ship->setItem(list(1450), right_turn, 8, 7);
		ship->setItem(list(1450), right_turn, 8, 11);
		ship->setItem(list(1450), up_turn, 4, 3);
		ship->setItem(list(1750), up_turn, 4, 5);
		ship->setItem(list(2050), up_turn, 4, 8);
		ship->setItem(list(2350), down_turn, 4, 9);
		ship->setItem(list(2650), up_turn, 0, 9);
		ship->setItem(list(2650), up_turn, 2, 10);
		ship->setItem(list(2650), up_turn, 6, 10);
		ship->setItem(list(2650), up_turn, 8, 9);
		ship->setItem(list(2950), up_turn, 3, 13);
		ship->setItem(list(3250), up_turn, 5, 13);
		ship->setItem(list(3550), up_turn, 0, 5);
		ship->setItem(list(3550), left_turn, 1, 6);
		ship->setItem(list(3550), left_turn, 7, 6);
		ship->setItem(list(3550), up_turn, 9, 5);
		ship->setItem(list(3551), up_turn, 2, 7);
		ship->setItem(list(3551), up_turn, 7, 7);
		ship->setItem(list(3551), left_turn, 2, 12);
		ship->setItem(list(3551), left_turn, 5, 12);
		ship->setItem(list(3851), up_turn, 1, 0);
		ship->setItem(list(3851), up_turn, 7, 0);
	}
};