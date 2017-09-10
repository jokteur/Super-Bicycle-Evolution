#include "universe.h"
#include "random.h"

Universe::Universe(float sizeX, float sizeY)
    :_currentTime(0), _currentEvent(nullptr)
{
    Random::init() ;
    init_creatures(N_CREATURES) ;
}

void Universe::printSchedule()
{
    // We use pointer to unique_ptr since we do not want to move the unique_ptr
    std::unique_ptr<Event>* ptr = &_currentEvent ;
    while (*ptr != nullptr)
    {
        cout << *(*ptr) << endl ;
        ptr = &((*ptr)->getNextEvent()) ;
    }
}


void Universe::run()
{
    while (_currentEvent != nullptr and _currentTime < MAX_TIME)
    {
        cout << *_currentEvent << endl ;
        _currentEvent->realise() ;
        _currentEvent = std::move(_currentEvent->getNextEvent()) ;
        _currentTime = _currentEvent->getScheduledTime() ;
        auto actingCreature = _currentEvent->getAction()->getActor() ;
        auto newAction = actingCreature->chooseAction() ;
        scheduleAction(std::move(newAction)) ;
    }
}


void Universe::scheduleAction(std::unique_ptr<BaseAction> newAction)
{
    // Use of pointer to unique_ptr because moving unique_ptr them is scary.
    std::unique_ptr<Event>* prePtr = &_currentEvent ;
    std::unique_ptr<Event>* postPtr = &(_currentEvent->getNextEvent()) ;
    auto newEvent = std::make_unique<Event>(newAction->getDuration() + _currentTime, std::move(newAction)) ;
    time_unit_t newTime = newEvent->getScheduledTime() ;

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


void Universe::init_creatures(uint64_t numberCreatures)
{
    for (uint64_t i = 0 ; i < numberCreatures ; ++i)
    {
        auto newCreature = std::make_shared<Creature>() ;
        ActionParams ap ;
        ap.duration = i ;
        ap.actor = newCreature ;
        // All creatures are start by waiting
        auto initialWaiting = std::make_unique<Waiting>(ap) ;
        if (i == 0)
        {
            _currentEvent = std::make_unique<Event>(i, std::move(initialWaiting)) ;
        }
        else
        {
            scheduleAction(std::move(initialWaiting)) ;
        }
    }
}
