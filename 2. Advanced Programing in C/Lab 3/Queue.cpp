#include "Queue.h"
using namespace std;

/**
 * Create an empty queue.
 */
Queue::Queue(){
	this->list= LinkedList();
}

/**
 * Remove all values from the queue.
 */
Queue::~Queue(){
	this->list.~LinkedList();
}

/**
 * Place a new value at the front of the queue.
 *
 * @param data  The data to be inserted.
 */
void Queue::enqueue(int value){
	this->list.prepend(value);
}

/**
 * Remove the value from the front of the queue.
 */
void Queue::dequeue(){
	this->list.remove(0);
}

/**
 * Get the value from the front of the queue.
 */
int Queue::front() const{
	return this->list.at(0);
}

/**
 * Whether or not the current queue contains values.
 *
 * @return      True if at least one value exists.
 */
bool Queue::isEmpty() const{
	return this->list.isEmpty();
}

/**
 * Get the length of the queue.
 *
 * @return      The amount of nodes in the queue.
 */
unsigned Queue::length() const{
	return this->list.length();
}

/**
 * Print the contents of the queue.
 */
const char* Queue::print() const{
	this->list.print();
	return "\0";
}
