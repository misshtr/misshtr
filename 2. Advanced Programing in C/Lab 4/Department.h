/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

class Course;
class Student;
#include "Course.h"
#include "Student.h"
#include <iostream>
using namespace std;


class Department{
private:
	friend class Course;
	friend class Student;
	string name;
	string id;
	Course** course;
	Student** student;
	Student** bad_students;
	int cours_count;
	int stud_count;
	int bad_stud_count;

	Student** isnewslist(int length);
	Course** isnewclist(int length);
	Course** copylist(Course** newlist,int length);
	Student** copylist(Student** newlist,int length);
	int searchinlist(Student &s1);
	int searchinlist(Course &c1);
	//Student** isnewbslist(int length);
public:
	Department();
	Department(Department &d);
	~Department();
	string getname();
	string getid();
	void set_dep_name(string x);
	void set_id(string x);
	int getcourscount();
	int getstudcount();
	int getbadstudcount();
	Course** getcourse();
	Student** getstudent();
	Department& operator=(Department &dep);
	bool operator>(Department &dep);
	friend ostream& operator<<(ostream &output,Department &dep1);
	friend istream& operator>>(istream& input, Department& dep1);
	bool operator+=(Course &cours);
	bool operator+=(Student &stud);
	bool addbadstu(Student &stud);
	int isacademicvalid();
};


#endif /* DEPARTMENT_H_ */
