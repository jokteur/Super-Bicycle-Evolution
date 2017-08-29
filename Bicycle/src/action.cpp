#include "action.h"

BaseAction::BaseAction()
{   }

BaseAction::BaseAction(Creature& actor)
    :_actor(actor)
{   }

BaseAction::~BaseAction()
{   }

string BaseAction::getDesc()
{
    return "BaseAction" ;
}

Attacking::Attacking(Creature& attacker, Creature& defender)
    :BaseAction(attacker), _defender(defender)
{   }

string Attacking::getDesc()
{
    return "Fuck you base !" ;
}

ostream& operator<< (ostream& out, BaseAction& action)
{
    cout << action.getDesc() ;
    return out ;
}
