/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Zoo.h"
using namespace std;

Zoo::Zoo(){ //C'TOR CREATING LISTS OF POINTERS FOR ALL ANIMALS, MOBILE ANIMALS AND LIONS, WITH COUNTERS FOR EACH ONE

	this->animals = new Animal*[200];
	this->mobileanimals = new MobileAnimal*[100];
	this->lions = new Lion*[100];
	this->animalslen = 0;
	this->mobileanimalslen = 0;
	this->lionslen = 0;
}
Zoo::~Zoo(){ //D'TOR DELETING THE ANIMAL LISTS AND ITS CONTENT. AND ALL THE LISTS ALLOCATED MEMORY

	for( int i=0; i<this->animalslen; i++)
		delete animals[i];
	delete[] animals;
	delete[] mobileanimals;
	delete[] lions;


}
void Zoo::addAnimal(Animal* animal){ //GETS - POINTER TO AN ANIMAL (WHICH COULD BE EVERY ANIMAL THE ZOO CAN GET)
								     // ADDING THE GIVEN ANIMAL TO THE LISTS ACCORDING TO ITS TYPE (USING DYNAMIC CASTING).

	//FIRST - ADDING THE ANIMAL TO THE MAIN ANIMALS LIST (AND UPDATING LIST COUNTER)
	this->animals[this->animalslen] = animal;
	++this->animalslen;

	//CHECKING IF THE ANIMAL IS A LION
	if(Lion* lion = dynamic_cast<Lion*>(animal))
	{
		//ADDING ANIMAL TO THE LIONS LIST (UPDATING COUNTER)
		this->lions[this->lionslen] = lion;
		++this->lionslen;

		//ADDING ANIMAL TO THE MOBILE LIST (UPDATING COUNTER)
		this->mobileanimals[this->mobileanimalslen] = dynamic_cast<MobileAnimal*>(animal);
		++this->mobileanimalslen;
		return;
	}

	//IF THE ANIMAL IS JUST A MOBILE ANIMAL - ADDING IT TO MOBILE LIST (UPDATING COUNTER)
	if(MobileAnimal* mobile = dynamic_cast<MobileAnimal*>(animal)){
		this->mobileanimals[this->mobileanimalslen] = mobile;
		++this->mobileanimalslen;
	}

}

void Zoo::feedZoo(){ //FEEDING THE ZOO. EACH ANIMAL EATS ACCORDING TO ITS TYPE

	//ITIRATING OVER THE ZOO ANIMAL'S LIST AND EXECUTING EACH ANIMAL'S EATING METHOD
	for( int i=0 ; i<this->animalslen; i++){
		this->animals[i]->eat();
	}
}

void Zoo::showTime(){ //LUNCHING THE SHOW OF THE ZOO. EACH ANIMAL PERFORMS ACCORDING TO ITS TYPE

	//ITIRATING OVER THE ZOO ANIMAL'S LIST AND EXECUTING EACH ANIMAL'S SHOW METHOD
	for(int i=0; i<this->animalslen; i++){
		this->animals[i]->show();
	}
}

void Zoo::exerciseZoo(){ //TAKING ANIMALS TO EXERCISE. ONLY THE MOBILE ONES CAN!

	//IF THERE ARE NO MOBILE ANIMALS - PRINTING A MESSAGE
	if(this->lionslen==0)
		cout<<"No Mobile Animals in the Zoo."<<endl;

	//ITIRATING OVER THE MOBILE ANIMALS LIST AND EXECUTING EACH ONE'S EXERCISE METHOD
	for( int i=0; i<this->mobileanimalslen; i++){
		this->mobileanimals[i]->exercise();
	}
}

void Zoo::lionShow(){ //LUNCHING LIONS "ROYAL SHOW"

	//IF LIONS LIST IS EMPTY - A MESSAGE IS PRINTED
	if(this->lionslen==0)
		cout<<"No Lions in the Zoo."<<endl;

	//ITIRATING OVER LIONS LIST AND EXECUTING THEIR ROYAL HUNTING SHOW
	for(int i=0; i<this->lionslen; i++){
		this->lions[i]->hunting();
	}
}


