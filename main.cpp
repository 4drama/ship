#include "collector.hpp"
#include "set_item.hpp"
#include <iostream>

#include <chrono>

#include "ship_attributes.hpp"
#include "item_list.hpp"
#include "ship_preset.hpp"

int main()
{
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

	ItemList items;
	
	Ship Ship1 = CreateHawkMK1();	
	HawkMK1preset1(Ship1, items);
	
	std::cout << std::endl;	
	
	Ship1.powerOn();	
//	Ship1.powerOff();

	Ship1.itemSetMode(modeAverage, 0, 13);
	Ship1.itemSetMode(modeAverage, 7, 13);
	
	Ship1.itemSetMode(modeAverage, 3, 13);
	
	Ship1.itemSetMode(modeAverage, 8, 7);
	Ship1.itemSetMode(modeAverage, 0, 11);
	
//	Ship1.itemSetMode(modeAverage, 0, 7);
//	Ship1.itemSetMode(modeAverage, 8, 11);
//	Ship1.removeItem(8, 8);	
//	Ship1.action(forwardMovement);	
	Ship1.nextStep(5);
	
	Ship1.Debug_print();
	Ship1.showItems();


	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "\nPrinting took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us.\n\n";  
	
	return 0;
};