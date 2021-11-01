/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Lion.h"
using namespace std;

Lion::Lion(){ //SETS LION NAME AND FOOD
	this->name = "Lion";
	this->food = "Gnu";

}
Lion::~Lion(){

}

void Lion::show(){ //PRINTS LION'S NAME AND ROYAL SHOW IN THE ZOO
	cout<<this->name<<endl<<"Royal walking in the garden."<<endl;
}

void Lion::hunting(){//PRINTS LIONS NAME AND ITS HUNTING SHOW

	cout<<this->name<<endl<<"Hunting!"<<endl;
}

string Lion::getName(){ //RETURNS LION'S NAME
	return this->name;
}
string Lion::getFood(){//RETURNS LION'S FOOD
	return this->food;
}

