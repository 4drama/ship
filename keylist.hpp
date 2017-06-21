#ifndef KeyList__
#define KeyList__

#include <utility>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stack>

//#include <memory>

//#include <iostream>

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
	std::vector<std::pair<int, T*> > valueList;
	
	KeyList(int);
	int add(T*);
	T* find(int);
	void erase(int);
	~KeyList();
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
int ml1::KeyList<T>::add(T* value)
{
//	std::cout << "Debug: KeyList add begin." << std::endl;
	int key = freeKeys.top();
	freeKeys.pop();
	
	std::pair<int, T*> a1(key, std::move(value));
		
	valueList.push_back(std::move(a1));
//	std::cout << "Debug: KeyList add end. key=" << key << " size="<< valueList.size() <<std::endl;
	return key;
};

template <class T>
T* ml1::KeyList<T>::find(int key)
{
//	std::cout << "Debug: KeyList find start." << std::endl;
	auto it = std::find_if (valueList.begin(), valueList.end(), 
		[key](std::pair<int, T*> &i)
		{return i.first == key;} );	
//	std::cout << "Debug: KeyList find end. key=" << key << " size="<< valueList.size() <<std::endl;	
	return it->second;
};

template <class T>
void ml1::KeyList<T>::erase(int key)
{
	auto it = std::find_if (valueList.begin(), valueList.end(), 
		[key](std::pair<int, T*> i)
		{
//			std::cerr << i.first << " " << key << std::endl;
			return i.first == key;
		} );	
	delete it->second;
	valueList.erase(it);
	freeKeys.push(key);
//	std::cout << "Debug: KeyList erase. key=" << key << " size="<< valueList.size() <<std::endl;
};

template <class T>
ml1::KeyList<T>::~KeyList()
{
	for (int i = 0, size = valueList.size(); i<size; ++i)
	{
		delete valueList[i].second;
	}
};
//----------------------------------------------------------
#endif