/*
 *  lab3Clock.cpp
 *  ENSF 694 Lab 3, exercise C
 *  Completed by: Jaskirat Singh
 *  Submission date: July 17
 */


#include "lab3Clock.h"

Clock::Clock(int hour, int minute, int second){
    //Make sure a valid time is entered, if not then initialize to 0
    if(hour >= 0 && minute >= 0 && second >= 0 && hour < 24 && minute < 60 && second < 60){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    else{
        //If invalid time is provided then set everything to 0
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
}

void Clock::increment(){
    //If seconds less than 59, increment it
    if(this->second < 59){
        this->second ++;
    }
    //If seconds == 59 check if minute less than 59 (seconds are 59)
    else if(this->minute < 59){
        this->second = 0;
        this->minute ++;
    }
    //If seconds == 59 and minute == 59 check if hour less than 23
    else if(this->hour < 23){
        this->second = 0;
        this->minute = 0;
        this->hour ++;
    }
    //If time is 23:59:59
    else{
        this->second = 0;
        this->minute = 0;
        this->hour = 0;
    }
}

void Clock::decrement(){
    //If seconds are more than 0, decrement it
    if(this->second > 0){
        this->second --;
    }
    //If minutes are more than 0, decrement it (seconds are 0)
    else if(this->minute > 0){
        this->second = 59;
        this->minute --;
    }
    //If hours are more than 0, decrement it (seconds and minutes are 0)
    else if(this->hour > 0){
        this->second = 59;
        this->minute = 59;
        this->hour --;
    }
    //Time is 00:00:00
    else{
        this->second = 59;
        this->minute = 59;
        this->hour = 23;
    }
}

void Clock::add_seconds(int seconds){
    //Call the increment function each time for each second to be added
    for(int i = 0; i < seconds; i++){
        increment();
    }
}

void Clock::sec_to_hms(int time){
    //If time is negative then do nothing
    if(time < 0) {return;}
    //Get hours and mod 24 to ensure hours is less than 24
    this->hour = (time / 3600) % 24;
    //Get minutes and mod by 60 to ensure minutes is less than 60
    this->minute = (time / 60) % 60;
    //Get seconds
    this->second = time % 60;
}
