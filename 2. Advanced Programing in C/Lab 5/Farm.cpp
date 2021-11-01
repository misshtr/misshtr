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

Farm::Farm(){

}

Farm::~Farm(){

}

void Farm::exercise(){ //PRINTS FARM ANIMAL'S NAME ACCORDING TO ITS TYPE AND THEN ITS EXERCISE METHOD
	cout<<this->getName()<<endl;
	cout<<"Walking slowly in the garden."<<endl;
}



