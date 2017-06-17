#include <iostream>
#include <chrono>

#include "ship.hpp"
#include "item_list.hpp"
#include "ship_preset.hpp"
#include "collector.hpp"

int main()
{
	
	std::chrono::steady_clock::time_point startCreate = std::chrono::steady_clock::now();

	ItemList items;
	
	Ship Ship1 = CreateHawkMK1();	
	HawkMK1preset1(Ship1, items);	
	std::chrono::steady_clock::time_point endCreate = std::chrono::steady_clock::now();
	
	std::cout << std::endl;	
	
	std::chrono::steady_clock::time_point startUse = std::chrono::steady_clock::now();	
	
	Ship1.powerOn();	
//	Ship1.powerOff();

	Ship1.nextStep(5);
/*
	Ship1.itemSetMode(modeAverage, 0, 13);
	Ship1.itemSetMode(modeAverage, 7, 13);
		
//	Ship1.itemSetMode(modeAverage, 8, 7);
//	Ship1.itemSetMode(modeAverage, 0, 11);
	
	Ship1.itemSetMode(modeAverage, 0, 7);
	Ship1.itemSetMode(modeAverage, 8, 11);
*/	

	Ship1.itemSetMode(modeAverage, 3, 13);

	Ship1.moveCommand(moveForward);
	Ship1.moveCommand(turnLeft);
//	Ship1.removeItem(8, 8);	
//	Ship1.action(forwardMovement);	
	Ship1.nextStep(5);

	std::chrono::steady_clock::time_point endUse = std::chrono::steady_clock::now();
	
	Ship1.Debug_print();
	Ship1.showItems();


	std::cout	<< std::endl << "Printing took: Create - " 
				<< std::chrono::duration_cast<std::chrono::microseconds>(endCreate - startCreate).count()
				<< "us, Use - "
				<< std::chrono::duration_cast<std::chrono::microseconds>(endUse - startUse).count()
				<< "us." << std::endl;  
	
	return 0;
};