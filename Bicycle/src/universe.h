#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cstdint>
#include <memory>
#include <vector>

#include "creature.h"
#include "event.h"
#include "typedef.h"

class Universe
{
public:
    Universe(float sizeX, float sizeY) ;

    global_time_t getCurrentTime(){return _currentTime ;} ;

    void scheduleEvent(std::unique_ptr<Event> newEvent) ;
    void printSchedule() ;

private:
    global_time_t _currentTime ;
    std::unique_ptr<Event> _currentEvent ;

    void initialize(uint64_t numberCreatures) ;
};

#endif // UNIVERSE_H
