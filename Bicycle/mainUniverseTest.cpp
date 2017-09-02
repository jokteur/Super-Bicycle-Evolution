#include <iostream>
#include <typeinfo>

#include "src/action.h"
#include "src/creature.h"
#include "src/event.h"

int main(int argc, char *argv[])
{
    auto c = std::make_shared<Creature>() ;
    auto c1 = std::make_shared<Creature>() ;
    auto c2 = std::make_shared<Creature>() ;
    auto act = std::make_unique<BaseAction>() ;
    auto attack = std::make_unique<Attacking>(std::move(c1), c2) ;
    auto wait = std::make_unique<Waiting>(std::move(c)) ;
    auto event = std::make_unique<Event>(123, std::move(wait)) ;
    auto event2 = std::make_unique<Event>(223, std::move(attack)) ;
    event->insertEventAfter(std::move(event2)) ;
    std::cout << *event << endl ;
    std::cout << *(event->getNextEvent()) << endl ;

    return 0 ;
}
