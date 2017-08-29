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
    Event currentEvent = Event(123, attack) ;
    Event nextEvent = Event(10000, attack) ;
    currentEvent.insertEventAfter(nextEvent) ;
    cout << attack.getDesc() << endl ;
    cout << attack << endl ;
    cout << currentEvent << endl ;
    cout << nextEvent << endl ;
    return 0 ;
}
