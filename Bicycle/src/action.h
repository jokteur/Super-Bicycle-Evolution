#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "creature.h"
#include "typedef.h"

// Needed to avoid circular reference
class Creature ;

#define REGISTER(ACT) \
    ACT(){} ; \
    ACT(ActionParams ap) \
        :BaseAction(ap)\
    { \
        static bool registered = false ; \
        if (!registered){registerSelf() ; registered = true ;} \
    }; \
    static ACT* instanciate(){return new ACT() ;} ; \
    virtual void registerSelf(){BaseAction::registerAction(#ACT, ACT::instanciate) ;} ;


struct ActionParams
{
    time_unit_t duration = 0 ;
    std::shared_ptr<Creature> actor ;
    std::weak_ptr<Creature> target ;
};

class BaseAction
{
public:
    BaseAction() ;
    BaseAction(ActionParams ap);
    virtual ~BaseAction();

    std::shared_ptr<Creature>& getActor(){return _actor ;} ;
    time_unit_t getDuration(){return _duration ;} ;

    // Method called when the event is added to the schedule
    virtual void preprocess(){} ;
    // Method called when the event occur
    virtual void enact(){} ;
    virtual string toString() ;

    friend std::ostream& operator<< (std::ostream& out, BaseAction& action) ;

    // Factory Methods
    static std::unique_ptr<BaseAction> createAction(int id) ;
    static void registerAction(std::string name, std::function<BaseAction*()> constructor) ;

    static std::vector<std::function<BaseAction*()>> _actionConstructors ;
    static std::vector<std::string> _actionNames ;

protected:
    time_unit_t _duration ;
    std::shared_ptr<Creature> _actor ;
    std::weak_ptr<Creature> _target ;

    virtual void registerSelf(){} ;
};


class Waiting : public BaseAction
{
public:
    virtual string toString() ;

    REGISTER(Waiting)
};

class Attacking : public BaseAction
{
public:
    virtual string toString() ;

    REGISTER(Attacking)
};


class Moving : public BaseAction
{
public:
    virtual string toString() ;

    REGISTER(Moving)
};


#endif // ACTION_H
