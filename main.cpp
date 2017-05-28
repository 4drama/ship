#include "collector.hpp"
#include "set_item.hpp"
//#include <utility>
#include <iostream>


int main()
{

//	Ship_struct ddr(empty_block, 0);
	
/*	std::vector<std::vector<int>* > ber;
	ber.push_back(new std::vector<int>);
	ber[0]->push_back(11);
	
	std::vector<std::vector<int> > ber;
	ber.resize(1);
	//ber.push_back(new std::vector<int>);
	ber[0].push_back(11);	
		
	Biba_ship.AddShipStructInLine(0, ddr);*/
	
	
	//std::pair<int,int> a1(10,20);
	
	//std::cout << a1.first;
	/*
	int* A;
	int B;
	
	B = 10;
	A = &B;
	
	std::cout << *A;
	*/
	
	Ship Ship1 = CreateHawkMK1();	
	Item_main_engine Bib(1000, 3, 9);
	{
	Set_item A1 = Set_item(Ship1, Bib, down_turn, 0, 13);
	
	std::cout << std::endl;
	
	Ship1.Debug_print();
	
	
	}
	Ship1.Debug_print();
	
	return 0;
};