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


#ifndef BUFFALO_H_
#define BUFFALO_H_


class Buffalo:public Farm{ //CLASS FOR BUFFALO. THIS IS A TYPE OF A FARM ANIMAL

	string name;

public:
	Buffalo();
	virtual ~Buffalo();
	string getName();

};



#endif /* BUFFALO_H_ */
