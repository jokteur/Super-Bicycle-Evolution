#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cstdint>
#include <memory>
#include <random>
#include <vector>

#include "creature.h"
#include "event.h"
#include "typedef.h"

// Number of creature at the beginning of a simulation
const uint64_t N_CREATURES = 10 ;
// Simulation stops when this time is reached
const time_unit_t MAX_TIME = 30 ;

class Universe
{
public:
    Universe(float sizeX, float sizeY) ;

    time_unit_t getCurrentTime(){return _currentTime ;} ;

    // Print all scheduled events
    void printSchedule() ;
    void run() ;
    void scheduleAction(std::unique_ptr<BaseAction> newAction) ;

private:
    time_unit_t _currentTime ;
    std::unique_ptr<Event> _currentEvent ;

    void init_creatures(uint64_t numberCreatures) ;
};

#endif // UNIVERSE_H
