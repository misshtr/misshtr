//============================================================================
/* Assignment: 4
Author1: Zohar Krupkin,
ID: 307936930
Author2: Hadar Rivlin,
ID: 207092537
 */
//============================================================================

//#include <iostream>
#include "Student.h"
#include "Course.h"
#include "Department.h"
#include "AcademicInstitute.h"

using namespace std;


int main() {
/*	Student s1;
	s1.set_stud_name("Zohar");
	s1.set_id(123);
	s1.set_sex('F');
	cout<<s1.getname()<<endl;
	cout<<s1.getcount()<<endl;
	cout<<s1.getid()<<endl;
	cout<<s1.getsex()<<endl;
	Student s2;
	s2.set_stud_name("Hadar");
	s2.set_id(2020);
	s2.set_sex('M');
	if (!(s1==s2))
		cout<<"1the == is working"<<endl;
	Course c3;
	c3.set_course_name("programming");
	c3.set_number_course("12-345");
	Course p=c3;
	s2+=c3;
	s1=s2;
	s1.getname();
	if (s1==s2)
		cout<<"2the == is working"<<endl;
	Course c1;
	c1.set_course_name("programming");
	c1.set_number_course("12345");
	cout<<c1.getcount();
	cout<<c1.getid();
	cout<<c1.getname();
	Course c2;
	c2.set_course_name("systems");
	c2.set_number_course("12-1");
	c2+=s1;
	if(!(c1==c2))
		cout<<"3the == is working"<<endl;
	c1=c2;
	c1.getname();
	if(c1==c2)
		cout<<"4the == is working"<<endl;
	Department d1("Math","127");
	//d1+=s1;
	//d1+=c3;
*/
	AcademicInstitute a("BGU");
	a.menu();


	return 0;
}



