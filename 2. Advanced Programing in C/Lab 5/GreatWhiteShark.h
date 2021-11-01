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


#ifndef GREATWHITESHARK_H_
#define GREATWHITESHARK_H_

class GreatWhiteShark: public PredatorAnimal{//SHARK CLASS. SHARK IS A TYPE OF A PREDATOR. EVERY SHARK HAS ITS NAME AND EATS A SPECIFIC FOOD
	string name;
	string food;



public:
	GreatWhiteShark();
	virtual ~GreatWhiteShark();
	virtual string getName();
	virtual string getFood();
	void show();

};



#endif /* GREATWHITESHARK_H_ */
