#include "action.h"

#include <sstream>

// Initialization of static vectors
std::vector<std::function<BaseAction*(ActionParams)>> BaseAction::_actionConstructors ;
std::vector<std::string> BaseAction::_actionNames ;

ActionConstructor::ActionConstructor(std::string name,
                                     std::function<BaseAction*(ActionParams)> constructor,
                                     std::vector<std::string> caracNames)
{
    BaseAction::_actionNames.push_back(name) ;
    BaseAction::_actionConstructors.push_back(constructor) ;
}


BaseAction::BaseAction()
{   }


BaseAction::BaseAction(ActionParams ap)
    : _duration(ap.duration), _actor(std::move(ap.actor)), _target(ap.target)
{   }


BaseAction::~BaseAction()
{   }


string BaseAction::toString()
{
    return "Base action" ;
} ;


std::unique_ptr<BaseAction> BaseAction::createAction(int id, ActionParams ap)
{
    std::unique_ptr<BaseAction> newptr(BaseAction::_actionConstructors[id](ap)) ;
    return newptr ;
}


string Waiting::toString()
{
    // stringstream allow to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << ") waiting" ;
    return ss.str() ;
}

string Attacking::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " attacking " << *static_cast<shared_ptr<Creature>>(_target) ;
    return ss.str() ;
}

string Moving::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " moving to 'some position'" ;
    return ss.str() ;
}

std::ostream& operator<< (std::ostream& out, BaseAction& action)
{
    // Calling toString avoids problem with subclass of BaseAction
    cout << action.toString() ;
    return out ;
}

