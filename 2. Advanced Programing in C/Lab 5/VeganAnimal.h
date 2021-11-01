/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "MobileAnimal.h"
using namespace std;

#ifndef VEGANANIMAL_H_
#define VEGANANIMAL_H_

class VeganAnimal:public MobileAnimal{ //ABSTRACT VEGAN ANIMAL CLASS, THIS CLASS IS A TYPE OF A MOBILE ANIMAL
									   //EVERY VEGAN ANIMAL EATS AND SHOWS THE SAME WAY. THUS THESE FUNCTIONS ARE IMPLEMENTED HERE

public:
	VeganAnimal();
	virtual ~VeganAnimal();
	void eat();
	void show();
	virtual string getName()=0;
};




#endif /* VEGANANIMAL_H_ */
