#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include "neuralsystem.h"

class Creature
{
private:
    //Fixed parameters
    float m_attack;
    float m_angularVelocity;
    float m_linearVelocity;
    float m_decisionSpeed;
    float m_visionArc;
    float m_visionDist;
    float m_interactionDist;

    //Changing parameters
    float m_maxHP;
    float m_HP;

    //Other parameters
    uint32_t m_lastActionTime;
    NeuralSystem m_brain;

public:
    Creature();
    ~Creature();

    void update();
    void die();
    bool loseHP(float hp); //Returns true if the creature died
    void clone();
    void reproduce();
    void exportCreature();


};

#endif // CREATURE_H
