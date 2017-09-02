#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "action.h"
#include "creature.h"
#include "typedef.h"

class Event
{
public:
    Event() ;
    Event(global_time_t time, std::unique_ptr<BaseAction> action, std::unique_ptr<Event> next = nullptr) ;

    // Getters
    global_time_t getScheduledTime(){return _time ;} ;
    std::unique_ptr<BaseAction>& getAction(){return _action ;} ;
    std::unique_ptr<Event>& getNextEvent(){return _next ;} ;

    void insertEventAfter(std::unique_ptr<Event> newNext) ;

    friend std::ostream& operator<< (std::ostream& out, Event& event) ;

private:
    global_time_t _time ;
    std::unique_ptr<BaseAction> _action ;
    std::unique_ptr<Event> _next ;
};

#endif // EVENT_H
