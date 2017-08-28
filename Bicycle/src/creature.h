#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include "neuralsystem.h"

class Creature
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
    uint32_t _lastActionTime;
    NeuralSystem *_brain;

public:
    Creature();
    ~Creature();

    void update();
    void die();
    bool loseHP(float hp); //Returns true if the creature died
    void clone();
    void reproduce();
    void exportCreature();
    void fct();


};

#endif // CREATURE_H
