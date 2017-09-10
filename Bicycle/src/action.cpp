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
    return "Base action [SHOULD NOT BE INSTANCIATED !]" ;
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
    // Calling toString allow to define the method once for all actions
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
    ss << *_actor << " moving forward" ;
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

std::string Turning::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " turning" ;
    return ss.str() ;
}


void Turning::preprocess()
{

}


void Turning::enact()
{

}

std::string Eating::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " eating apples" ;
    return ss.str() ;
}


void Eating::preprocess()
{

}


void Eating::enact()
{

}

std::string Cloning::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " cloning itself" ;
    return ss.str() ;
}


void Cloning::preprocess()
{

}


void Cloning::enact()
{

}

