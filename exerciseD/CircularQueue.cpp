/*
 *  CircularQueue.cpp
 *  ENSF 694 Lab 1, exercise D
 *  Completed by: Jaskirat Singh
 *  Submission date: July 17
 */

#include "CircularQueue.h"

CircularQueue::CircularQueue() {
    //Initialize values
    this->head = 0;
    this->tail = 0;
    this->count = 0;
}

bool CircularQueue::isFull()const {
    //If tail is one behind head then queue is full
    if((tail + 1) % SIZE == head){
        return true;
    }
    return false;
}

bool CircularQueue::isEmpty()const {
    //If head and tail are at same location then queue is empty
    return head == tail;
}

int CircularQueue::enqueue(int v) {
    if(isFull()){
        //Queue Full
        return -1;
    }
    //Save position
    int pos = tail;
    //Update queue value
    arr[tail] = v;
    //Move tail forward by one % SIZE to maintain circularity
    tail = (tail + 1) % SIZE;
    //Increase count
    count++;
    //Return pos to fulfil tester requirements
    return pos;
}

int CircularQueue::dequeue() {
    if(isEmpty()){
        return -1;
    }
    //Save position
    int pos = head;
    //Move head forward by one % SIZE to maintain circularity
    head = (head + 1) % SIZE;
    //Increase count
    count--;
    //Return pos to fulfil tester requirements
    return pos;
}

int CircularQueue::counter()const{
    //Output count value
    return this->count;
}

const int* CircularQueue::get_arr()const{
    //Output array
    return this->arr;
}

void CircularQueue::displayQueue() const {
    //Check if queue is empty
    if(isEmpty()){
        cout << "Queue is empty." << endl;
        return;
    }
    //Since tail is kept one index behind add one to print
    for(int i = 0;i < count;i++) {
        cout << arr[i+1] << " ";
    }
    cout << endl;
}
