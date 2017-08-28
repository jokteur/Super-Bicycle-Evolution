#ifndef ACTION_H
#define ACTION_H

#include <iostream>

using namespace std ;

#include "creature.h"

class Action
{
public:
    Action();
    virtual ~Action();

    virtual string getName() ;

protected:
    string _actionName = "Base action" ;

private:
    Creature _actor ;
};

class Waiting : public Action
{
public:
    Waiting() ;
};

ostream& operator<< (ostream& out, Action& action) ;

#endif // ACTION_H
