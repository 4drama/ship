#ifndef OBJECT_LIST__
#define OBJECT_LIST__

#include <vector>
#include <memory>
#include <algorithm>

#include "space_object.hpp"

class ObjectList
{
private:
	std::vector<std::shared_ptr<SpaceObject> > list;
public:

	template <class T>
	std::shared_ptr<T> addObject(T&& obj)
	{
		auto pObj = std::make_shared<T>(std::move(obj));
		list.push_back(pObj);
		return pObj;
	};
	
	void nextStep(int count)
	{
		std::for_each(	list.begin(), list.end(), 		
				[count](std::shared_ptr<SpaceObject> i)
				{
					i->nextStep(count);
				});
	};
	
};

#endif