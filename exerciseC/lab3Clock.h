/*
 *  lab3Clock.h
 *  ENSF 694 Lab 3, exercise C
 *  Completed by: Jaskirat Singh
 *  Submission date: July 17
 */

#ifndef lab3Clock_h
#define lab3Clock_h

using namespace std;

class Clock{
    int hour;
    int minute;
    int second;
    
public:
    /* PROMISES: initializes all member vars to 0 */
    Clock(){hour = minute = second = 0;}
    /* PROMISES: initializes all member vars to given time in seconds
       REQUIRES: positive integer. negative integer will do nothing.*/
    Clock(int time){sec_to_hms(time);}
    /* PROMISES: initializes all member vars to given time.
        If invalid time is provided then time will be set to 00:00:00
        REQUIRES: int hour, minute, and second values with valid time in 24 hour format */
    Clock(int hour, int minute, int second);
    
    /* PROMISES: Gets hour value */
    int get_hour() const {return hour;}
    /* PROMISES: Gets minute value */
    int get_minute() const {return minute;}
    /* PROMISES: Gets second value */
    int get_second() const {return second;}
    
    /* PROMISES: Sets hour value
        REQUIRES: positive integer between 0 and 23, inclusive */
    void set_hour(int hour){if(hour >= 0 && hour < 24) this->hour = hour;}
    /* PROMISES: Sets minute value
        REQUIRES: positive integer between 0 and 60, inclusive */
    void set_minute(int minute){if(minute >= 0 && minute < 60) this->minute = minute;}
    /* PROMISES: Sets second value
        REQUIRES: positive integer between 0 and 60, inclusive */
    void set_second(int second){if(second >= 0 && second < 60) this->second = second;}
    
    /* PROMISES: Increments seconds by 1. Maintains valid time. */
    void increment();
    /* PROMISES: Decrements seconds by 1. Maintains valid time. */
    void decrement();
    /* PROMISES: Increments seconds by provided int. Maintains valid time. */
    void add_seconds(int seconds);
    
private:
    /* PROMISES: Provides current time in seconds */
    inline int hms_to_sec(){return (this->hour * 3600) + (this->minute * 60) + this->second;}
    /* PROMISES: Sets current time to provided time
        REQUIRES: int time in seconds */
    void sec_to_hms(int time);
};

#endif /* lab3Clock_h */
