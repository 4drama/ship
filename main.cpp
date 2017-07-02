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
	Rectangle A(Point{0,0}, Point{0,1}, Point{1,1}, Point{1,0});
	Rectangle B(Point{2,2}, Point{2,0.5}, Point{0,0.5}, Point{0,2});
	Rectangle C(Point{2,2}, Point{2,4}, Point{4,4}, Point{4,2});
	
	bool AB = intersectionRectangle(A, B);	
	bool AC = intersectionRectangle(A, C);	
	
	std::cout << "Collision AB = " << AB << std::endl;
	std::cout << "Collision AC = " << AC << std::endl;
	
	std::chrono::steady_clock::time_point startCreate = std::chrono::steady_clock::now();

	set_update_frequency(5);
	
	ItemList items;		
	ObjectList spaceObjects;
	
	auto ship1 = spaceObjects.addObject(CreateHawkMK1());
	auto ship2 = spaceObjects.addObject(CreateHawkMK1());
	HawkMK1preset1(*ship1, items);
	HawkMK1preset1(*ship2, items);
	ship1->setPosition(0, 4, 180);
	ship2->setPosition(0, 0, 0);
	
	std::chrono::steady_clock::time_point endCreate = std::chrono::steady_clock::now();
	std::cout << std::endl;	
	std::chrono::steady_clock::time_point startUse = std::chrono::steady_clock::now();	
	
	ship1->powerOn();
	ship2->powerOn();
	
	ship1->moveCommand(moveForward);	
	
	ship2->itemSetMode(modeAverage, 3, 13);
	ship2->moveCommand(moveForward);	
	
	int amount = 50;
	
	while(amount--)
	{
		spaceObjects.nextStep();
	}
	
	std::chrono::steady_clock::time_point endUse = std::chrono::steady_clock::now();
	
	ship1->Debug_print();
	std::cout << std::endl;
	ship2->Debug_print();
//	ship2->showItems();
	
	std::cout	<< std::endl << "Printing took: Create - " 
				<< std::chrono::duration_cast<std::chrono::microseconds>(endCreate - startCreate).count()
				<< "us, Use - "
				<< std::chrono::duration_cast<std::chrono::microseconds>(endUse - startUse).count()
				<< "us." << std::endl; 	
	
	return 0;
};