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
    int type = static_cast<ActionType>(Random::D3()) ;
    switch(type)
    {
        case WAITING:
        {
            return make_unique<Waiting>(std::move(shared_from_this()), 10) ;
        }
        case ATTACKING:
        {
            std::shared_ptr<Creature> c = shared_from_this() ;
            return make_unique<Attacking>(std::move(shared_from_this()), c, 10) ;
        }
        case MOVING:
        {
            return make_unique<Moving>(std::move(shared_from_this()), 10) ;
        }
    }
}

ostream& operator<< (ostream& out, Creature& creature)
{
    out << "crea (" << &creature << ")" ;
    return out ;
}

