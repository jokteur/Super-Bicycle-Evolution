#include <iostream>
#include <typeinfo>

using namespace std;

class Creature
{

};

class Action
{
protected:
    string _actionName = "Base action" ;
    Creature _actor ;

public:
    virtual string getName()
    {
        return _actionName ;
    }
};

class Waiting : public Action
{
public:
    Waiting()
    {
        _actionName = "Waiting" ;
    }
};

ostream& operator<< (ostream& out, Action& action)
{
    out << action.getName() ;
    return out ;
}


class Event
{
  float _time ;
  Action _action ;
  Event* _next ;

public :
  Event(float time, Action& action, Event* next=nullptr)
  {
    _time = time ;
    _action = action ;
    _next = next ;
  }

  float getScheduledTime()
  {
      return _time ;
  }

  Action& getAction()
  {
      return _action ;
  }

  Event& getNext()
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

ostream& operator<< (ostream& out, Event& event)
{
    out << "Event (" << &event << ") schedules [" << event.getAction() << "] at time " << event.getScheduledTime() << ". " ;
    out << "Next event : " << event.getNextPtr() ;
    return out ;
}

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
