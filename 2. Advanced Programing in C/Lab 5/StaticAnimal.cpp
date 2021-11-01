/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "StaticAnimal.h"
using namespace std;


StaticAnimal::StaticAnimal(){

}

StaticAnimal::~StaticAnimal(){

}

void StaticAnimal::show(){ //FUNCTION ACTS THE SAME FOR THE STATIC ANIMALS. PRINTS ANIMAL'S NAME AND MAKES THEM "SHOW"

	cout<<this->getName()<<endl;
	cout<<"Beautiful & colorful views!"<<endl;
}







