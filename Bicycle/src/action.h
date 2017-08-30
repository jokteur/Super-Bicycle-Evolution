#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>

using namespace std ;

#include "creature.h"

class BaseAction
{
public:
    BaseAction() ;
    BaseAction(Creature& actor);
    virtual ~BaseAction();

    Creature getActor(){return *_actor ;} ;

    Creature* getPtrToActor(){return _actor ;};

    virtual string getDesc() ;

protected:
    Creature* _actor ;
};

class Waiting : public BaseAction
{
public:
    Waiting(Creature& waiter):BaseAction(waiter) {} ;
    virtual string getDesc() ;
};

class Attacking : public BaseAction
{
public:
    Attacking(Creature& attacker, Creature& defender) ;

    Creature getAttacker(){return *_actor ;} ;
    Creature getDefender(){return *_defender;} ;

    Creature* getPtrToAttacker(){return _actor ;} ;
    Creature* getPtrToDefender(){return _defender ;} ;

    virtual string getDesc() ;

protected:
    Creature* _defender ;
};

ostream& operator<< (ostream& out, BaseAction& action) ;

#endif // ACTION_H
