#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cstdint>
#include <vector>

#include "creature.h"
#include "event.h"
#include "typedef.h"

class Universe
{
public:
    Universe(float sizeX, float sizeY) ;

    global_time_t getCurrentTime(){return _currentTime ;} ;

    void scheduleEvent(Event* newEvent) ;

private:
    global_time_t _currentTime ;
    Event* _currentEvent ;
    std::vector<Creature> _creatures ;

    void initialize(uint64_t numberCreatures) ;
};

#endif // UNIVERSE_H
