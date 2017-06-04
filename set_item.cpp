#include "set_item.hpp"

#include <iostream> 
#include <iterator>

Set_item::Set_item(Ship& Ship_pointer_, Item& Item_pointer_, Turn_item_type Turn_, X_call X_call_, Y_call Y_call_)
				: Ship_pointer(&Ship_pointer_), Item_pointer(&Item_pointer_), Turn(Turn_)
{
//	std::cout << "Debug: Set_item Constructor begin" <<std::endl;
//	std::cout << " Set_item constuctor" <<std::endl;
	
	auto width = Item_pointer_.Get_width();
	auto height = Item_pointer_.Get_height();
	
	
	if (Turn_ == left_turn || Turn_ == right_turn )
	{
		
		
		for(int x=X_call_, xto=X_call_+height; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+width; y<yto; ++y)
			{
				if(!Ship_pointer_.Block_check_struct_item(Item_pointer_, x, y, Turn_))
				{
					std::cerr << "ERROR on set item: check failed" << std::endl;
					return;
				};	
			};						
		};
	
		
		
/*		
		for(int x=X_call_, xto=X_call_+height; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+width; y<yto; ++y)
			{
				Ship_pointer_.setStatus()
				
			//	Ship_pointer_.Block_set_struct_item(*this, x, y);
				Ship_pointer_.Block_set_struct_item(*this, x, y);
				Cells.push_back( std::make_pair (x, y) );
			};						
		};
*/

	}
	else if(Turn_ == up_turn || Turn_ == down_turn)
	{
		
	
		for(int x=X_call_, xto=X_call_+width; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+height; y<yto; ++y)
			{
				if(!Ship_pointer_.Block_check_struct_item(Item_pointer_, x, y, Turn_))
				{
					std::cerr << "ERROR on set item: check failed" << std::endl;
					return;
				};	
			};						
		};
		
		
		
	/*	
		for(int x=X_call_, xto=X_call_+width; x<xto; ++x)
		{
			for(int y=Y_call_, yto=Y_call_+height; y<yto; ++y)
			{
				Ship_pointer_.Block_set_struct_item(*this, x, y);
				Cells.push_back( std::make_pair (x, y) );				
			};						
		};
	*/
		
	};
//	std::cout << " end check" <<std::endl;
	Ship_pointer_.setStatus();
//	std::cout << "Debug: Set_item Constructor end" <<std::endl;
};

Set_item::~Set_item()
{
//	std::cout << "Debug: Set_item Destructor" <<std::endl;
	for ( auto it = Cells.begin(); it!=Cells.end(); it++ )
	{
		//std::cout << it->first << " " << it->second << std::endl;
		Ship_pointer->Block_reser_struct_item(it->second, it->first);
	};
};

void Set_item::addKeyingStruct(int x, int y)
{
//	std::cout << "Debug: Set_item addKeyingStruct." << x << " " << y << std::endl;
	Cells.push_back( std::make_pair (x, y) );
};