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
#include "MobileAnimal.h"
#include "Lion.h"
using namespace std;

#ifndef ZOO_H_
#define ZOO_H_

class Zoo{ //ZOO CLASS
	       //EVERY ZOO HAS A LIST OF ALL THE ANIMALS, LIST OF THE MOBILE ANIMALS, AND LIST FOR THE LIONS
		   //THERE IS A COUNTER FOR EACH LIST

	Animal** animals;
	MobileAnimal** mobileanimals;
	Lion** lions;
	int animalslen;
	int mobileanimalslen;
	int lionslen;

public:
	Zoo();
	~Zoo();
	void addAnimal(Animal* animal);
	void feedZoo();
	void showTime();
	void exerciseZoo();
	void lionShow();





};




#endif /* ZOO_H_ */
