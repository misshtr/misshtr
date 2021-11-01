/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#include "Department.h"
#include <iostream>
using namespace std;

Department::Department(){
	this->name = "";
	this->id = "";
	this->course = NULL;
	this->cours_count = 0;
	this->student = NULL;
	this->stud_count = 0;
	this->bad_students = NULL;
	this->bad_stud_count = 0;
}
Department::Department(Department &d){
	this->name = d.name;
	this->id = d.id;
	this->course = d.course;
	this->cours_count = d.cours_count;
	this->student = d.student;
	this->stud_count = d.stud_count;
	this->bad_students = d.bad_students;
	this->bad_stud_count = d.bad_stud_count;
}
Department::~Department(){
	delete[] this->course;
	delete[] this->student;
	delete[] this->bad_students;
}

void Department::set_dep_name(string x){
	this->name = x;
}
void Department::set_id(string x){
	this->id = x;
}
Course** Department::getcourse(){
	return this->course;
}
Student** Department::getstudent(){
	return this->student;
}
string Department::getname(){
	return this->name;
}
string Department::getid(){
	return this->id;
}
int Department::getcourscount(){
	return this->cours_count;
}
int Department::getstudcount(){
	return this->stud_count;
}
int Department::getbadstudcount(){
	return this->bad_stud_count;
}
Department& Department::operator=(Department &dep){
	this->name = dep.getname();
	this->id = dep.getid();
	this->bad_stud_count = dep.getbadstudcount();
	this->copylist(dep.course, dep.cours_count);
	this->copylist(dep.student, dep.stud_count);
	this->copylist(dep.bad_students, dep.bad_stud_count);
	this->cours_count = dep.getcourscount();
	this->stud_count = dep.getstudcount();
	return *this;
}
bool Department::operator>(Department &dep){
	if(this->isacademicvalid() > dep.isacademicvalid())
		return true;
	return false;
}
ostream& operator<<(ostream &output,Department &dep1){
	cout<<"The name of the department is:"<<dep1.getname()<<endl;
	cout<<"The ID of the department is:"<<dep1.getid()<<endl;
	if (!dep1.getcourscount())
		cout<<"There are no courses in this department"<<endl;
	else{
		cout<<"the courses in this department are:"<<endl;
		Course** p = dep1.course;
		for (int i=0; p+i==NULL; i++)
		{
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<endl;
		}
	}
	if (!dep1.getstudcount())
		cout<<"There are no students in this department"<<endl;
	else{
		cout<<"the students in this department are:"<<endl;
		Student** p = dep1.student;
		for (int i=0; p+i==NULL; i++)
		{
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<endl;
		}
	}
	if (!dep1.getbadstudcount())
		cout<<"There are no bad students in this department"<<endl;
	else{
		cout<<"the bad students in this department are:"<<endl;
		Student** p = dep1.bad_students;
		for (int i=0; p+i==NULL; i++)
		{
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<endl;
		}
	}
	return output;
}

istream& operator>>(istream& input, Department& dep1){

	cout<<"please enter the name of the department"<<endl;
	input>>dep1.name;
	cout<<"please enter the ID of the department"<<endl;
	input>>dep1.id;
	return input;

}
bool Department::operator+=(Course &cours){
	Course** p = this->course;
	if(cours_count==0)
	{
		course= new Course*[1];
		**course = cours;
		cours_count ++;
		return true;
	}
	if (searchinlist(cours)!=-1)
	{
		cout<<"The student is already registered for the course"<<endl;
		return false;
	}
	p = this->course;
	if (*(p+cours_count+1)==NULL)
	{
		**(p+cours_count+1)=cours;
		cours_count++;
		return true;
	}
	else{
		Course** newcourse;
		newcourse=isnewclist(2*cours_count);
		if(newcourse==NULL)
		{
			cout<<"ERROR: No memory"<<endl;
			return false;
		}
		if (newcourse != this->course){
			newcourse=copylist(newcourse,cours_count);
			p = newcourse+cours_count;
			for(int i=0; i<2*cours_count;i++)
				*(p+i)=NULL;
			this->course = newcourse;
		}
		p = this->course;
		**(p+cours_count+1)=cours;
		cours_count++;
		return true;

	}
	return false;
}
bool Department::operator+=(Student &stud){
	Student** p = this->student;
	if(stud_count==0)
	{
		student= new Student*[1];
		*student = &stud;
		stud_count ++;
		return true;
	}
	if (searchinlist(stud)!=-1)
	{
		cout<<"The student is already registered for the department"<<endl;
		return false;
	}
	p = this->student;
	if (*(p+stud_count+1)==NULL)
	{
		**(p+stud_count+1)=stud;
		stud_count++;
		return true;
	}
	else{
		Student** newstude;
		newstude=isnewslist(2*stud_count);
		if(newstude==NULL)
		{
			cout<<"ERROR: No memory"<<endl;
			return false;
		}
		if (newstude != this->student){
			newstude=copylist(newstude,stud_count);
			p = newstude+stud_count;
			for(int i=0; i<2*stud_count;i++)
				*(p+i)=NULL;
			this->student = newstude;
		}
		p = this->student;
		**(p+stud_count+1)=stud;
		stud_count++;
		return true;

	}
	return false;
}


