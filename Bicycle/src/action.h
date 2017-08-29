#ifndef ACTION_H
#define ACTION_H

#include <iostream>

using namespace std ;

#include "creature.h"

class BaseAction
{
public:
    BaseAction();
    virtual ~BaseAction();

    virtual string getName() ;

protected:
    string _actionName = "Base action" ;

private:
    Creature _actor ;
};

class Waiting : public BaseAction
{
public:
    Waiting() ;
};

ostream& operator<< (ostream& out, BaseAction& action) ;

#endif // ACTION_H
