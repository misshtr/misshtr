/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Equidae.h"
using namespace std;

#ifndef HORSE_H_
#define HORSE_H_

class Horse:public Equidae{ //HORSE CLASS. THIS IS A TYPE OF AN EQUIDAE ANIMAL.

	string name;

public:
	Horse();
	virtual ~Horse();
	string getName();

};



#endif /* HORSE_H_ */
