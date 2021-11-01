/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "VeganAnimal.h"
using namespace std;

#ifndef FARM_H_
#define FARM_H_

class Farm:public VeganAnimal{ //CLASS FOR FARM ANIMALS. THIS IS A TYPE OF A VEGAN ANIMAL
							   //EVERY FARM ANIMAL HAS THE SAME EXERCISE METHOD - WICH IS IMPLEMENTED HERE

public:
	Farm();
	virtual ~Farm();
	void exercise();
	virtual string getName()=0;
};



#endif /* FARM_H_ */
