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

#ifndef MOBILEANIMAL_H_
#define MOBILEANIMAL_H_

class MobileAnimal: public Animal{ //ABSTRACT CLASS FOR MOBILE ANIMALS TYPE. IT IS A TYPE OF ANIMAL

public:
	//ALL FUNCTIONS ARE IMPLEMENTED SPECIFICLY FOR EACH ANIMAL.
	//EACH FUNCTION IS PURE VIRTUAL - WE IMPLEMENT THEM INSIDE THE SPECIFIC ANIMAL CLASS
	virtual void exercise()=0;
	virtual string getName()=0;
	MobileAnimal();
	virtual ~MobileAnimal();
};



#endif /* MOBILEANIMAL_H_ */
