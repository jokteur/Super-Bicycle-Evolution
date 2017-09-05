#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "ANN.h"
#include "action.h"
#include "typedef.h"

class BaseAction ; // Needed to avoid circular reference

class Creature
    : public std::enable_shared_from_this<Creature>
{

private:
    //Fixed parameters
    float _attack;
    float _angularVelocity;
    float _linearVelocity;
    float _decisionSpeed;
    float _visionArc;
    float _visionDist;
    float _interactionDist;

    //Changing parameters
    float _maxHP;
    float _HP;

    //Other parameters
    global_time_t _lastActionTime;
    ANN *_brain;

public:
    Creature();
    virtual ~Creature();

    void update();
    void die();
    bool loseHP(float hp); //Returns true if the creature died
    void clone();
    void reproduce();
    void exportCreature();
    void fct();

    std::unique_ptr<BaseAction> chooseAction() ;

    friend ostream& operator<< (ostream& out, Creature& creature) ;
};

#endif // CREATURE_H
