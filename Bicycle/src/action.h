#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <memory>
#include <string>

#include "creature.h"

class BaseAction
{
public:
    BaseAction() ;
    BaseAction(std::shared_ptr<Creature> actor);
    virtual ~BaseAction();

    std::shared_ptr<Creature>& getActor(){return _actor ;} ;

    virtual string toString() ;

    friend std::ostream& operator<< (std::ostream& out, BaseAction& action) ;

protected:
    std::shared_ptr<Creature> _actor ;
};

class Waiting : public BaseAction
{
public:
    Waiting(){} ;
    Waiting(std::shared_ptr<Creature> waiter):BaseAction(std::move(waiter)){} ;

    virtual string toString() ;

};

class Attacking : public BaseAction
{
public:
    Attacking(std::shared_ptr<Creature> attacker, std::shared_ptr<Creature>& defender) ;

    std::weak_ptr<Creature>& getDefender(){return _defender;} ;

    virtual string toString() ;
protected:
    std::weak_ptr<Creature> _defender ;
};

#endif // ACTION_H
