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

#ifndef ZEBRA_H_
#define ZEBRA_H_

class Zebra:public Equidae{ //HORSE CLASS. THIS IS A TYPE OF AN EQUIDAE ANIMAL.

	string name;

public:
	Zebra();
	virtual ~Zebra();
	string getName();

};



#endif /* ZEBRA_H_ */
