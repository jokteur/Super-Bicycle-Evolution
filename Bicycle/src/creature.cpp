#include "creature.h"

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

ostream& operator<< (ostream& out, Creature& creature)
{
    out << "crea (" << &creature << ")" ;
    return out ;
}

