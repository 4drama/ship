#include "item_list.hpp"

#include <iterator>
#include <algorithm>


ItemList::ItemList()
{
	list.push_back(std::make_pair(1001, new Item_main_engine("Engine Azrt 1577" ,1250, 3, 9, 900, 400, 4, 1900, 900, 100, 15, 8, 70, 20)));
	list.push_back(std::make_pair(1101, new Item_help_engine("Move Engine HG12" ,250, 2, 2, 400, 70, 2, 500, 200, 0, 0, 30, 8)));
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