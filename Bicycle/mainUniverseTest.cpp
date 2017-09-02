#include <iostream>
#include <typeinfo>

#include "src/action.h"
#include "src/creature.h"
#include "src/event.h"
#include "src/universe.h"

int main(int argc, char *argv[])
{
    Universe universe = Universe(100, 100) ;
    universe.printSchedule() ;

    return 0 ;
}
