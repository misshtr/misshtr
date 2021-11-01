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

#ifndef WOLF_H_
#define WOLF_H_

class Wolf: public PredatorAnimal{ //LION CLASS. WOLF IS A TYPE OF A PREDATOR. EVERY WOLF HAS ITS NAME AND EATS A SPECIFIC FOOD
	string name;
	string food;



public:
	Wolf();
	virtual ~Wolf();
	virtual string getName();
	virtual string getFood();
	void show();
};






#endif /* WOLF_H_ */
