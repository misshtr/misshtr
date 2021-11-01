/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "PredatorAnimal.h"
using namespace std;

#ifndef LION_H_
#define LION_H_

class Lion: public PredatorAnimal{ //LION CLASS. LION IS A TYPE OF A PREDATOR. EVERY LION HAS ITS NAME AND EATS A SPECIFIC FOOD
	string name;
	string food;

public:
		Lion();
		virtual ~Lion();
		virtual string getName();
		virtual string getFood();
		void show();
		void hunting();

};



#endif /* LION_H_ */
