/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#ifndef STUDENT_H_
#define STUDENT_H_

class Course;
#include "Course.h"
#include <iostream>
using namespace std;
//#include <string>


class Student {
private:
	friend class Course;
	string name;
	int id;
	char sex;
	int count;
	double ave;
	Course** course;
	Course** isnewlist(int length);
	Course** copylist(Course** newlist, int length);
	int searchinlist(Course &c1);

public:

	Student();
	Student(Student &stud); //constructor

	~Student(); //destructor

	string getname(); //returns the name

	int getid(); //returns the id
	double getave();
	char getsex(); //returns the sex

	int getcount(); //returns courses count

	Course** getcourse();

	void set_stud_name(string x);
	void set_id(int x);
	void set_course(Course** x,int i);
	void set_sex(char x);
	void set_count(int x);


	Student operator=(Student &stud);

	bool operator==( Student &stud);

	bool operator>(Student &stud);



	friend ostream& operator<<(ostream &output,Student &s1);

	friend istream& operator>>(istream& input,Student& s1);

	bool operator+=(Course &cours);

	bool operator-=(Course &cours);

	Course operator[](int num);



	void shrinkinglist();

};



#endif /* STUDENT_H_ */
