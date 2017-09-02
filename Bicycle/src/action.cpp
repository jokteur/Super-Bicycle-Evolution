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


string Waiting::toString()
{
    std::stringstream ss ;
    ss << *_actor << ") waiting" ;
    return ss.str() ;
}

Attacking::Attacking(std::shared_ptr<Creature> attacker, std::shared_ptr<Creature>& defender)
    :BaseAction(std::move(attacker)), _defender(defender)
{   }

string Attacking::toString()
{
    std::stringstream ss ;
    ss << *_actor << " attacking " << *static_cast<shared_ptr<Creature>>(_defender) ;
    return ss.str() ;
}

std::ostream& operator<< (std::ostream& out, BaseAction& action)
{
    cout << action.toString() ;
    return out ;
}

