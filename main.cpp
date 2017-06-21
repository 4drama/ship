#include <iostream>
#include <chrono>

#include "ship.hpp"
#include "item_list.hpp"
#include "ship_preset.hpp"
#include "collector.hpp"

#include "object_list.hpp"

#include <memory>

int main()
{		
	std::chrono::steady_clock::time_point startCreate = std::chrono::steady_clock::now();

	set_update_frequency(1);
	
	ItemList items;		
	ObjectList spaceObjects;
	
	auto ship2 = spaceObjects.addObject(CreateHawkMK1());
	HawkMK1preset1(*ship2, items);
	ship2->setPosition(4, 4, 180);
	
	std::chrono::steady_clock::time_point endCreate = std::chrono::steady_clock::now();
	std::cout << std::endl;	
	std::chrono::steady_clock::time_point startUse = std::chrono::steady_clock::now();	
	
	ship2->powerOn();
	
	spaceObjects.nextStep(5);
	ship2->itemSetMode(modeAverage, 3, 13);
	ship2->moveCommand(moveForward);
	spaceObjects.nextStep(5);
	
	std::chrono::steady_clock::time_point endUse = std::chrono::steady_clock::now();
	
	ship2->Debug_print();
	ship2->showItems();
	
	std::cout	<< std::endl << "Printing took: Create - " 
				<< std::chrono::duration_cast<std::chrono::microseconds>(endCreate - startCreate).count()
				<< "us, Use - "
				<< std::chrono::duration_cast<std::chrono::microseconds>(endUse - startUse).count()
				<< "us." << std::endl; 	
	
	return 0;
};