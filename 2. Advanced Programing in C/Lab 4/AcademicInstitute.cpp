/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#include "AcademicInstitute.h"
#include <iostream>
using namespace std;

AcademicInstitute::AcademicInstitute(){
	this->name = "";
	this->departments = NULL;
	this->depcount=0;
	this->notincount = 0;
	this->notintact = NULL;
	this->stcount = 0;
	this->students = NULL;
}
AcademicInstitute::AcademicInstitute(string name){//constructor
	this->name = name;
	this->departments = NULL;
	this->depcount=0;
	this->notincount = 0;
	this->notintact = NULL;
	this->stcount = 0;
	this->students = NULL;
}
AcademicInstitute::~AcademicInstitute(){ //destructor
	delete[] this->departments;
	delete[] this->notintact;
	delete[] this->students;
}
string AcademicInstitute::getname(){
	return this->name;
}
int AcademicInstitute::getdepcount(){
	return this->depcount;
}
int AcademicInstitute::getstcount(){
	return this->stcount;
}
int AcademicInstitute::getnotincount(){
	return this->notincount;
}

void AcademicInstitute::menu(){
	while(1)
	{
		cout<<"Please choose the option you want to do by number"<<endl;
		cout<<"1. Add department"<<endl<<"2. Add course to department"<<endl;
		cout<<"3. Add student to department"<<endl<<"4. Register student to course"<<endl;
		cout<<"5. Grading students in course"<<endl<<"6. Print course information"<<endl;
		cout<<"7. Print student information"<<endl<<"8. Print department information"<<endl;
		cout<<"9. Remove student from course"<<endl<<"10. Exit"<<endl;
		int i;
		cin>>i;
		switch(i){
		case 1 :
			if(adddepartment())
				cout<<"The department was added successfully"<<endl;
			else cout<<"There is a problem adding department please try later"<<endl;
			break;
		case 2:
			if(addCourseToDepartment())
				cout<<"The Course was added successfully to the Department"<<endl;
			else cout<<"There is a problem adding the course to the department please try later"<<endl;
			break;
		case 3:
			if(addStudentToDepartment())
				cout<<"The student was added successfully to the Department"<<endl;
			else cout<<"There is a problem adding the course to the department please try later"<<endl;
			break;
		case 4:
			if(registerStudentToCourse())
				cout<<"The student was registered successfully to the course"<<endl;
			break;
		case 5:
			gradingStudentsInCourse();
			break;
		case 6:
			printCourseInformation();
			break;
		case 7:
			printStudentInformation();
			break;
		case 8:
			printDepartmentInformation();
			break;
		case 9:
			if (removeStudentFromCourse())
				cout<<"the student was successfully removed from course"<<endl;
			break;
		case 10:
			exit();
			break;
		default:
			cout<<"Error: invalid input, please choose an option from the manu"<<endl;
			break;
		}
	}
}
bool AcademicInstitute::adddepartment(){
	if(depcount == 0){
		Department** dep = new Department*[1];

		cout<<"Please enter the name of the department"<<endl;
		string name;
		cin >> name;
		cout<<"Please enter the id of the department"<<endl;
		string id;
		cin >> id;
		Department d;
		d.set_dep_name(name);
		d.set_id(id);
		*(dep) = &d;
		departments = dep;
		//*(departments) = &d;
		depcount++;
		return true;
	}
	Department** p= this->departments;
	if (*(p+depcount+1)==NULL)
	{
		cout<<"Please enter the name of the department"<<endl;
		string name;
		cin >> name;
		cout<<"Please enter the id of the department"<<endl;
		string id;
		cin >> id;
		Department d;
		d.set_dep_name(name);
		d.set_id(id);
		*(p+depcount+1)=&d;
		depcount++;
		return true;
	}
	else{
		Department** newlist= new Department*[2*depcount];
		p= this->departments;
		if (newlist != NULL)
		{
			Department** q= newlist;
			for (int i=0; i<depcount;i++)
			{
				*(q+i) = *(p+i);
			}
			q = newlist+depcount;
			for (int i=0; i<depcount;i++)
				*(q+i) = NULL;
			delete[] departments;
			departments = newlist;
			cout<<"Please enter the name of the department"<<endl;
			string name;
			cin >> name;
			cout<<"Please enter the id of the department"<<endl;
			string id;
			cin >> id;
			Department d;
			d.set_dep_name(name);
			d.set_id(id);
			*(newlist+depcount+1)= &d;
			depcount++;
			return true;
		}
		cout<<"ERROR: no memory";
		return false;
	}
	return false;
}
bool AcademicInstitute::addCourseToDepartment(){
	Department** d;
	if(depcount == 0)
	{
		cout<<"There are no departments in this institute"<<endl;
		return false;

	}
	while(1){
		cout<<"Please enter the department ID"<<endl;
		string idd;
		cin>>idd;
		Department** p= this->departments;
		int i;
		for(i=0; i<depcount; i++)
		{
			if((**(p+i)).getid() == idd){
				d=(p+i);
				break;
			}
		}
		if((**(p+i)).getid()==idd)
			break;
		else cout<<"The ID is incorrect"<<endl;
	}
	while(1){
		cout<<"Please enter the course name"<<endl;
		string name;
		cin>>name;
		cout<<"Please enter the course ID"<<endl;
		string idc;
		cin>>idc;
		Course c;
		c.set_course_name(name);
		c.set_number_course(idc);
		Course* c1=&c;
		int i;
		for (i=0;i<(**d).getcourscount();i++)
		{
			Course* c0 =*((**d).getcourse())+i;
			if(c0==c1)
			{
				cout<<"This course is already exist in this department"<<endl;
				break;
			}
		}
		if(i==(**d).getcourscount())
		{
			return ((**d).operator +=(*c1));

		}
	}
}
bool AcademicInstitute::addStudentToDepartment(){
	Department** d;
	while(1){
		cout<<"Please enter the department ID"<<endl;
		string idd;
		cin>>idd;
		Department** p= this->departments;
		int i;
		for(i=0; i<depcount; i++)
		{
			if((**(p+i)).getid()==idd){
				d=(p+i);
				break;
			}
		}
		if((**(p+i)).getid()==idd)
			break;
		else cout<<"The ID is incorrect"<<endl;
	}
	cout<<"Please enter the student name"<<endl;
	string name;
	cin>>name;
	cout<<"Please enter the student ID"<<endl;
	int ids;
	cin>>ids;
	cout<<"Please enter the student sex"<<endl;
	char sex;
	cin>>sex;
	Student s;
	s.set_stud_name(name);
	s.set_id(ids);
	s.set_sex(sex);
	Student* s1=&s;
	int i;
	for (i=0;i<(**d).getstudcount();i++)
	{
		Student* s0 =*((**d).getstudent())+i;
		if(s0==s1)
		{
			cout<<"This student is already exist in this department"<<endl;
			return false;
		}
	}
	return ((**d).operator +=(*s1));

}
bool AcademicInstitute::registerStudentToCourse(){
	string idd;
	cout<<"please enter the department code"<<endl;
	cin>>idd;
	Department** d;
	Department** p= this->departments;
	int i;
	for(i=0; i<depcount; i++)
	{
		if((**(p+i)).getid()==idd){
			d=(p+i);
			break;
		}
	}
	if(i==depcount)
	{
		cout<<"the department does not exist in the system"<<endl;
		return false;
	}
	string idc;
	cout<<"please enter the course code"<<endl;
	cin>>idc;
	Course** c;
	Course** q=(**d).getcourse();
	for(i=0; i<(**d).getcourscount(); i++)
	{
		if((**(q+i)).getid()==idc){
			c=(q+i);
			break;
		}
	}
	if(i==(**d).getcourscount())
	{
		cout<<"the course does not exist in this department"<<endl;
		return false;
	}
	int ids;
	cout<<"please enter the student id"<<endl;
	cin>>ids;
	Student** s;
	Student** w=(**d).getstudent();
	for(i=0; i<(**d).getbadstudcount(); i++)
	{
		if((**(w+i)).getid()==ids){
			s=(w+i);
			break;
		}
	}
	if(i==(**d).getbadstudcount())
	{
		cout<<"the student does not exist in this department"<<endl;
		return false;
	}
	w=(**c).getstudents();
	Student s1=**s;
	for(i=0; i<(**c).getcount(); i++)
	{
		if((**(w+i))==s1){
			cout<<"the student is already registered for the course"<<endl;
			return false;
		}
	}
	return ((**c).operator +=(s1));

}
void AcademicInstitute::gradingStudentsInCourse(){
	Course** c;
	Department** d;
	while(1){
		cout<<"Please enter the course ID"<<endl;
		string idc;
		cin>>idc;
		Department** p= this->departments;
		Course** q;
		int i;
		int j;
		for(i=0; i<depcount; i++)
		{
			for(j=0; j<(**p).getcourscount(); j++)
			{
				q=(**p).getcourse();
				if((**(q+i)).getid()==idc){
					c=(q+i);
					d=(p+i);
					break;
				}
			}
			if (j<(**p).getcourscount()) break;
		}
		if((*c)->getid()==idc)
		{
			break;
		}
		else cout<<"the course id is incorrect"<<endl;
	}
	if (!(*c)->getcount())
		cout<<"There are no students register for this course"<<endl;
	else{
		Student** p = (**c).getstudents();
		int** q = (**c).getstudentsgrades();
		for (int i=0; i<(**c).getcount(); i++)
		{
			cout<<"please enter the grade of the student:"<<endl;
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<endl;
			cin>>(**(q+i));
		}
		Student** w = (**d).getstudent();
		for (int i=0; i<(**d).getstudcount(); i++)
		{
			if(isbad(**(w+i)))
			{
				(**d).addbadstu(**(w+i));
			}
		}
	}
}
bool AcademicInstitute::isbad(Student &s1)
{
	return (s1.getave() < 65);
}
void AcademicInstitute::printCourseInformation(){
	Department** d;
	Course** c;
	while(1){
		cout<<"Please enter the course ID"<<endl;
		string idc;
		cin>>idc;
		Department** p= this->departments;
		Course** q;
		int i;
		int j;
		for(i=0; i<depcount; i++)
		{
			for(j=0; j<(**p).getcourscount(); j++)
			{
				q=(**p).getcourse();
				if((**(q+i)).getid()==idc){
					d=(p+i);
					c=(q+i);
					break;
				}
			}
			if (j<(**p).getcourscount()) break;
		}
		if((*c)->getid()==idc)
		{
			break;
		}
		else cout<<"the course id is incorrect"<<endl;
	}
	cout<<"The department name that the course is in is:"<<(**d).getname()<<endl;
	cout<<"the id of the department"<<(**d).getid()<<endl;
	cout<<(**c)<<endl;
}
void AcademicInstitute::printStudentInformation(){
	Student** c;
	while(1){
		cout<<"Please enter the Student ID"<<endl;
		int ids;
		cin>>ids;
		Department** p= this->departments;
		Student** q;
		int i;
		int j;
		for(i=0; i<depcount; i++)
		{
			for(j=0; j<(**p).getbadstudcount(); j++)
			{
				q=(**p).getstudent();
				if((**(q+i)).getid()==ids){
					c=(q+i);
					break;
				}
			}
			if (j<(**p).getbadstudcount()) break;
		}
		if((*c)->getid()==ids)
		{
			break;
		}
		else cout<<"the course id is incorrect"<<endl;
	}
	cout<<(**c)<<endl;

}
void AcademicInstitute::printDepartmentInformation(){
	Department** d;
	while(1){
		cout<<"Please enter the department ID"<<endl;
		string idd;
		cin>>idd;
		Department** p= this->departments;
		int i;
		for(i=0; i<depcount; i++)
		{
			if((**(p+i)).getid()==idd){
				d=(p+i);
				break;
			}
		}
		if((*d)->getid()==idd)
		{
			break;
		}
		else cout<<"the department id is incorrect"<<endl;
	}
	cout<<(**d)<<endl;
}
bool AcademicInstitute::removeStudentFromCourse(){
	cout<<"Please enter the Course ID"<<endl;
	string idc;
	cin>>idc;
	Course** c;
	Department** p= this->departments;
	Course** q;
	int i;
	int j;
	for(i=0; i<depcount; i++)
	{
		for(j=0; j<(**p).getcourscount(); j++)
		{
			q=(**p).getcourse();
			if((**(q+i)).getid()==idc){
				c=(q+i);
				break;
			}
		}
		if (j<(**p).getcourscount()) break;
	}
	if((*c)->getid()!=idc)
	{
		cout<<"there is no such course in the institute"<<endl;
		return false;
	}
	else{
		cout<<"Please enter the Student ID"<<endl;
		int ids;
		cin>>ids;
		Student** s;
		Student** w= (**c).getstudents();
		int k;
		for(k=0; k<(**c).getcount();k++)
		{
			if((*(w+k))->getid() == ids)
			{
				s=w+k;
				break;
			}
		}
		if(k==(**c).getcount())
		{
			cout<<"the student does not take this course"<<endl;
			return false;
		}
		else{
			(**c).operator -=(**s);
			(**s).operator -=(**c);
			return true;
		}
	}
	return false;
}
bool AcademicInstitute::exit(){
	for(int i=0; i<this->depcount; i++){
		delete this->departments[i];
	}
	for(int i=0; i<this->notincount; i++){
		delete this->notintact[i];
	}
	for(int i=0; i<this->stcount; i++){
		delete this->students[i];
	}
	delete[] departments;
	delete[] students;
	delete[] notintact;

	return true;
}






