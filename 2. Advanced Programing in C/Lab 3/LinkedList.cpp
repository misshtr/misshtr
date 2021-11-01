#include "LinkedList.h"
using namespace std;


LinkedList::Node* LinkedList::createNode(int data, Node* next){
	Node* new_n = new Node(); //CREATES A NEW NODE
	new_n->data = data;
	new_n->next = next;
	++this->size;
	return new_n;
}


LinkedList::Node* LinkedList::get(int index) const{
	Node* iter = head; //NODE TO ITERATE THRU LIST
	int count = 0;
	if((unsigned int)index > this->size){ //CHECKS IF INDEX IS VALID
		cout<< "index is out of range" << endl;
		return NULL;
	}
	if(head!=NULL){ //IF LIST IS EMPTY
		while(iter!=NULL && count!=index){
			iter = iter->next;
			count++;
		}
		if(count==index) //IF WE FOUND THE NODE IN THE LIST
			return iter; //RETURNS NODE
	}
	return NULL; //RETURNS NULL
}

LinkedList::LinkedList(){
	this->head = NULL; //MAKES SURE ITS EMPTY
	this->tail = NULL;
	this->size = 0;
}

LinkedList::LinkedList(const LinkedList& other){
	LinkedList cpy;
	cpy=LinkedList(); //CREATING NEW LIST
	Node* iter1 = other.head;
	Node* iter2 = cpy.head; //SETTING ITERATORS

	while(iter1){
		iter2 = cpy.head;
		if(cpy.size == 0){ //IF LIST IS EMPTY
			cpy.createNode(other.head->data);
			cpy.tail = cpy.head;
		}
		else while(iter2->next) iter2 = iter2->next; //IF LIST ISNT EMPTY ITERATE TO THE END
		iter2->next = createNode(iter1->data);	//CREATE NEW NODE AT END OF LIST
		cpy.tail = iter2->next;
		iter1 = iter1->next;
	}

}

LinkedList::LinkedList(int* values, int length){
	this->size = 0;
	for(int i=0; i<length; ++i){ //TO ITER THRU EACH ITEM ON ARR TILL END
		this->append(*(values+i)); //CALL FUNC APPEND TO CREATE THE LIST
	}
	this->size = length; //SET SIZE
}

LinkedList::~LinkedList(){
	Node* head = this->head;
	Node* temp;
	while(this->size!=0){ //WHILE LIST ISNT EMPTY
		temp = head; //SAVES HEAD OF LIST
		head = head->next; //DISCONNECTS HEAD
		delete temp; //DELETES PREV HEAD
		--this->size; //MINIMIZE SIZE BY ONE TO GET TO WHILE LOOP END
	}
}

void LinkedList::prepend(int data){
	Node* new_n = createNode(data);
	if(this->size==0){ //IF ITS AN EMPTY LIST
		this->head = new_n; //SETS NEW HEAD
		this->tail = new_n; //HEAD IS ALSO TAIL
	}
	else{
		new_n->next = this->head; //LINKS HEAD TO ORIGIN LIST
		this->head = new_n; //MAKES HEAD THE HEAD OF THE LIST
	}
	++this->size; //ADDS +1 TO SIZE
}

void LinkedList::append(int data){
	Node* iter = this->head;
	if(this->size==0){ //IF LIST IS EMPTY
		this->head = createNode(data); //HEAD OF LIST IS NEW NODE
		this->tail = this->head; //HEAD IS ALSO TAIL
	}
	else{ //LIST ISNT EMPTY
		while(iter->next) iter = iter->next; //ITER TO END OF LIST
		iter->next = createNode(data); //NEXT OF LAST IS A NEW NODE
		this->tail = iter->next; //LAST NODE IS NEW TAIL
	}
}

void LinkedList::insert(int data, int index){
	int i = 1; //YES INDEED
	Node* head = this->head;
	if((unsigned int)index > this->size){ //CHECKS IF INDEX IS VALID
		cout<< "index is out of range" << endl;
		return;
	}
	if(index==0){ //CASE THAT INDEX IS FIRST IN LIST
		this->prepend(data);
		return;
	}
	while(i!=index){ //ANY OTHER CASE, GETS TO ONE BEFORE NEEDED INDEX
		head = head->next;
		++i;
	}
	Node* node = createNode(data, head->next); //CREATES NEW NODE
	head->next = node; //SETS IT IN THE RIGHT INDEX PLACE


}

void LinkedList::remove(int index){
	int i = 1;
	Node* temp;
	Node* head = this->head;
	if((unsigned int)index > this->size){ //CHECKS IF INDEX IS VALID
		cout<< "index is out of range" << endl;
		return;
	}
	if(index==0){ //CASE THAT INDEX IS FIRST IN LIST
		temp = this->head;
		this->head = this->head->next;
		delete temp;
		--this->size; //REDUCING THE LIST SIZE BY ONE
		return;
	}
	while(i!=index){ //ANY OTHER CASE, GETS TO ONE BEFORE NEEDED INDEX
		head = head->next;
		++i;
	}
	temp = head->next; //SAVES NODE WE WANT TO DELETE
	head->next = head->next->next; //CUTS NODE FROM LIST
	delete temp; //DELETE THAT NODE
	--this->size; //REDUCING THE LIST SIZE BY ONE
}

bool LinkedList::contains(int value) const{
	Node* head = this->head;
	while(head){
		if(head->data == value) return true;
		head = head->next;
	}
	return false;
}

bool LinkedList::isEmpty() const{
	if(this->size == 0) return false;
	return true;
}

unsigned LinkedList::length() const{
	return this->size;
}

int LinkedList::at(int index) const{
	Node* head = this->head;
	if((unsigned int)index > this->size){ //CHECKS IF INDEX IS VALID
		cout<< "index is out of range" << endl;
		return index;
	}
	int count = 0;
	while(head){
		if(count == index) return head->data;
		++count;
		head = head->next;
	}
	return index;
}

bool LinkedList::compare(const LinkedList& other){
	Node* head = this->head;
	LinkedList iter = other;
	unsigned int flag = 0;
	while(head){
		if(head->data == iter.head->data) ++flag;
		head = head->next;
		iter.head = iter.head->next;
	}
	if(flag == other.size) return true;
	return false;
}

std::string LinkedList::print() const{
	Node* temp = this->head;
	if(this->size == 0) cout<<"LIST IS EMPTY";
	while(temp->next){
		cout<<temp->data<<endl;
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return "\0";

}












