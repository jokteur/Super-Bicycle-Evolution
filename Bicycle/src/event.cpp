#include "event.h"

Event::Event(float time, Action& action, Event* next=nullptr)
{
    _time = time ;
    _action = action ;
    _next = next ;
}

float Event::getScheduledTime()
{
    return _time ;
}

Action& Event::getAction()
{
    return _action ;
}

Event& Event::getNextEvent()
{
    return *_next ;
}

Event* Event::getPtrToNext()
{
    return _next ;
}

void Event::insertNextEvent(Event& newNext)
{
      newNext._next = _next ;
      _next = &newNext ;
}

ostream& operator<< (ostream& out, Event& event)
{
    out << "Event (" << &event << ") schedules [" << event.getAction() << "] at time " << event.getScheduledTime() << ". " ;
    out << "Next event : " << event.getNextPtr() ;
    return out ;
}