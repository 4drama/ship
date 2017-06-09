#include "item_list.hpp"

#include <iterator>
#include <algorithm>

ItemList::ItemList()
{
	list.push_back(std::make_pair(1150, new Item_main_engine("Engine Azrt 1577" ,1250, 3, 9, 900, 400, 4, 1900, 900, 100, 15, 8, 70, 20)));
	list.push_back(std::make_pair(1450, new Item_help_engine("Move Engine HG12" ,250, 2, 2, 400, 500, 200, 0, 0, 30, 8)));
	list.push_back(std::make_pair(1750, new Item_cabina("Cabina Azrt 2577" ,200, 2, 3, 200, 10, 0)));
	list.push_back(std::make_pair(2050, new Item_gate("pb G12" ,150, 2, 1, 350, 4)));
	list.push_back(std::make_pair(2350, new Item_cargo_cell("Cargo Azrt 413" ,150, 2, 3, 300, 2, 3)));
	list.push_back(std::make_pair(2650, new Item_power_generator("tdGENERATOR1000" ,450, 2, 2, 250, 250, 3, -90, 16)));
	list.push_back(std::make_pair(2950, new Item_energy_shield("Shield Azrt 3577" ,350, 2, 2, 300, 150, 2, 10, 6, 150, 60, 500, 25)));
	list.push_back(std::make_pair(3250, new Item_active_cooling("tdCOOLING1010" ,200, 2, 2, 450, 30, -120, 200, -360)));
	list.push_back(std::make_pair(3550, new Item_energy_storage("tdACCUMULATOR1052", 50, 1, 2, 150, 100, 1, 180)));
	list.push_back(std::make_pair(3551, new Item_energy_storage("tdACCUMULATOR1053", 100, 1, 3, 200, 150, 1, 300)));
	list.push_back(std::make_pair(3851, new Item_ballistic_weapon("Energy boll HG12 gun 1B", 550, 2, 6, 700, 250, 4, 180, 160, 120, 2, 1800)));
	
};
	
Item* ItemList::operator()(int id)
{
		auto it = std::find_if (list.begin(), list.end(), 
		[id](std::pair<int, Item*> &i)
		{return i.first == id;} );	
	return it->second;
};	
	
ItemList::~ItemList()
{
	for (int i = 0, size = list.size(); i<size; ++i)
	{
		delete list[i].second;
	}
};	