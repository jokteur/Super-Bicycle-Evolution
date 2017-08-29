#ifndef ACTION_H
#define ACTION_H

#include <iostream>

using namespace std ;

#include "creature.h"

class BaseAction
{
public:
    BaseAction() ;
    BaseAction(Creature& actor);
    virtual ~BaseAction();

    virtual string getDesc() ;

protected:
    Creature _actor ;
};

class Waiting : public BaseAction
{   };

class Attacking : public BaseAction
{
public:
    Attacking(Creature& attacker, Creature& defender) ;

    Creature getAttacker(){return _actor ;} ;
    Creature getDefender(){return _defender;} ;

    virtual string getDesc() ;

protected:
    Creature _defender ;
};

ostream& operator<< (ostream& out, BaseAction& action) ;

#endif // ACTION_H
