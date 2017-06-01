#ifndef KeyList__
#define KeyList__

#include <utility>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stack>

#include <iostream>

namespace ml1
{
//==========================================================
//=====================DECLARATION==========================	
template <class T> 
class KeyList
{	
private:			
	std::stack<int> freeKeys;	
public:
	std::vector<std::pair<int, T> > valueList;
	
	KeyList(int);
	int add(T&&);
	T& find(int);
	void erase(int);
};
//----------------------------------------------------------
};

	


//==========================================================	
//=====================IMPLEMENTATION=======================
template <class T>
ml1::KeyList<T>::KeyList(int keys)
{
	for (int i = 1; i < keys ; ++i)
	{
		freeKeys.push(i);
	}
};

template <class T>
int ml1::KeyList<T>::add(T&& value)
{
	std::cout << "Debug: KeyList add begin." << std::endl;
	int key = freeKeys.top();
	freeKeys.pop();
	
	std::pair<int, T> a1(key, std::move(value));
		
	valueList.push_back(std::move(a1));
	std::cout << "Debug: KeyList add end. key=" << key << " size="<< valueList.size() <<std::endl;
	return key;
};

template <class T>
T& ml1::KeyList<T>::find(int key)
{
	auto it = std::find_if (valueList.begin(), valueList.end(), 
		[key](std::pair<int, T> i)
		{return i.first == key;} );	
	std::cout << "Debug: KeyList find. key=" << key << " size="<< valueList.size() <<std::endl;	
	return it->second;
};

template <class T>
void ml1::KeyList<T>::erase(int key)
{
	auto it = std::find_if (valueList.begin(), valueList.end(), 
		[key](std::pair<int, T> i)
		{return i.first == key;} );
	valueList.erase(it);
	freeKeys.push(key);
	std::cout << "Debug: KeyList erase. key=" << key << " size="<< valueList.size() <<std::endl;
};
//----------------------------------------------------------
#endif