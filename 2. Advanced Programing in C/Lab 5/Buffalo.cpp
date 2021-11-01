/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Buffalo.h"
using namespace std;


Buffalo::Buffalo(){ //SETS BUFFALO NAME
	this->name = "Buffalo";
}

Buffalo:: ~Buffalo(){

}

string Buffalo::getName(){ //RETURNS BUFFALO NAME
	return this->name;
}
