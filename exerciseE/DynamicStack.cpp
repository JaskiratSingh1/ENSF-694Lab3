/*
 *  DynamicStack.cpp
 *  ENSF 694 Lab 3, exercise E
 *  Completed by: Jaskirat Singh
 *  Submission date: July 17
 */

#include "DynamicStack.h"

DynamicStack::DynamicStack( int n ){
    //Initialize member variables according to promises
    entry = 0;
    initial_capacity = current_capacity = n;
    array = new int[initial_capacity];
}


DynamicStack::DynamicStack( DynamicStack const &stack ) {
    //Initialize member variables by the provided object
    entry = stack.entry;
    initial_capacity = stack.initial_capacity;
    current_capacity = stack.current_capacity;
    //Initialize new array and populate it
    array = new int[current_capacity];
    for (int i = 0; i < entry; i++){
        array[i] = stack.array[i];
    }
}

DynamicStack::~DynamicStack() {
    //Deconstructor deletes array and frees up the memory
    delete[] array;
}


int DynamicStack::top() const {
    //Check if stack is empty
    if(entry > 0) {
        //Return top value if stack is populated
        return array[entry - 1];
    }
    //Stack is empty
    return -1;
}

int DynamicStack::size() const {
    //Entry holds the location for the enxt element, i.e. size
    return entry;
}


bool DynamicStack::empty() const {
    //If entry is 0 then stack is empty
    return entry == 0;
}

int DynamicStack::capacity() const {
    //Provided the current capacity
    return current_capacity;
}

DynamicStack &DynamicStack::operator=( DynamicStack const &rhs ) {
    //Copy constructor
    if(this != &rhs) {
        //Delete member array to free up memory
        delete[] array;
        //Populate new vars
        entry = rhs.entry;
        initial_capacity = rhs.initial_capacity;
        current_capacity = rhs.current_capacity;
        array = new int[current_capacity];
        for(int i = 0; i < entry; i++) {
            array[i] = rhs.array[i];
        }
    }
    //Return the this pointer
    return *this;
}

void DynamicStack::push(const int  &obj ) {
    if(entry == current_capacity){
        //Double capacity if it has been reached
        current_capacity *= 2;
        //Generate new array with new capacity
        int *newArray = new int[current_capacity];
        //Populate new array
        for(int i = 0; i < entry; i++) {
            newArray[i] = array[i];
        }
        //Delete old array
        delete[] array;
        //Point member array to new enlarged array
        array = newArray;
    }
    //Add the new element in the stack
    array[entry++] = obj;
}

int DynamicStack::pop() {
    //If array is empty do nothing
    if (entry == 0) {
        return -1;
    }
    //Get new top of stack, decrementing entry
    int value = array[--entry];
    
    //Halve current capacity if the stated conditions are met
    if(entry == current_capacity / 4 && current_capacity > initial_capacity && entry > 0){
        //Halve the capacity
        current_capacity /= 2;
        //Create new array with new capacity
        int *newArray = new int[current_capacity];
        //Populate new array
        for (int i = 0; i < entry; ++i) {
            newArray[i] = array[i];
        }
        //Delete old array in memory
        delete[] array;
        //Point member array to new smaller array
        array = newArray;
    }
    //Return the value of the new top of stack
    return value;
}

void DynamicStack::clear(){
    //Delete the existing array in memory
    delete[] array;
    //Reset current capcity to initial value
    current_capacity = initial_capacity;
    //Create new array with the new current capacity
    array = new int[current_capacity];
    //Reset entry to 0
    entry = 0;
}

void DynamicStack::display(){
    //Print out all the entries of the stack
    for(int i = 0; i < entry; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
