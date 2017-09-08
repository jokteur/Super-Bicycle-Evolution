#include "creature.h"

#include "random.h"

Creature::Creature()
{

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

std::unique_ptr<BaseAction> Creature::chooseAction()
{
    ActionParams ap ;
    ap.duration = 10 ;
    ap.actor = std::move(shared_from_this()) ;
    return make_unique<Moving>(ap) ;
}

ostream& operator<< (ostream& out, Creature& creature)
{
    out << "crea (" << &creature << ")" ;
    return out ;
}

