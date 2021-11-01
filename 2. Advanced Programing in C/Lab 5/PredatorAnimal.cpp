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

PredatorAnimal::PredatorAnimal(){

}

PredatorAnimal::~PredatorAnimal(){

}

void PredatorAnimal::exercise(){ //PRINTS ANIMAL'S NAME ACCORDING TO ITS TYPE, AND THEN THEIR EXERCISE METHOD

	cout<<this->getName()<<endl;
	cout<<"Running after potential food."<<endl;
}

void PredatorAnimal::eat(){ //PRINTS ANIMAL'S NAME ACCORDING TO ITS TYPE, AND THEN THEIR EATING METHOD ACCORDING TO ITS FOOD

	cout<<this->getName()<<endl;
	cout<<"Preying! Eating " <<this->getFood()<<"! Yummy!"<<endl;
}








