#include <memory>

#include "src/universe.h"

#include "src/action.h"
#include "src/creature.h"

int main(int argc, char *argv[])
{
    Universe universe = Universe(100, 100) ;
    universe.run() ;

    return 0 ;
}
