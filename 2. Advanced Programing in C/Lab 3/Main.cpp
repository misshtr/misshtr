#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>



using namespace std;

void isbalanced(string line);
void whatsthecode();

void whatsthecode(){ //FUNC THAT ONLY PRINTS IF INPUT IS 9999
	int x;
	Stack s = Stack();
	cout<<"PLEASE ENTER NUMBERS"<<endl;
	while(1){
		cin>>x;
		if(x==9999){
			s.print();
			return;
		}
		s.push(x);
	}
}

void isbalanced(string line){
	Stack lst = Stack();
	char curr;
	int count = 0;
	for (int j = 0; line[j]!='\0'; j++){
		++count;
	}
	int size = count;
	char p[size];
	for (int j = 0; j < size; j++){
		p[j] = line[j];
	}
	for( int i=0; i < size; i++){
		if(p[i]=='(' || p[i]=='[' || p[i]=='{'){
			lst.push(p[i]);
			continue;
		}
		if(!lst.isEmpty()){
			cout<<"false"<<endl;
			return; //MEANS WE DIDNT FIND ANY OPENING BRACKETS SO CAN NEVER BE BALANCED
		}
		switch (p[i]){ //NEXT ITEM THAT IS NOT OPENING HAS TO MATCH THE LAST OPEN TO BALANCE
		case ')':
			curr = lst.top();
			lst.pop(); //WE DONT WANT TO CREATE DOUBLES
			if(curr!='('){
				cout<<"false"<<endl;
				return;
			}
			break;
		case ']':
			curr = lst.top();
			lst.pop(); //WE DONT WANT TO CREATE DOUBLES
			if(curr!='['){
				cout<<"false"<<endl;
				return;
			}
			break;
		case '}':
			curr = lst.top();
			lst.pop(); //WE DONT WANT TO CREATE DOUBLES
			if(curr!='{'){
				cout<<"false"<<endl;
				return;
			}
			break;
		}
	}
	if(!lst.isEmpty()) cout<<"true"<<endl; //IF IS BALANCED THE LIST SHOULD BE EMPTY!
	else cout<<"false"<<endl;
	return;
}

int main() {
	cout<<"PLEASE INSERT BRACKET STRING"<<endl;
	string input;
	cin>>input;
	isbalanced(input);
	whatsthecode();
}
