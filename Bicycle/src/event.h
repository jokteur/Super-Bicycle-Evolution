#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std ;

#include "action.h"
#include "creature.h"

class Event
{
public:
    Event(float time, BaseAction& action, Event* next=nullptr) ;

    float getScheduledTime() ;
    BaseAction& getAction() ;
    Event& getNextEvent() ;
    Event* getPtrToNext() ;
    void insertNextEvent(Event &newNext) ;

private:
    float _time ;
    BaseAction _action ;
    Event* _next ;
};

ostream& operator<< (ostream& out, Event& event) ;

#endif // EVENT_H
