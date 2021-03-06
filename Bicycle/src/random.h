#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <random>

class Random
{
public:
    Random();
    virtual ~Random();

    static void init() ;

    static float normal(){return _N(_rng) ;} ;
    static float D6(){return _d6(_rng) ;} ;

protected:

private:
    static int k ;
    static std::uniform_int_distribution<> _d6 ;
    static std::mt19937 _rng ;
    static std::normal_distribution<> _N ;
};

#endif // RANDOM_H
