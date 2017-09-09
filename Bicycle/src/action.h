#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "creature.h"
#include "typedef.h"

// Needed to avoid circular reference
class BaseAction ;
class Creature ;

#define ACTION_CLASS(ACT, ...) \
class ACT : public BaseAction \
{ \
public: \
    ACT(){} ; \
    ACT(ActionParams ap):BaseAction(ap){}; \
    virtual std::string toString() ; \
    virtual void preprocess() ; \
    virtual void enact() ; \
    static ACT* instanciate(ActionParams ap){return new ACT(ap) ;} ; \
    static bool _registered ; \
    static std::vector<std::string> getRequiredCaracs() \
    { \
        std::vector<std::string> reqFields = {__VA_ARGS__} ; \
        return reqFields ; \
    }; \
};

#define REGISTER_ACTION(ACT) \
bool ACT::_registered = BaseAction::registerAction(#ACT, ACT::instanciate, ACT::getRequiredCaracs()) ;

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
    static bool registerAction(std::string name,
                               std::function<BaseAction*(ActionParams)> constructor,
                               std::vector<std::string> requiredCaracs) ;
    static std::unique_ptr<BaseAction> createAction(int id, ActionParams ap) ;

    static std::vector<std::function<BaseAction*(ActionParams)>> _actionConstructors ;
    static std::vector<std::string> _actionNames ;

protected:
    time_unit_t _duration ;
    std::shared_ptr<Creature> _actor ;
    std::weak_ptr<Creature> _target ;
};


ACTION_CLASS(Waiting)
ACTION_CLASS(Attacking, "attack")
ACTION_CLASS(Moving, "linearSpeed")

#endif // ACTION_H
