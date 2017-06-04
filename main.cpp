#include "collector.hpp"
#include "set_item.hpp"
#include <iostream>

#include "ship_attributes.hpp"

int main()
{
	ShipAttributes d2;
	d2.recountAttributes();
	d2.debugPermanentAttributes();
	d2.debugAttributes();
	d2.nextStep();
	d2.debugAttributes();
	d2.nextStep();
	d2.debugAttributes();
	
	Ship Ship1 = CreateHawkMK1();	
	Item_main_engine Bib(2500, 3, 9);
	Item_help_engine Eng(200, 2, 2);
	
	std::cout << std::endl;
	Ship1.setItem(Bib, down_turn, 0, 13);
	Ship1.setItem(Bib, down_turn, 7, 13);		
	Ship1.setItem(Eng, left_turn, 0, 7);
	Ship1.setItem(Eng, up_turn, 4, 3);
	
	Ship1.Debug_print();
//	std::cout << std::endl;
//	Ship1.removeItem(0, 13);
//	Ship1.Debug_print();
//	std::cout << std::endl;
	

	return 0;
};