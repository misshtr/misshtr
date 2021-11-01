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


#ifndef MENU_H_
#define MENU_H_

class Menu{ //MENU CLASS
			//MENU CREATS A NEW ZOO
	Zoo* z;
public:
	Menu();
	~Menu();
	void mainMenu();
	void chooseAnimal();
};



#endif /* MENU_H_ */