bool Department::addbadstu(Student &stud){
	Student** p = this->bad_students;
	if(bad_stud_count==0)
	{
		student= new Student*[1];
		**bad_students =stud;
		bad_stud_count ++;
		return true;
	}
	if (searchinlist(stud)!=-1)
	{
		cout<<"The student is already registered for the stude"<<endl;
		return false;
	}
	p = this->bad_students;
	if (*(p+bad_stud_count+1)==NULL)
	{
		**(p+bad_stud_count+1)=stud;
		bad_stud_count++;
		return true;
	}
	else{
		Student** newstude;
		newstude=isnewslist(2*bad_stud_count);
		if(newstude==NULL)
		{
			cout<<"ERROR: No memory"<<endl;
			return false;
		}
		if (newstude != this->bad_students){
			newstude=copylist(newstude,bad_stud_count);
			p = newstude+bad_stud_count;
			for(int i=0; i<2*bad_stud_count;i++)
				*(p+i)=NULL;
			this->bad_students = newstude;
		}
		p = this->bad_students;
		**(p+bad_stud_count+1)=stud;
		bad_stud_count++;
		return true;

	}
	return false;
}
Course** Department::copylist(Course** newlist,int length){ //COPY ONE LIST TO ANOTHER
	if (cours_count == 0){ //NEW STUDENT CASE
		Course** p = newlist;
		course = isnewclist(length);
		for (int i=0; i<length; i++)
		{
			*(course+i)=*(p+i);
		}
		return this->course;
	}

	else if(this->course == newlist){ //COPYING COURSE INFO TO ITSELF, WE WANT TO MAKE OLD LIST BIGGER
		Course** p = newlist;
		delete[] course;
		course = new Course*[length];
		for (int i=0; i<length; i++)
		{
			*(course+i)=*(p+i);
		}
		return newlist;
	}
	else { //NOT NEW, NEEDS BIGGER LIST
		Course** p = newlist;
		delete[] course;
		course = new Course*[length];
		for (int i=0; i< length; i++)
		{
			*(course+i)=*(p+i);
		}

		return course;
	}
}

Student** Department::copylist(Student** newlist,int length){ //COPY ONE LIST TO ANOTHER
	if (stud_count == 0){ //NEW STUDENT CASE
		Student** p = newlist;
		for (int i=0; i<length; i++)
		{
			student = isnewslist(length);
			*(student+i)=*(p+i);
		}
		return this->student;
	}
	else if(this->student==newlist){ //COPYING COURSE INFO TO ITSELF, WE WANT TO MAKE OLD LIST BIGGER
		Student** p = newlist;
		delete[] student;
		student = new Student*[length];
		for (int i=0; i<length; i++)
		{
			*(student+i)=*(p+i);
		}
		return student;
	}
	else { //NOT NEW, NEEDS BIGGER LIST
		Student** p = newlist;
		delete[] this->student;
		student = new Student*[length];
		for (int i=0; i<length; i++)
		{
			*(student+i)=*(p+i);
		}
		return student;
	}
}

int Department::isacademicvalid(){
	return (this->stud_count - this->bad_stud_count); //RETURNS NUMBER OF ACADEMICLY VALID STUDENTS

}

Student** Department::isnewslist(int length){
	if(this->stud_count < length){ //IF NEEDS BIGGER LIST
		Student** stud = new Student*[length];
		if(stud!=NULL) //ALLOCATION COMPLETE
			return stud;
	}
	return this->student; //IN CASE NO ALLOC
}
Course** Department::isnewclist(int length){

	if(this->cours_count < length){ //IF NEEDS BIGGER LIST
		Course** cours = new Course*[length];
		if(cours!=NULL) //ALLOCATION COMPLETE
			return cours;
	}
	return this->course; //IN CASE NO ALLOC
}

int Department::searchinlist(Student& s1)
{
	Student** p=this->student;
	for (int i=0; i<stud_count;i++)
	{
		if(**(p+i)==s1)
			return i;
	}
	return -1;
}

int Department::searchinlist(Course& c1)
{
	Course** p=this->course;
	for (int i=0; i<cours_count;i++)
	{
		if(**(p+i)==c1)
			return i;
	}
	return -1;
}

/*
Student** Department::isnewbslist(int length){
	if(this->bad_stud_count < length){ //IF NEEDS BIGGER LIST
		Student** stud = new Student*[length];
		if(stud!=NULL) //ALLOCATION COMPLETE
			return stud;
	}
	return this->bad_students; //IN CASE NO ALLOC
}
 */
