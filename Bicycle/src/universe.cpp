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
        auto actingCreature = _currentEvent->getAction()->getActor() ;
        _currentEvent = std::move(_currentEvent->getNextEvent()) ;
        _currentTime = _currentEvent->getScheduledTime() ;
        auto newAction = actingCreature->chooseAction() ;
        scheduleAction(std::move(newAction)) ;
    }
}

void Universe::scheduleAction(std::unique_ptr<BaseAction> newAction)
{
    std::unique_ptr<Event>* prePtr = &_currentEvent ;
    std::unique_ptr<Event>* postPtr = &(_currentEvent->getNextEvent()) ;
    auto newEvent = std::make_unique<Event>(newAction->getDuration() + _currentTime, std::move(newAction)) ;
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

void Universe::init_creatures(uint64_t numberCreatures)
{
    for (int i = 0 ; i < numberCreatures ; ++i)
    {
        auto newCreature = std::make_shared<Creature>() ;
        auto initialWaiting = std::make_unique<Waiting>(std::move(newCreature), i) ;
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
