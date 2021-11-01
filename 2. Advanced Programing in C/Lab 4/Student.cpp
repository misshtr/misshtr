/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(){
	this->name = "";
	this->id = 0;
	this->count = 0;
	this->sex = '\0';
	this->course = 0;
	this->ave = 0;
}
Student::Student(Student &stud){ //constructor
	this->name = stud.name;
	this->id = stud.id;
	this->sex = stud.sex;
	this->set_course(stud.getcourse(),stud.getcount());
	this->count = stud.count;
	this->ave = stud.ave;
}
Student:: ~Student(){ //destructor
	delete[] this->course;
}

Course** Student::isnewlist(int length){ //CHECKS IF NEEDS TO ALLOCATE
	if(this->count < length){ //IF NEEDS BIGGER LIST
		delete[] this->course;
		course = new Course*[length];
		this->count = length;
		if(course!=NULL) //ALLOCATION COMPLETE
			return course;
	}
	return this->course; //IN CASE NO ALLOC
}

Course** Student::copylist(Course** newlist,int length){ //COPY ONE LIST TO ANOTHER
	if (count == 0){ //NEW STUDENT CASE
		Course** p = newlist;
		course = isnewlist(length);
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

string Student::getname(){ //returns the name
	return this->name;
}
int Student::getid(){//returns the id
	return this->id;
}
char Student::getsex(){ //returns the sex
	return this->sex;
}
int Student::getcount(){ //returns courses count
	return this->count;
}
Student Student::operator=(Student &stud){
	Course** s1 = stud.getcourse();
	int i = stud.count;
	this->name = stud.getname();
	this->id = stud.getid();
	this->sex = stud.getsex();
	this->copylist(s1,i);
	this->count = stud.getcount();
	return *this;
}
Course** Student::getcourse(){
	return (this->course);
}
double Student::getave(){
	Course** p = this->course;
	for (int i=0; i<count; i++)
	{
		ave = ave+(*(p+i))->getgrade(this);
	}
	ave = ave/this->count;
	return ave;
}

void Student::set_stud_name(string x){
	this->name = x;
}
void Student::set_id(int x){
	this->id = x;
}
void Student::set_course(Course** x,int i){
	this->course = copylist(x,i);
	this->count = i;
}
void Student::set_sex(char x){
	this->sex = x;
}
void Student::set_count(int x){
	this->count = x;
}
bool Student::operator==(Student &stud){
	return this->id == stud.getid();
}

bool Student::operator>(Student &stud){
	Course** p=this->course;
	Course** q=stud.course;
	double avthis = 0;
	double avstud = 0;
	Student* s1=&stud;
	Student* s2=this;
	for (int i=0; i<count; i++)
	{
		avthis = (**(p+i)).getgrade(s2) + avthis;
		avstud = (**(q+i)).getgrade(s1) + avstud;
	}
	avthis = avthis/this->getcount();
	avstud = avstud/s1->getcount();
	if(avthis>avstud)
		return true;
	else  return false;

}

ostream& operator<<(ostream &output,Student &s1){

	cout<<"The name of the student is:"<<s1.getname();
	cout<<endl;
	cout<<"The ID of the student is:"<<s1.getid()<<endl;
	cout<<"The student is:";
	if (s1.getsex() == 'F' or s1.getsex()=='f')
		cout<<"female"<<endl;
	else cout<<"male"<<endl;
	if (!s1.getcount())
		cout<<"There are no courses that the student is register for"<<endl;
	else{
		cout<<"the courses that the student is registered for are:"<<endl;
		Course** p = s1.course;
		for (int i=0; p+i==NULL; i++)
		{
			cout<<(*(p+i))->getname()<<","<<(*(p+i))->getid()<<endl;
			cout<<"and his grade is: "<<(*(p+i))->getgrade(&s1)<<endl;
		}

		cout<<"the average of the student is: "<<s1.getave()<<endl;
	}
	return output;
}

istream& operator>>(istream& input,Student& s1){
	cout<<"please enter the name of the student"<<endl;
	input>>s1.name;
	cout<<"please enter the ID of the student"<<endl;
	input>>s1.id;
	cout<<"please enter the sex of the student"<<endl;
	input>>s1.sex;
	return input;
}

bool Student::operator+=(Course &cours){
	Course** p = this->course;
	if(count==0)
	{
		this->course= new Course*[1];
		//Course temp;
		//temp=new Course();
		//temp=cours;
		*(this->course) = &cours;
		count ++;
		return true;
	}
	if (searchinlist(cours)!=-1)
	{
		cout<<"The student is already registered for the course"<<endl;
		return false;
	}
	p = this->course;
	if (*(p+count+1)==NULL)
	{
		**(p+count+1)=cours;
		count++;
		return true;
	}
	else{
		Course** newcourse;
		newcourse=isnewlist(2*count);
		if(newcourse==NULL)
		{
			cout<<"ERROR: No memory"<<endl;
			return false;
		}
		if (newcourse != this->course){
			newcourse=copylist(newcourse,count);
			p = newcourse+count;
			for(int i=0; i<2*count;i++)
				*(p+i)=NULL;
			this->course = newcourse;
		}
		p = this->course;
		**(p+count+1)=cours;
		count++;
		return true;

	}
	return false;
}

bool Student::operator-=(Course &cours){
	int i= searchinlist(**course);
	if (i==-1)
	{
		cout<<"the student does not take this course"<<endl;
		return false;
	}
	else{
		Course** p = this->course;
		for(int j=i; j<count-1; j++)
		{
			*(p+j)=*(p+j+1);
		}
		*(p+count)=NULL;
		count--;
		shrinkinglist();
		return true;
	}
}

Course Student::operator[](int num){
	Course** p = this->course;

	if (num >count)
	{
		cout<<"this student is not taking this course."<<endl;

		//????!?!?!!??!what to return
	}
	return **(p+num);
}

int Student::searchinlist(Course &c1)
{
	Course** p=this->course;
	for (int i=0; i<count;i++)
	{
		if(**(p+i)==c1)
			return i;
	}
	return -1;
}

void Student::shrinkinglist()
{
	Course** p=this->course;
	int i;
	for (i=count; *(p+i)!=NULL;i++);
	if (count <= ((i-1)/4)){
		i=(i-1)/2;
		Course** c = new Course*[i];
		if(c!=NULL){ //ALLOCATION COMPLETE
			c=copylist(c,i);
			Course** r = c;
			for(int j=count; j<i;j++){
				*(r+j)=NULL;
			}
			this->course=c;
		}
	}
}


