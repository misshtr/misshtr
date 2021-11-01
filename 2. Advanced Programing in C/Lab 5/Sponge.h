/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "StaticAnimal.h"
using namespace std;

#ifndef SPONGE_H_
#define SPONGE_H_

class Sponge: public StaticAnimal{ //CLASS FOR SPONGE OBJECT. SPONGE IS A STATIC ANIMAL
								   //EVERY SPONGE HAS A NAME. A SPONGE EATS DIFFERENTLY FROM THE OTHER ANIMALS

 string name;

public:
	Sponge();
	virtual ~Sponge();
	string getName();
	void eat();

};



#endif /* SPONGE_H_ */
