/* ========================================
 *  Assignment: 5
 * Author: Renan Weiss, ID: 205533508
 * Author: Hadar Rivlin, ID: 207092537
 * ========================================
 */
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include "Menu.h"
#include "Sponge.h"
#include "Coral.h"
#include "Lion.h"
#include "GreatWhiteShark.h"
#include "Wolf.h"
#include "Zebra.h"
#include "Horse.h"
#include "Cow.h"
#include "Sheep.h"
#include "Buffalo.h"
using namespace std;


Menu::Menu(){ //CREATING A NEW ZOO BY ALLOCATING DYNAMIC MEMORY
	this->z = new Zoo;
}
Menu::~Menu(){ //DELETING THE ZOO FROM MEMORY
	delete this->z;
}

void Menu::chooseAnimal(){ //PRINTING THE ANIMAL CHOICES TO ADD TO THE ZOO FOR THE USER
						   //ADDING THE WANTED ANIMAL TO THE ZOO

	int a = 0; //VARIABLE FOR USER CHOICE (1-10)

	//PRINTING ANIMAL OPTIONS
	cout<<"Choose animal:"<<endl;
	cout<<"(1) Sponge"<<endl;
	cout<<"(2) Coral"<<endl;
	cout<<"(3) Lion"<<endl;
	cout<<"(4) Great White Shark"<<endl;
	cout<<"(5) Wolf"<<endl;
	cout<<"(6) Zebra"<<endl;
	cout<<"(7) Horse"<<endl;
	cout<<"(8) Cow"<<endl;
	cout<<"(9) Sheep"<<endl;
	cout<<"(10) Buffalo"<<endl;


	cin>>a; //INPUT FROM USER

	//IF CHOICE ISN'T VALID
	while(a<1 || a>10){
		cout<<"Invalid choice. please enter number within range 1-10:"<<endl;
		cin>>a;
	}

	//CASE FOR EVERY ANIMAL CHOICE:
	//CREATING A MEMORY FOR THE WANTED ANIMAL (POINTER OF TYPE "ANIMAL", POINTS TO A SPECIFIC ANIMAL TYPE (WHICH IS DERIVED FROM ANIMAL CLASS))
	//ADDING IT TO THE ZOO
	switch (a){
	case 1:{
		Animal* s = new Sponge();
		this->z->addAnimal(s);
	}
	break;

	case 2:{
		Animal* c = new Coral();
		this->z->addAnimal(c);
	}
	break;

	case 3:{
		Animal* l = new Lion();
		this->z->addAnimal(l);
	}
	break;

	case 4:{
		Animal* sh = new GreatWhiteShark();
		this->z->addAnimal(sh);
	}
	break;

	case 5:{
		Animal* w = new Wolf();
		this->z->addAnimal(w);
	}
	break;

	case 6:{
		Animal* ze = new Zebra();
		this->z->addAnimal(ze);
	}
	break;

	case 7:{
		Animal* h = new Horse();
		this->z->addAnimal(h);
	}
	break;

	case 8:{
		Animal* co = new Cow();
		this->z->addAnimal(co);
	}
	break;

	case 9:{
		Animal* sp = new Sheep();
		this->z->addAnimal(sp);
	}
	break;

	case 10:{
		Animal* b = new Buffalo();
		this->z->addAnimal(b);
	}
	break;
	};
}



void Menu::mainMenu(){ //ASKING USER TO ADD 5 ANIMALS TO THE ZOO
					   //THEN PRINTS THE MAIN MENU

	//USER IS ASKED FIRST TO ADD 5 ANIMALS. USING THE "CHOOSEANIMAL" FUNCTION ABOVE
	cout<<"Please add 5 animals to the zoo"<<endl;
	for(int i=1; i<=5; i++)
		this->chooseAnimal();

	//PRINTING THE MAIN MENU

	int n=0; //VARIABLE FOR USER'S CHOICE

	//WHILE CHOICE IS NOT "EXIT" - MAIN MENU PRINTED NON-STOP
	while(n!=6){
		cout<<"    M A I N  M E N U"<<endl;
		cout<<"(1) Add An Animal To The Zoo"<<endl;
		cout<<"(2) Feed Zoo Animals"<<endl;
		cout<<"(3) Animals Showtime"<<endl;
		cout<<"(4) Watch Mobile Animals Exercise"<<endl;
		cout<<"(5) Watch Lions Special Stadium Act"<<endl;
		cout<<"(6) Exit"<<endl;

		cin>>n; //USER'S INPUT

		//IF INPUT IS INVALID. PRINTING A MESSAGE AND ASK TO ENTER AGAIN
		while(n<1 || n>6){
			cout<<"Invalid choice. please enter number within range 1-6"<<endl;
			cin>>n;
		}

		//AGAIN - CASE FOR EVERY CHOICE. FOR EACH CHOICE THE ANIMAL IS ADDED TO THE ZOO BY "CHOOSEANIMAL" FUNCTION ABOVE
		switch (n){
		case 1:
			this->chooseAnimal();
			break;
		case 2:
			z->feedZoo();
			break;
		case 3:
			z->showTime();
			break;
		case 4:
			z->exerciseZoo();
			break;
		case 5:
			z->lionShow();
			break;
		case 6:
			cout<<"GOODBYE!"<<endl;
			break;
		}
	}



}


