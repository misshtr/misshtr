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

#ifndef EQUIDAE_H_
#define EQUIDAE_H_

class Equidae:public VeganAnimal{ //ABSTRACT CLASS FOR EQUIDAE. THIS IS A TYPE OF A VEGAN ANIMAL
								  //EVERY EQUIDAE ANIMAL HAS THE SAME EXERCISE METHOD WICH IS IMPLEMENTED HERE

	string name;

public:
	Equidae();
	virtual ~Equidae();
	virtual string getName()=0;
	void exercise();

};



#endif /* EQUIDAE_H_ */
