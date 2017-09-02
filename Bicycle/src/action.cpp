#include "action.h"

#include <sstream>

BaseAction::BaseAction()
{   }

BaseAction::BaseAction(std::shared_ptr<Creature> actor)
    :_actor(std::move(actor))
{   }

BaseAction::~BaseAction()
{   }

string BaseAction::toString()
{
    return "Base action" ;
} ;

Waiting::Waiting(std::shared_ptr<Creature> waiter)
    :BaseAction(std::move(waiter))
{

}

string Waiting::toString()
{
    // stringstream allow to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << ") waiting" ;
    return ss.str() ;
}

Attacking::Attacking(std::shared_ptr<Creature> attacker, std::shared_ptr<Creature>& defender)
    :BaseAction(std::move(attacker)), _defender(defender)
{   }

string Attacking::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " attacking " << *static_cast<shared_ptr<Creature>>(_defender) ;
    return ss.str() ;
}

std::ostream& operator<< (std::ostream& out, BaseAction& action)
{
    // Calling toString avoids problem with subclass of BaseAction
    cout << action.toString() ;
    return out ;
}

