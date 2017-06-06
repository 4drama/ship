#include "collector.hpp"
#include "set_item.hpp"
#include <iostream>

#include "ship_attributes.hpp"

int main()
{
	ShipAttributes d2;
	Item_main_engine deg(1250, 3, 9, 900, 400, 4, 1900, 900, 100, 15, 8, 70, 20);
	Item* k2 = &deg;
	k2->addAttributes(d2, no_matter_turn, 0);
	k2->recountAttributes(d2, powerOff, modeAverage);
	k2->recountAttributes(d2, modeAverage, modeLow);
	k2->removeAttributes(d2, no_matter_turn, modeLow, 0);
	
	d2.recountAttributes();
	d2.debugPermanentAttributes();
	d2.debugAttributes();
	d2.nextStep();
	d2.debugAttributes();
	d2.nextStep();
	d2.debugAttributes();
	
	Ship Ship1 = CreateHawkMK1();	
	Item_main_engine Bib(1250, 3, 9, 900, 400, 4, 1900, 900, 100, 15, 8, 70, 20);
	Item_help_engine Eng(250, 2, 2, 400, 70, 2, 500, 200, 0, 0, 30, 8);
	
	std::cout << std::endl;
	Ship1.setItem(Bib, down_turn, 0, 13);
	Ship1.setItem(Bib, down_turn, 7, 13);		
	Ship1.setItem(Eng, left_turn, 0, 7);
	Ship1.setItem(Eng, left_turn, 0, 11);
	Ship1.setItem(Eng, right_turn, 8, 7);
	Ship1.setItem(Eng, right_turn, 8, 11);
	Ship1.setItem(Eng, up_turn, 4, 3);
	
	Ship1.Debug_print();
//	std::cout << std::endl;
//	Ship1.removeItem(0, 13);
//	Ship1.Debug_print();
//	std::cout << std::endl;
	

	return 0;
};