/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "VeganAnimal.h"
using namespace std;


VeganAnimal::VeganAnimal(){


}

VeganAnimal::~VeganAnimal(){


}


void VeganAnimal::eat(){ //PRINTS VEGAN ANIMAL NAME AND THEN THEIR EATING METHOD

	cout<<this->getName()<<endl;
	cout<<"Eating grass."<<endl;
}

void VeganAnimal::show(){ //PRINTS VEGAN ANIMAL NAME AND THEN ITS SHOW METHOD

	cout<<this->getName()<<endl;
	cout<<"Bored staring at the guests."<<endl;
}

