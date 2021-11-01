/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Horse.h"
using namespace std;


Horse::Horse(){ //SETS HORSE NAME
	this->name = "Horse";
}

Horse:: ~Horse(){

}
string Horse::getName(){ //RETURNS HORSE NAME
	return this->name;
}

