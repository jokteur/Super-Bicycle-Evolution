#include "action.h"

#include <sstream>

// Decide where to put this stuff without fucking breaking my project
string ptrToStr(void* ptr)
{
    stringstream ss ;
    ss << ptr ;
    return ss.str() ;
}

BaseAction::BaseAction()
{   }

BaseAction::BaseAction(Creature& actor)
    :_actor(&actor)
{   }

BaseAction::~BaseAction()
{   }

string BaseAction::getDesc()
{
    return "BaseAction" ;
}

string Waiting::getDesc()
{
    return "(" + ptrToStr(getPtrToActor()) + ") waiting" ;
}

Attacking::Attacking(Creature& attacker, Creature& defender)
    :BaseAction(attacker), _defender(&defender)
{   }

string Attacking::getDesc()
{
    return "(" + ptrToStr(getPtrToAttacker()) + ") attacking (" +  ptrToStr(getPtrToDefender()) + ")";
}

ostream& operator<< (ostream& out, BaseAction& action)
{
    cout << action.getDesc() ;
    return out ;
}
