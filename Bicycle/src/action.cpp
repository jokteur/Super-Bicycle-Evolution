#include "action.h"

BaseAction::BaseAction()
{
    //ctor
}

BaseAction::~BaseAction()
{
    //dtor
}

string BaseAction::getName()
{
    return _actionName ;
}

Waiting::Waiting()
{
    _actionName = "Waiting" ;
}

ostream& operator<< (ostream& out, BaseAction& action)
{
    out << action.getName() ;
    return out ;
}
