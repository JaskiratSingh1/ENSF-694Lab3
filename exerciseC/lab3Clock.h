//
//  lab3Clock.h
//  ENSF-694Lab3
//
//  Created by Jaskirat Singh on 2024-07-16.
//

#ifndef lab3Clock_h
#define lab3Clock_h

using namespace std;

class Clock{
    int hour;
    int minute;
    int second;
    
public:
    Clock(){hour = minute = second = 0;}
    Clock(int time){sec_to_hms(time);}
    Clock(int hour, int minute, int second);
    
    int get_hour() const {return hour;}
    int get_minute() const {return minute;}
    int get_second() const {return second;}
    
    void set_hour(int hour){if(hour >= 0 && hour < 24) this->hour = hour;}
    void set_minute(int minute){if(minute >= 0 && minute < 60) this->minute = minute;}
    void set_second(int second){if(second >= 0 && second < 60) this->second = second;}
    
    void increment();
    void decrement();
    void add_seconds(int seconds);
    
private:
    int hms_to_sec(){return (this->hour * 3600) + (this->minute * 60) + this->second;}
    void sec_to_hms(int time);
};

#endif /* lab3Clock_h */
