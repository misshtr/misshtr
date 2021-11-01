/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Equidae.h"
using namespace std;

Equidae::Equidae(){

}

Equidae::~Equidae(){

}

void Equidae::exercise(){ //PRINTS ANIMAL'S NAME ACCORDING TO ITS TYPE AND THEN ITS EXERCISE METHOD
	cout<<this->getName()<<endl;
	cout<<"Running fast in circles."<<endl;
}




