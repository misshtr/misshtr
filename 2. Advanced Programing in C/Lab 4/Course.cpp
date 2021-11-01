/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#include "Course.h"
#include <iostream>
using namespace std;


Course::Course() { //empty constructor
	this->name = "";
	this->id = "";
	this->count = 0;
	this->student_grades = 0;
	this->students = 0;
}
Course::Course(Course &cours){ //constructor
	this->name=cours.getname();
	this->id=cours.getid();
	this->set_Student(cours.getstudents(), cours.getcount());
	this->set_grades(cours.getstudentsgrades());
	this->count=cours.getcount();
}

Course::~Course(){ //destructor
	delete[] this->student_grades;
	delete[] this->students;
}

Student** Course::isnewlist(int length){ //CHECKS IF NEEDS TO ALLOCATE
	if(this->count < length){ //IF NEEDS BIGGER LIST
		Student** stud = new Student*[length];
		if(stud!=NULL) //ALLOCATION COMPLETE
			return stud;
	}
	return this->students; //IN CASE NO ALLOC
}

Student** Course::copylist(Student** newlist,int length){ //COPY ONE LIST TO ANOTHER
	if (count == 0){ //NEW STUDENT CASE
		Student** p = newlist;
		for (int i=0; i<length; i++)
		{
			students = isnewlist(length);
			*(students+i)=*(p+i);
		}
		return this->students;
	}
	else if(this->students==newlist){ //COPYING COURSE INFO TO ITSELF, WE WANT TO MAKE OLD LIST BIGGER
		Student** p = newlist;
		delete[] students;
		students = new Student*[length];
		for (int i=0; i<length; i++)
		{
			*(students+i)=*(p+i);
		}
		return students;
	}
	else { //NOT NEW, NEEDS BIGGER LIST
		Student** p = newlist;
		delete[] this->students;
		students = new Student*[length];
		for (int i=0; i<length; i++)
		{
			*(students+i)=*(p+i);
		}
		return students;
	}
}
int** Course::isnewlistgrade(int length){ //CHECKS IF NEEDS TO ALLOCATE
	if(this->count < length){ //IF NEEDS BIGGER LIST
		int** stud = new int*[length];
		if(stud!=NULL) //ALLOCATION COMPLETE
			return stud;
	}
	return this->student_grades; //IN CASE NO ALLOC
}

int** Course::copylist(int** newlist,int length){ //COPY ONE LIST TO ANOTHER
	if (count == 0){ //NEW STUDENT CASE
		int** p = newlist;
		for (int i=0; i<length; i++)
		{
			student_grades = isnewlistgrade(length);
			int x= **(p+i);
			int* X = &x;
			*(student_grades+i)=X;
		}
		return this->student_grades;
	}
	else if(this->student_grades==newlist){ //COPYING COURSE INFO TO ITSELF, WE WANT TO MAKE OLD LIST BIGGER
			int** p = newlist;
			delete[] student_grades;
			student_grades = new int*[length];
			for (int i=0; i<length; i++)
			{
				*(student_grades+i)=*(p+i);
			}
			return student_grades;
		}
		else { //NOT NEW, NEEDS BIGGER LIST
			int** p = newlist;
			delete[] this->student_grades;
			student_grades = new int*[length];
			for (int i=0; i<length; i++)
			{
				*(student_grades+i)=*(p+i);
			}
			return student_grades;
		}
}
Student** Course::getstudents()
{
	return this->students;
}
int** Course::getstudentsgrades()
{
	return this->student_grades;
}

string Course::getname(){ //gets course name
	return this->name;
}
string Course::getid(){ //gets course id
	return this->id;
}
int Course::getcount(){ //gets student count in course
	return this->count;
}
void Course::set_course_name(string x){
	this->name = x;
}
void Course::set_number_course(string x){
	this->id = x;
}
void Course::set_Student(Student** x, int i){
	this->students = copylist(x,i);
	this->count = i;
}

