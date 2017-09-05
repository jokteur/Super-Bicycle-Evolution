#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cstdint>
#include <memory>
#include <random>
#include <vector>

#include "creature.h"
#include "event.h"
#include "typedef.h"

const uint64_t N_CREATURES = 10 ;
const float MAX_TIME = 100 ;

class Universe
{
public:
    Universe(float sizeX, float sizeY) ;

    global_time_t getCurrentTime(){return _currentTime ;} ;

    void printSchedule() ;
    void run() ;
    void scheduleAction(std::unique_ptr<BaseAction> newAction) ;

private:
    global_time_t _currentTime ;
    std::unique_ptr<Event> _currentEvent ;

    void init_creatures(uint64_t numberCreatures) ;
};

#endif // UNIVERSE_H
