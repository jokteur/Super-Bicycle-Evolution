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

#define GETSET(type, param) \
private: \
    type _##param ; \
public: \
    type get##param(){return _##param ;} ; \
    void set##param(type newVal){_##param = newVal ;} ;

class BaseAction ; // Needed to avoid circular reference

class Creature
    : public std::enable_shared_from_this<Creature>
{

private:
    //General fixed parameters
    float _visionArc ;
    float _visionDist ;
    float _decisionSpeed ;
    ANN *_brain;

    //Action specific parameters
    std::unordered_map<std::string, float> _actionParams ;
    static std::vector<std::string> _paramNames ;

    //General variable parameters
    time_unit_t _lastActionTime;
    float _maxHP ;
    GETSET(Vector2f, Pos)
    GETSET(Vector2f, Dir)
    GETSET(float, HP)

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
