#include "event.h"

Event::Event()
{   }

Event::Event(global_time_t time, BaseAction& action, Event* next)
    :_time(time), _action(action), _next(next)
{   }

void Event::insertEventAfter(Event& newNext)
{
      newNext._next = _next ;
      _next = &newNext ;
}

ostream& operator<< (ostream& out, Event& event)
{
    out << "Event (" << &event << ") scheduling [" << event.getAction() << "] at time " << event.getScheduledTime() << ". " ;
    out << "Next event : " << event.getPtrToNext() ;
    return out ;
}
