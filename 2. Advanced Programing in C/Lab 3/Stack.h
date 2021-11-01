#include "LinkedList.h"

#ifndef CPP_STACK_H
#define CPP_STACK_H

class Stack {
private:
    LinkedList list;

public:
    /**
     * Create an empty stack.
     */
    Stack();

    /**
     * Remove all values from the stack.
     */
    ~Stack();

    /**
     * Get the value from the top of the stack.
     */
    int top() const;

    /**
     * Remove the value from the top of the stack.
     */
    void pop();

    /**
     * Place a new value at the top of the stack.
     *
     * @param data  The data to be inserted.
     */
    void push(int data);

    /**
     * Whether or not the current stack contains values.
     *
     * @return      True if at least one value exists.
     */
    bool isEmpty() const;

    /**
     * Get the length of the stack.
     *
     * @return      The amount of nodes in the stack.
     */
    unsigned length() const;

    /**
     * Print the contents of the stack.
     */
    const char* print() const;
};

#endif
