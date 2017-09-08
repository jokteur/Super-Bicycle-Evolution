#include <vector>

#include "src/universe.h"

#include <functional>
#include <memory>
#include <iostream>

int main(int argc, char *argv[])
{
    Universe universe = Universe(100, 100) ;
    universe.run() ;

    cout << BaseAction::_actionNames.size() << endl ;

    for (auto name : BaseAction::_actionNames)
    {
        cout << name << endl ;
    }

    return 0 ;
}
