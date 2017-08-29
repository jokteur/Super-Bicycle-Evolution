#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <iostream>

using namespace std ;

#include "action.h"
#include "creature.h"
#include "typedef.h"

class Event
{
public:
    Event() ;
    Event(global_time_t time, BaseAction& action, Event* next=nullptr) ;

    // Getters
    global_time_t getScheduledTime(){return _time ;} ;
    BaseAction& getAction(){return _action ;} ;
    Event& getNextEvent(){return *_next ;} ;
    Event* getPtrToNext(){return _next ;} ;

    void insertEventAfter(Event &newNext) ;

private:
    global_time_t _time ;
    BaseAction _action ;
    Event* _next ;
};

ostream& operator<< (ostream& out, Event& event) ;

#endif // EVENT_H
