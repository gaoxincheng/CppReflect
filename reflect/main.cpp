#include "ClassFactory.hpp"
#include <iostream>
#include <typeinfo>

class A
{
public:
	A(){};
	void print()
	{
		std::cout << "this is class A !" << std::endl;
	}
};
Register_Class(A);


int main()
{
	A* a = (A*)ClassFactory::getInstance().getClassObject("A");
	a->print();
	std::cout << typeid(a).name();
	delete a;

	auto c = getchar();
	return 0;
}