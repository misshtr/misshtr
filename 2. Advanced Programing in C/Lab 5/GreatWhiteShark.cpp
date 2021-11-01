/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "GreatWhiteShark.h"
using namespace std;


GreatWhiteShark::GreatWhiteShark(){//SETS SHARK NAME AND FOOD
	this->name = "GreatWhiteShark";
	this->food = "Fish";
}

GreatWhiteShark::~GreatWhiteShark(){

}

void GreatWhiteShark::show(){ //PRINTS SHARK NAME AND ITS SHOW IN THE ZOO
	cout<<this->name<<endl<<"Water diving."<<endl;
}

string GreatWhiteShark::getName(){ //RETURNS SHARK'S NAME
	return this->name;
}
string GreatWhiteShark::getFood(){//RETURNS LION'S FOOD
	return this->food;
}
