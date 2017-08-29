#include <iostream>
#include <typeinfo>

#include "src/event.h"
#include "src/action.h"

using namespace std ;

int main(int argc, char *argv[])
{
    BaseAction act = BaseAction() ;
    Waiting wait = Waiting() ;
    Event event = Event(12, wait) ;
    Event event2 = Event(33, act) ;
    event.insertNextEvent(event2) ;
    cout << event << endl ;
    cout << event.getNextEvent() ;
    return 0 ;
}
