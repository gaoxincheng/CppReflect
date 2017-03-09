#ifndef _COMMON_H
#define _COMMON_H
#include "ClassFactory.hpp"

#define  Register_Class(className) \
	className*	CreateClass##className() \
						{						 \
							return new className;	 \
						}		\
		 MakeRegister rigClass(#className,(CreateClassObject)CreateClass##className);	


#endif // _COMMON_H
