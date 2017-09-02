#include "universe.h"

const int N_CREATURES = 10 ;

Universe::Universe(float sizeX, float sizeY)
    :_currentTime(0), _currentEvent(nullptr)
{
    for (int i = 0 ; i < N_CREATURES ; ++i)
    {
        auto newCreature = std::make_shared<Creature>() ;
        auto initialWaiting = std::make_unique<Waiting>(std::move(newCreature)) ;
        auto initialEvent = std::make_unique<Event>(i, std::move(initialWaiting)) ;
        if (i == 0)
        {
            _currentEvent = std::move(initialEvent) ;
        }
        else
        {
            scheduleEvent(std::move(initialEvent)) ;
        }
    }
}

void Universe::scheduleEvent(std::unique_ptr<Event> newEvent)
{
    std::unique_ptr<Event>* prePtr = &_currentEvent ;
    std::unique_ptr<Event>* postPtr = &(_currentEvent->getNextEvent()) ;
    global_time_t newTime = newEvent->getScheduledTime() ;

    while (true)
    {
        if (*postPtr == nullptr || newTime < (*postPtr)->getScheduledTime())
        {
            (*prePtr)->insertEventAfter(std::move(newEvent)) ;
            break ;
        }
        prePtr = postPtr ;
        postPtr = &((*prePtr)->getNextEvent()) ;
    }
}

void Universe::printSchedule()
{
    std::unique_ptr<Event>* ptr = &_currentEvent ;
    while (*ptr != nullptr)
    {
        cout << *(*ptr) << endl ;
        ptr = &((*ptr)->getNextEvent()) ;
    }
}