void Course::set_grades(int** x){
	int i = count;
	this->student_grades = copylist(x,i);
}
void Course::set_studcount(int x){
	this->count = x;
}
Course Course::operator=(Course &cours){
	this->name=cours.getname();
	this->id=cours.getid();
	this->copylist(cours.students, cours.count);
	this->copylist(cours.student_grades, cours.count);
	this->count=cours.count;
	return *this;
}
bool Course::operator==(Course &course){
	return this->id==course.getid();
}
bool Course::operator>(Course &course){
	if (this->count > course.getcount())
		return true;
	else return false;
}
ostream& operator<<(ostream& output,Course& cours){
	cout<<"the name of the course is:"<<cours.getname()<<endl;
	cout<<"the course number is:"<<cours.getid()<<endl;
	if (!cours.getcount())
		cout<<"There are no students register for this course"<<endl;
	else{
		cout<<"the students that are registered for this course are:"<<endl;
		Student** p = cours.students;
		int** q = cours.student_grades;
		for (int i=0; p+i==NULL; i++)
		{
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<" and is grade is:"<<**(q+i)<<endl;
		}
	}
	return output;
}
istream& operator>>(istream& input,Course& cours){
	cout<<"please enter the name of the course"<<endl;
	input>>cours.name;
	cout<<"please enter the ID of the course"<<endl;
	input>>cours.id;
	return input;
}
bool Course::operator+=(Student &stud){
	Student* s = &stud;
	if(count==0)
	{
		students= new Student*[1];
		student_grades=new int*[1];
		*students = &stud;
		int *x=new int;
		*x=-1;
		(*student_grades)=x;
		count ++;
		return true;
	}
	if (searchinlist(s)!=-1)
	{
		cout<<"The student is already registered for the course"<<endl;
		return false;
	}
	Student** p = this->students;
	p = this->students;
	int** q = this->student_grades;
	if (*(p+count+1)==NULL)
	{
		*(p+count+1)=s;
		count++;
		**(q+count)=-1;
		return true;
	}
	else{
		Student** newstudents;
		int** newgrades;
		newstudents=isnewlist(2*count);
		newgrades = isnewlistgrade(2*count);
		if((newstudents==NULL)||(newgrades==NULL))
		{
			cout<<"ERROR: No memory"<<endl;
			return false;
		}
		if ((newstudents != this->students) && (newgrades!=this->student_grades)){
			newstudents=copylist(newstudents,count);
			p = newstudents+count;
			for(int i=0; i<2*count;i++)
				*(p+i)=NULL;
			this->students = newstudents;
			newgrades = copylist(newgrades,count);
			q=newgrades+count;
			for(int i=0; i<2*count;i++)
				*(q+i)=NULL;
			this->student_grades = newgrades;
		}
		p = this->students;
		q = this->student_grades;
		*(p+count+1)=s;
		count++;
		**(q+count)=-1;
		return true;

	}
	return false;
}
bool Course::operator-=(Student &stud){
	int i= searchinlist(&stud);
	if (i==-1)
	{
		cout<<"the student does not take this course"<<endl;
		return false;
	}
	else{
		Student** p = this->students;
		int** q = this->student_grades;
		for(int j=i; j<count-1; j++)
		{
			*(p+j)=*(p+j+1);
			*(q+j)=*(q+j+1);
		}
		*(p+count)=NULL;
		*(q+count)=NULL;
		count--;
		shrinkinglist();
		return true;
	}
}
Student* Course::operator[](int num){
	Student** p = this->students;
	if (num >count)
	{
		cout<<"there is no such place in the list of students taking this course."<<endl;
		return NULL;
	}
	return *(p+num);
}
int Course::searchinlist(Student* s1)
{
	Student** p=this->students;
	for (int i=0; i<count;i++)
	{
		if(*(p+i)==s1)
			return i;
	}
	return -1;
}
void Course::shrinkinglist()
{
	Student** p=this->students;
	int i;
	for (i=count; *(p+i)!=NULL;i++);
	if (count <= ((i-1)/4)){
		i=(i-1)/2;
		Student** stud = new Student*[i];
		int** grades = new int*[i];
		if((stud!=NULL)&& grades!=NULL){ //ALLOCATION COMPLETE
			stud=copylist(stud,i);
			grades=copylist(grades,i);
			Student** r = stud;
			int** q=grades;
			for(int j=count; j<i;j++){
				*(r+j)=NULL;
				*(q+j)=NULL;
			}
			this->students=stud;
			this->student_grades = grades;
		}
	}
}
int Course::getgrade(Student* s0){
	int i=searchinlist(s0);
	int** p = this->student_grades;
	if (i >count)
	{
		cout<<"there is no such place in the list of students taking this course."<<endl;
		return -1;
	}
	return **(p+i);
}







