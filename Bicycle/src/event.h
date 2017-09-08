#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "action.h"
#include "typedef.h"

class BaseAction ; // Needed to avoid circular reference

class Event
{
public:
    Event() ;
    Event(time_unit_t time,
          std::unique_ptr<BaseAction> action,
          std::unique_ptr<Event> next = nullptr) ;
    virtual ~Event() ;

    // Getters
    time_unit_t getScheduledTime(){return _time ;} ;
    std::unique_ptr<BaseAction>& getAction(){return _action ;} ;
    std::unique_ptr<Event>& getNextEvent(){return _next ;} ;

    void insertEventAfter(std::unique_ptr<Event> newNext) ;
    void realise() {} ;

    friend std::ostream& operator<< (std::ostream& out, Event& event) ;

private:
    time_unit_t _time ;
    std::unique_ptr<BaseAction> _action ;
    std::unique_ptr<Event> _next ;
};

#endif // EVENT_H
