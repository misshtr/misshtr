/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Cow.h"
using namespace std;


Cow::Cow(){ //SETS COW NAME
	this->name = "Cow";
}

Cow:: ~Cow(){

}

string Cow::getName(){ //RETURNS COW NAME
	return this->name;
}
