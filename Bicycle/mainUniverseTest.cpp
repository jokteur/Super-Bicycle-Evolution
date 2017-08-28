#include <iostream>
#include <typeinfo>

#include "src/event.h"

using namespace std ;

int main(int argc, char *argv[])
{
    Action act = Action() ;
    Waiting wait = Waiting() ;
    Event event = Event(12, wait) ;
    Event event2 = Event(33, act) ;
    event.insertNext(event2) ;
    cout << event << endl ;
    cout << event.getNext() ;
    return 0 ;
}
