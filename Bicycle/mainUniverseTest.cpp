#include <iostream>
#include <typeinfo>

#include "src/action.h"
#include "src/creature.h"
#include "src/event.h"

using namespace std ;

int main(int argc, char *argv[])
{
    Creature c = Creature() ;
    Creature c2 = Creature() ;
    Attacking attack = Attacking(c, c2) ;
    Attacking attack2 = Attacking(c2, c) ;
    Waiting w = Waiting(c) ;
    Event currentEvent = Event(123, attack) ;
    Event nextEvent = Event(10000, attack2) ;
    Event midEvent = Event(155, w) ;
    currentEvent.insertEventAfter(nextEvent) ;
    currentEvent.insertEventAfter(midEvent) ;

    cout << currentEvent << endl ;
    cout << midEvent << endl ;
    cout << nextEvent << endl ;
    return 0 ;
}
