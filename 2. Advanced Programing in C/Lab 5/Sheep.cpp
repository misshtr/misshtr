/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Sheep.h"
using namespace std;


Sheep::Sheep(){ //SETS SHEEP NAME
	this->name = "Sheep";
}

Sheep:: ~Sheep(){

}

string Sheep::getName(){ //RETURNS SHEEP NAME
	return this->name;
}
