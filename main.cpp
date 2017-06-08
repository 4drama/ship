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
	
//	Ship1.removeItem(8, 8);		
	Ship1.powerOn();
	Ship1.Debug_print();


	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "\nPrinting took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us.\n\n";  
	
	return 0;
};