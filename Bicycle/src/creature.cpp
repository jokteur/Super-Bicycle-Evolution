#include "creature.h"

#include "random.h"


std::vector<std::string> Creature::_caracNames ;

Creature::Creature()
{
    _Pos.setRandom() ;
    _Dir.setRandom() ; // TODO Normalize to 1

    for (auto name : Creature::_caracNames)
        _caracs[name] = 1 ; // TODO Randomize the initialization
}

//Destructor
Creature::~Creature()
{

}

void Creature::update()
{

}

void Creature::die()
{

}

bool Creature::loseHP(float hp)
{
	return false;
}

void Creature::clone()
{

}

void Creature::reproduce()
{

}

void Creature::exportCreature()
{

}

void Creature::addCarac(std::string name)
{
    Creature::_caracNames.push_back(name) ;
}


float Creature::getCarac(std::string name)
{
    return _caracs[name] ;
}

/*  Return the action chosen by the creature

    Actually simply chose one randomly and put a duration of 10 for it.
    Also the target of an action is always itself.
*/
std::unique_ptr<BaseAction> Creature::chooseAction()
{
    ActionParams ap ;
    ap.duration = 10 ;
    ap.actor = std::move(shared_from_this()) ;
    ap.target = shared_from_this() ;
    return BaseAction::createAction(Random::D6(), ap) ;
}

ostream& operator<< (ostream& out, Creature& creature)
{
    out << "crea (" << &creature << ")" ;
    return out ;
}

