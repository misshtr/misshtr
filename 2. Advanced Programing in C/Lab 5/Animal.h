/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal{ //ABSTRACT CLASS FOR ANIMAL TYPE OBJECT

public:
	//EACH ANIMAL HAS ITS OWN NAME, SPECIFIC EATING, AND A SPECIFIC SHOW.
	//EACH OF THESE FUNCTIONS IS IMPLEMENTED IN THE SPECIFIC ANIMAL CLASS.
	//THIS CLASS IS ABSTRACT - WE USE THE DEFAULT CONSTRUCTOR!
	Animal();
	virtual ~Animal();
	virtual string getName()=0;
	virtual void eat()=0;
	virtual void show()=0;



};



#endif /* ANIMAL_H_ */
