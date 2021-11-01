#include "Stack.h"
using namespace std;

/**
 * Create an empty stack.
 */
Stack::Stack(){
	this->list= LinkedList();
}

/**
 * Remove all values from the stack.
 */
Stack::~Stack(){
	while(this->length()!=0){
		this->pop();
	}
}

/**
 * Get the value from the top of the stack.
 */
int Stack::top() const{
	return this->list.at(this->length()-1);
}

/**
 * Remove the value from the top of the stack.
 */
void Stack::pop(){
	this->list.remove(this->length()-1);
}

/**
 * Place a new value at the top of the stack.
 *
 * @param data  The data to be inserted.
 */
void Stack::push(int data){
	this->list.append(data);
}

/**
 * Whether or not the current stack contains values.
 *
 * @return      True if at least one value exists.
 */
bool Stack::isEmpty() const{
	return this->list.isEmpty();
}

/**
 * Get the length of the stack.
 *
 * @return      The amount of nodes in the stack.
 */
unsigned Stack::length() const{
	return this->list.length();
}

/**
 * Print the contents of the stack.
 */
const char* Stack::print() const{
	this->list.print();
	return "\0";
}
