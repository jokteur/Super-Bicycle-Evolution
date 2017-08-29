#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <cstdint>
#include <vector>

using namespace std ;

#include "creature.h"
#include "event.h"
#include "typedef.h"

typedef

class Universe
{
public:
    Universe(float sizeX, float sizeY) ;

    global_time_t getCurrentTime(){return _currentTime ;} ;
    Event getCurrentEvent(){return _currentEvent ;} ;

private:
    global_time_t _currentTime ;
    Event _currentEvent ;
    vector<Creature> _creatures ;

    void initialize(uint64_t numberCreatures) ;
};

#endif // UNIVERSE_H
