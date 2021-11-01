#include "LinkedList.h"

#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

class Queue {
private:
    LinkedList list;

public:
    /**
     * Create an empty queue.
     */
    Queue();

    /**
     * Remove all values from the queue.
     */
    ~Queue();

    /**
     * Place a new value at the front of the queue.
     *
     * @param data  The data to be inserted.
     */
    void enqueue(int value);

    /**
     * Remove the value from the from of the queue.
     */
    void dequeue();

    /**
     * Get the value from the front of the queue.
     */
    int front() const;

    /**
     * Whether or not the current queue contains values.
     *
     * @return      True if at least one value exists.
     */
    bool isEmpty() const;

    /**
     * Get the length of the queue.
     *
     * @return      The amount of nodes in the queue.
     */
    unsigned length() const;

    /**
     * Print the contents of the queue.
     */
    const char* print() const;
};


#endif
