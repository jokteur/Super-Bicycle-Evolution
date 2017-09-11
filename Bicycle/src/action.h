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

/*  Macro to define an Action class.

    Args :
        - ACT : Class name
        - ... : Required characteristics (any number of arguments)
    Defines :
        - Constructors
            NB : The empty constructor is needed for the initialization of smart
                 pointers (unique_ptr and shared_ptr)
        - Declaration of methods that are required to be overwritten
            . toString
            . preprocess
            . enact
        - Declaration and definition of methods and fields used in registration
            . _registered
            . instanciate
            . getRequiredCaracs
*/
#define ACTION_CLASS(ACT, ...) \
class ACT : public BaseAction \
{ \
public: \
    ACT(){} ; \
    ACT(ActionParams ap):BaseAction(ap){}; \
    virtual std::string toString() ; \
    virtual void preprocess() ; \
    virtual void enact() ; \
    static bool _registered ; \
    static ACT* instanciate(ActionParams ap){return new ACT(ap) ;} ; \
    static std::vector<std::string> getRequiredCaracs() \
    { \
        std::vector<std::string> reqFields = {__VA_ARGS__} ; \
        return reqFields ; \
    }; \
};

/*  Macro to register an Action class.

    Since static fields can be initialized anywhere, this macro can be use
    anywhere as well.
*/
#define REGISTER_ACTION(ACT) \
bool ACT::_registered = BaseAction::registerAction(#ACT, \
                                                   ACT::instanciate, \
                                                   ACT::getRequiredCaracs()) ;

/*  Parameter for Action class constructors.

    Putting them as a struct allow to add/remove some without changing the code.
*/
struct ActionParams
{
    time_unit_t duration = 0 ;
    std::shared_ptr<Creature> actor ;
    std::weak_ptr<Creature> target ;
};


/*  Base class for Actions. All action classes should inherit from it.
*/
class BaseAction
{
public:
    BaseAction() ;
    BaseAction(ActionParams ap);
    virtual ~BaseAction();

    // Getters
    std::shared_ptr<Creature>& getActor(){return _actor ;} ;
    time_unit_t getDuration(){return _duration ;} ;

    // Method called when the event is added to the schedule
    virtual void preprocess(){} ;
    // Method called when the event occur
    virtual void enact(){} ;
    // String representation of the action
    virtual string toString() ;
    // Allow to print action using std::cout
    friend std::ostream& operator<< (std::ostream& out, BaseAction& action) ;

    // Factory Methods
    static bool registerAction(std::string name,
                               std::function<BaseAction*(ActionParams)> constructor,
                               std::vector<std::string> requiredCaracs) ;
    static std::unique_ptr<BaseAction> createAction(int id, ActionParams ap) ;

    // Factory fields (filled by registerAction)
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
ACTION_CLASS(Turning, "angularSpeed")
ACTION_CLASS(Eating, "eatingRange")
ACTION_CLASS(Cloning)


#endif // ACTION_H
