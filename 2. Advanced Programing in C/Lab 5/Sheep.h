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


#ifndef SHEEP_H_
#define SHEEP_H_


class Sheep:public Farm{ //CLASS FOR SHEEP. A SHEEP IS A TYPE OF A FARM ANIMAL

	string name;

public:
	Sheep();
	virtual ~Sheep();
	string getName();

};



#endif /* SHEEP_H_ */
