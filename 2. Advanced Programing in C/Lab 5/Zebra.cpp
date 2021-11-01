/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Zebra.h"
using namespace std;

Zebra::Zebra(){ //SETS HORSE NAME
	this->name = "Zebra";
}

Zebra:: ~Zebra(){

}

string Zebra::getName(){ //RETURNS HORSE NAME
	return this->name;
}
