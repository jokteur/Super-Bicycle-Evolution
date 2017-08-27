#include <iostream>
#include <typeinfo>

using namespace std;

class Creature
{

};

class Event
{
  float _time ;
  Creature _actor ;
  Event* _next ;

public :
  Event(float time, Creature actor, Event* next=nullptr)
  {
    _time = time ;
    _actor = actor ;
    _next = next ;
  }

  int getScheduledTime()
  {
      return _time ;
  }

  Event getNext()
  {
      return *_next ;
  }

  Event* getNextPtr()
  {
      return _next ;
  }

  void insertNext(Event &newNext)
  {
      newNext._next = _next ;
      _next = &newNext ;
  }
} ;

void print(Event &event)
{
    cout << "Event (" << &event << ") with value " << event.getValue() << ". Next : " << event.getNextPtr() ;
}

void println(Event &event)
{
    print(event) ;
    cout << endl ;
}

int main(int argc, char *argv[])
{
    Event e1 {1} ;
    Event e2 {2} ;
    e1.insertNext(e2) ;
    println(e1) ;
    println(e2) ;

    return 0 ;
}
