#include "Random.h"

Random::Random()
{

}

Random::~Random()
{
    //dtor
}

std::uniform_int_distribution<> Random::_d6 ;
std::mt19937 Random::_rng ;
std::normal_distribution<> Random::_N ;

void Random::init()
{
    _rng.seed(std::random_device()()) ;
    _d6 = std::uniform_int_distribution<>(0, 5) ;
    _N = std::normal_distribution<>(0, 1) ;
}

