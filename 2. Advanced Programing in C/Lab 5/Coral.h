/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "StaticAnimal.h"
using namespace std;


#ifndef CORAL_H_
#define CORAL_H_


 class Coral: public StaticAnimal{ //CLASS FOR CORAL OBJECT. CORAL IS A STATIC ANIMAL
								   //EVERY CORAL HAS A NAME AND ITS OWN EATING METHOD
 string name;


public:
	Coral();
	virtual ~Coral();
	string getName();
	void eat();

};




#endif /* CORAL_H_ */
