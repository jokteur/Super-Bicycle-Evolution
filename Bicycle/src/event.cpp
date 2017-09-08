#include "event.h"

Event::Event()
{   }

Event::Event(time_unit_t time, std::unique_ptr<BaseAction> action, std::unique_ptr<Event> next)
    :_time(time),
     _action(std::move(action)),
     _next(std::move(next))
{   }

Event::~Event()
{   }

void Event::insertEventAfter(std::unique_ptr<Event> newNext)
{
      newNext->_next = std::move(_next) ;
      _next = std::move(newNext) ;
}

std::ostream& operator<< (std::ostream& out, Event& event)
{
    out << event._time << " : (" << &event << ") scheduling [" << *event._action << "]." ;
    out << " Followed by (" << event._next.get() << ")." ;
    return out ;
}
