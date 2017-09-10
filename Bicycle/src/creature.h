#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include <Eigen/Dense>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "ANN.h"
#include "action.h"
#include "typedef.h"

/*  Easy setter and getter creation, as well as private field creation.

    The drawback is that the private field start with a capital letter.
*/
#define GETSET(type, param) \
private: \
    type _##param ; \
public: \
    type get##param(){return _##param ;} ; \
    void set##param(type newVal){_##param = newVal ;} ;

class BaseAction ; // Needed to avoid circular reference

/*  Creature class

    Inheriting from enable_shared_from_this allows to return shared_ptr from
    an instance to itself.
*/
class Creature
    : public std::enable_shared_from_this<Creature>
{

private:
    /*  General fixed parameters

        These parameters are fixed and do not depend on an action.
        It may be interesting to create a class to handle the "senses" of the
        creatures, as it would allows several different senses.
    */
    float _visionArc ;
    float _visionDist ;
    float _decisionSpeed ;
    ANN *_brain;

    /*  Action specific (fixed) parameters (aka Carac)

        These parameters are tied to an action and are added when the action is
        registered using REGISTER_ACTION.
    */
    std::unordered_map<std::string, float> _caracs ;
    static std::vector<std::string> _caracNames ;

    /*  General variable parameters

        These parameters do not depend on an action and change during the life
        of a creature.
    */
    time_unit_t _lastActionTime;
    GETSET(float, _maxHP)
    GETSET(float, HP)
    GETSET(Vector2f, Pos)
    GETSET(Vector2f, Dir)

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

    static void addCarac(std::string name) ;
    float getCarac(std::string name) ;
    std::unique_ptr<BaseAction> chooseAction() ;

    friend ostream& operator<< (ostream& out, Creature& creature) ;
};

#undef GETSET

#endif // CREATURE_H
