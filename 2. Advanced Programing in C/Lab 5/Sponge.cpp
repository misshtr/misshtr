/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Sponge.h"
using namespace std;


Sponge::Sponge(){ //CONSTRUCTOR - SETTING SPONGE NAME - "SPONGE"
	this->name = "Sponge";
}

Sponge::~Sponge(){

}

void Sponge::eat(){ //FUNCTION PRINTS THE EATING METHOD OF THE SPONGE
	cout<<this->name<<endl<<"Filtering water flow to obtain food."<<endl;
}

string Sponge::getName(){ //FUNCTION RETURNS SPONGE NAME
	return this->name;
}



