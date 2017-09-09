#include "creature.h"

#include "random.h"


std::vector<std::string> Creature::_paramNames ;

Creature::Creature()
{
    _Pos.setRandom() ;
    _Dir.setRandom() ;

    for (auto name : Creature::_paramNames)
        _actionParams[name] = 1 ;
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
    Creature::_paramNames.push_back(name) ;
}


float Creature::getCarac(std::string name)
{
    return _actionParams[name] ;
}


std::unique_ptr<BaseAction> Creature::chooseAction()
{
    ActionParams ap ;
    ap.duration = 10 ;
    ap.actor = std::move(shared_from_this()) ;
    ap.target = shared_from_this() ;
    return BaseAction::createAction(Random::D3(), ap) ;
}

ostream& operator<< (ostream& out, Creature& creature)
{
    out << "crea (" << &creature << ")" ;
    return out ;
}

