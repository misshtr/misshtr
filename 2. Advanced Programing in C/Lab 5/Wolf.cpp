/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Wolf.h"
using namespace std;



Wolf::Wolf(){ //SETS WOLF'S NAME AND FOOD
	this->name = "Wolf";
	this->food = "Rabbit";
}

Wolf::~Wolf(){

}

void Wolf::show(){ //PRINTS WOLF NAME AND ITS SHOW
	cout<<this->name<<endl<<"Joyful Running and flapping their tail."<<endl;
}

string Wolf::getName(){ //RETURNS WOLFS NAME
	return this->name;
}

string Wolf::getFood(){ //RETURNS WOLF FOOD
	return this->food;
}
