#include <vector>

#include "src/universe.h"

#include <functional>
#include <memory>
#include <iostream>


REGISTER_ACTION(Waiting)
REGISTER_ACTION(Moving)
REGISTER_ACTION(Attacking)
REGISTER_ACTION(Turning)
REGISTER_ACTION(Eating)
REGISTER_ACTION(Cloning)

int main(int argc, char *argv[])
{
    Universe universe = Universe(100, 100) ;
    universe.run() ;

    return 0 ;
}
