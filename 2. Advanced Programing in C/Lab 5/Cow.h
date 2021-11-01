/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Farm.h"
using namespace std;


#ifndef COW_H_
#define COW_H_

class Cow:public Farm{ //COW CLASS. THIS ANIMAL IS A TYPE OF A FARM ANIMAL

	string name;

public:
	Cow();
	virtual ~Cow();
	string getName();
};




#endif /* COW_H_ */
