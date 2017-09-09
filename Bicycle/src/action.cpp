#include "action.h"

#include <sstream>

// Initialization of static vectors
std::vector<std::function<BaseAction*(ActionParams)>> BaseAction::_actionConstructors ;
std::vector<std::string> BaseAction::_actionNames ;


BaseAction::BaseAction(){}


BaseAction::BaseAction(ActionParams ap)
    : _duration(ap.duration), _actor(std::move(ap.actor)), _target(ap.target)
{   }


BaseAction::~BaseAction(){}


std::string BaseAction::toString()
{
    return "Base action" ;
} ;


bool BaseAction::registerAction(std::string name,
                                std::function<BaseAction*(ActionParams)> constructor,
                                std::vector<std::string> requiredCaracs)
{
    BaseAction::_actionNames.push_back(name) ;
    BaseAction::_actionConstructors.push_back(constructor) ;
    for (auto name : requiredCaracs)
        Creature::addCarac(name) ;
    return true ;
}


std::unique_ptr<BaseAction> BaseAction::createAction(int id, ActionParams ap)
{
    std::unique_ptr<BaseAction> newptr(BaseAction::_actionConstructors[id](ap)) ;
    return newptr ;
}


std::ostream& operator<< (std::ostream& out, BaseAction& action)
{
    // Calling toString avoids problem with subclass of BaseAction
    cout << action.toString() ;
    return out ;
}



std::string Waiting::toString()
{
    // stringstream allow to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " waiting" ;
    return ss.str() ;
}

void Waiting::preprocess()
{

}


void Waiting::enact()
{

}


std::string Attacking::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " attacking " << *static_cast<shared_ptr<Creature>>(_target) ;
    return ss.str() ;
}


void Attacking::preprocess()
{

}


void Attacking::enact()
{

}


std::string Moving::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " moving to 'some position'" ;
    return ss.str() ;
}


void Moving::preprocess()
{

}


void Moving::enact()
{
    Vector2f diff = _actor->getCarac("linearSpeed")*_duration*_actor->getDir() ;
    _actor->setPos(_actor->getPos() + diff) ;
}

