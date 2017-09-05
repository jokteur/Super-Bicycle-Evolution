#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <memory>
#include <string>

#include "creature.h"
#include "typedef.h"

class Creature ; // Needed to avoid circular reference

class BaseAction
{
public:
    BaseAction() ;
    BaseAction(std::shared_ptr<Creature> actor,
               global_time_t duration);
    virtual ~BaseAction();

    std::shared_ptr<Creature>& getActor(){return _actor ;} ;
    global_time_t getDuration(){return _duration ;} ;

    // Method called when the event is added to the schedule
    virtual void preprocess(){} ;
    // Method called when the event occur
    virtual void enact(){} ;
    virtual string toString() ;

    friend std::ostream& operator<< (std::ostream& out, BaseAction& action) ;

protected:
    std::shared_ptr<Creature> _actor ;
    global_time_t _duration ;
};

class Waiting : public BaseAction
{
public:
    Waiting(std::shared_ptr<Creature> actor,
            global_time_t duration);

    virtual string toString() ;

};

class Attacking : public BaseAction
{
public:
    Attacking(std::shared_ptr<Creature> attacker,
              std::shared_ptr<Creature>& defender,
              global_time_t duration) ;

    std::weak_ptr<Creature>& getDefender(){return _defender;} ;

    virtual string toString() ;
protected:
    std::weak_ptr<Creature> _defender ;
};

class Moving : public BaseAction
{
public:
    Moving(std::shared_ptr<Creature> actor,
           global_time_t duration) ;

    virtual string toString() ;
};

enum ActionType
{
    WAITING,
    ATTACKING,
    MOVING,
    N_ACTION_TYPES
};

#endif // ACTION_H
