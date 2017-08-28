#include "action.h"

Action::Action()
{
    //ctor
}

Action::~Action()
{
    //dtor
}


virtual string Action::getName()
{
    return _actionName ;
}

Waiting::Waiting()
{
    _actionName = "Waiting" ;
}

ostream& operator<< (ostream& out, Action& action)
{
    out << action.getName() ;
    return out ;
}
