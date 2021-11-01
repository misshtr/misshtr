/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Animal.h"
using namespace std;

#ifndef STATICANIMAL_H_
#define STATICANIMAL_H_

class StaticAnimal: public Animal{ //THIS IS AN ABSTARCT CLASS FOR STATIC ANIMALS TYPE. IT IS A TYPE OF ANIMAL

public:
	//EVERY STATIC ANIMAL HAS THE SAME "SHOW" FUNCTION.
	//ALL THE OTHER FUNCTIONS ARE VIRTUAL, AND IMPLEMENTED ACCORDING TO THE ANIMAL TYPE (SPONGE \ CORAL)
	//ABSTARCT CLASS - WE USE THE DEFAULT CONSTRUCTOR
	StaticAnimal();
	virtual ~StaticAnimal();
	virtual void eat()=0;
	virtual string getName()=0;
	void show();

};



#endif /* STATICANIMAL_H_ */
