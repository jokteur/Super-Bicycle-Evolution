#include "universe.h"

const int N_CREATURES = 10 ;

Universe::Universe(float sizeX, float sizeY)
    :_currentTime(0), _currentEvent(nullptr)
{
    for (int i = 0 ; i < N_CREATURES ; ++i)
    {
        Creature newCreature = Creature() ;
        _creatures.push_back(newCreature) ;
        Waiting initialWaiting = Waiting(newCreature) ;
        Event initialEvent = Event(i, initialWaiting) ;
        if (i == 0)
        {
            _currentEvent = initialEvent ;
        }
        else
        {
            scheduleEvent(initialEvent) ;
        }
    }

    cout << *_currentEvent << endl ;
    Event* next = _currentEvent->getPtrToNext() ;
    while (next != nullptr && false)
    {
        cout << *next << endl ;
        next = next->getPtrToNext() ;
    }
}

void Universe::scheduleEvent(Event* newEvent)
{
    global_time_t newTime = newEvent->getScheduledTime() ;
    Event* lastEvent = _currentEvent ;
    Event* testedEvent = _currentEvent->getPtrToNext() ;

    cout << testedEvent << endl ;

    if (testedEvent != nullptr)
    {
        while (newTime > testedEvent->getScheduledTime())
        {
            lastEvent = testedEvent ;
            testedEvent = lastEvent->getPtrToNext() ;
        }
    }

    lastEvent->insertEventAfter(newEvent) ;
}
