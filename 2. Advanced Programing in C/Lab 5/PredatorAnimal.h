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

#ifndef PREDATORANIMAL_H_
#define PREDATORANIMAL_H_

class PredatorAnimal :public MobileAnimal {//CLASS FOR PREDATOR ANIMALS. TYPE OF A MOBILE ANIMAL

public:
	//ABSTRACT CLASS FOR PREDATOR ANIMALS TYPE.
	//EVERY PREDATOR EATS AND EXERCISE THE SAME WAY! - THUS FUNCTIONS ARE IMPLEMENTED HERE
	//EVERY PREDATOR SHOWS DIFFERETNLY. "SHOW" FUNCTION IS IMPLEMENTED IN EVERY PREDATOR SPECIFCALY
	PredatorAnimal ();
	virtual ~PredatorAnimal();
	void exercise();
	void eat();
	virtual string getName()=0;
	virtual string getFood()=0;


};



#endif /* PREDATORANIMAL_H_ */
