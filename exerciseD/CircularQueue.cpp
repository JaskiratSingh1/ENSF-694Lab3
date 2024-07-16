//
//  CircularQueue.cpp
//  Circular Queue
//
//  Created by Mahmood Moussavi on 2024-04-09.
//

#include "CircularQueue.h"

CircularQueue::CircularQueue() {
    //Initialize values
    this->head = 0;
    this->tail = 0;
    this->count = 0;
}

bool CircularQueue::isFull()const {
    if((tail + 1) % SIZE == head){
        return true;
    }
    return false;
}

bool CircularQueue::isEmpty()const {
    return head == tail;
}

int CircularQueue::enqueue(int v) {
    if(isFull()){
        //Queue Full
        return -1;
    }
    int pos = tail;
    arr[tail] = v;
    tail = (tail + 1) % SIZE;
    count++;
    return pos;
}

int CircularQueue::dequeue() {
    if(isEmpty()){
        return -1;
    }
    int pos = head;
    head = (head + 1) % SIZE;
    count--;
    return pos;
}

int CircularQueue::counter()const{
    return this->count;
}

const int* CircularQueue::get_arr()const{
    return this->arr;
}

void CircularQueue::displayQueue() const {
    if(isEmpty()){
        cout << "Queue is empty." << endl;
        return;
    }
    for(int i = 0;i < count;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
