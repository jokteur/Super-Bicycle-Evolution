#include "action.h"

#include <sstream>

BaseAction::BaseAction()
{   }

BaseAction::BaseAction(std::shared_ptr<Creature> actor,
                       global_time_t duration)
    :_actor(std::move(actor)), _duration(duration)
{   }

BaseAction::~BaseAction()
{   }

string BaseAction::toString()
{
    return "Base action" ;
} ;

Waiting::Waiting(std::shared_ptr<Creature> actor, global_time_t duration)
    :BaseAction(std::move(actor), duration)
{   }

string Waiting::toString()
{
    // stringstream allow to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << ") waiting" ;
    return ss.str() ;
}

Attacking::Attacking(std::shared_ptr<Creature> attacker,
                     std::shared_ptr<Creature>& defender,
                     global_time_t duration)
    :BaseAction(std::move(attacker), duration), _defender(defender)
{   }

string Attacking::toString()
{
    // stringstream allows to use the << operator defined for Creature
    std::stringstream ss ;
    ss << *_actor << " attacking " << *static_cast<shared_ptr<Creature>>(_defender) ;
    return ss.str() ;
}

Moving::Moving(std::shared_ptr<Creature> actor, global_time_t duration)
    :BaseAction(std::move(actor), duration)
{   }

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

