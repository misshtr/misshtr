/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Coral.h"
using namespace std;


Coral::Coral(){ //CONSTRUCTOR - SET CORAL NAME - "CORAL"
	this->name = "Coral";
}
Coral::~Coral(){

}

void Coral::eat(){ //PRINTS THE CORAL'S NAME AND ITS SPECIFIC EATING METHOD
	cout<<this->name<<endl<<"Feeding on a variety of small sea-organisms."<<endl;
}

string Coral::getName(){ //FUNCTION RETURNS CORAL'S NAME
	return this->name;
}
