/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#ifndef ACADEMICINSTITUTE_H_
#define ACADEMICINSTITUTE_H_

class Student;
class Course;
class Department;
#include "Student.h"
#include "Course.h"
#include "Department.h"
#include <iostream>
using namespace std;

class AcademicInstitute {
private:
	string name;
	Department** departments;
	int depcount;
	Student** students;
	int stcount;
	Student** notintact;
	int notincount;

public:
	AcademicInstitute();
	AcademicInstitute(string name); //constructor
	~AcademicInstitute(); //destructor
	string getname();
	int getdepcount();
	int getstcount();
	int getnotincount();
	void menu();
	bool adddepartment();
	bool addCourseToDepartment();
	bool addStudentToDepartment();
	bool registerStudentToCourse();
	void gradingStudentsInCourse();
	bool isbad(Student &s1);
	void printCourseInformation();
	void printStudentInformation();
	void printDepartmentInformation();
	bool removeStudentFromCourse();
	bool exit();

};



#endif /* ACADEMICINSTITUTE_H_ */
