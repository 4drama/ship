#ifndef ITEM_LIST__
#define ITEM_LIST__

#include "item.hpp"

#include <vector>
#include <utility>


class ItemList
{
private:	
	std::vector<std::pair<int, Item*>> list;
	
public:	
	ItemList();
	Item* operator()(int);
	~ItemList();	
};


#endif