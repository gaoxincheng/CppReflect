#ifndef _CLASS_FACTORY_H
#define _CLASS_FACTORY_H
#include <map>
#include <string.h>
#include <iostream>
#include <functional>
#include "common.hpp"

//typedef void* (*CreateClassObject)(void);
typedef std::function<void*(void)>  CreateClassObject;

class ClassFactory
{
private:
	ClassFactory(){};
public:
	static ClassFactory & getInstance()
	{
		static ClassFactory _intance;
		return _intance;
	}
	void *getClassObject(std::string className)
	{
		auto it = _class_map.find(className);
		if (it != _class_map.end())
			return it->second();
		return nullptr;
	}

	void register_class(std::string className, CreateClassObject createFunc)
	{
		auto it = _class_map.find(className);
		if (it != _class_map.end())
			return;
		_class_map.insert(std::make_pair(className,createFunc));
	}

private:
	std::map<std::string, CreateClassObject> _class_map;
};

class MakeRegister
{
private:
	MakeRegister(){};
public:
	MakeRegister(std::string className, CreateClassObject createFunc)
	{
		ClassFactory::getInstance().register_class(className, createFunc);
	}
};

#endif // !_CLASS_FACTORY_H
