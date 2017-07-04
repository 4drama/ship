#ifndef OBJECT_LIST__
#define OBJECT_LIST__

#include <vector>
#include <memory>

#include "space_object.hpp"

class ObjectList
{
private:
	std::vector<std::shared_ptr<SpaceObject> > list;
	
	void attributesReckon();
	void coordinateReckon();
//	void collisionReckon();
	
public:

	template <class T>
	std::shared_ptr<T> addObject(T&& obj);
	
	void nextStep();	
	
};

template <class T>
std::shared_ptr<T> ObjectList::addObject(T&& obj)
{
	auto pObj = std::make_shared<T>(std::move(obj));
	list.push_back(pObj);
	return pObj;
};

#endif