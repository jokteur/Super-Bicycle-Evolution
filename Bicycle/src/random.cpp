#include "Random.h"

Random::Random()
{

}

Random::~Random()
{
    //dtor
}

std::uniform_int_distribution<> Random::_d3 ;
std::mt19937 Random::_rng ;
std::normal_distribution<> Random::_N ;

void Random::init()
{
    _rng.seed(std::random_device()()) ;
    _d3 = std::uniform_int_distribution<>(0, 2) ;
    _N = std::normal_distribution<>(0, 1) ;
}

