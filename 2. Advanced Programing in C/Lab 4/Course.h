/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */


#ifndef COURSE_H_
#define COURSE_H_

class Student;
#include "Student.h"
#include <iostream>
using namespace std;

class Course {
private:
	friend class Student;
	string name;
	string id;
	Student** students;
	int** student_grades;
	int count;

	Student** isnewlist(int length);
	Student** copylist(Student** newlist,int length=0);
	int** isnewlistgrade(int length);
	int** copylist(int** newlist,int length=0);
	int searchinlist(Student* s1);
public:

	Course();
	Course(Course &cours);
	~Course();
	string getname();
	string getid();
	int getcount();
	Student** getstudents();
	int** getstudentsgrades();
	void set_course_name(string x);
	void set_number_course(string x);
	void set_Student(Student** x, int i);
	void set_grades(int** x);
	void set_studcount(int x);

	Course operator=(Course &course);
	bool operator==(Course &course);
	bool operator>(Course &course);
	friend ostream& operator<<(ostream &output,Course &cours);
	friend istream& operator>>(istream& input,Course& cours);
	bool operator+=(Student &stud);
	bool operator-=(Student &stud);
	Student* operator[](int num);

	void shrinkinglist();
	int getgrade(Student *s0);
};




#endif /* COURSE_H_ */
