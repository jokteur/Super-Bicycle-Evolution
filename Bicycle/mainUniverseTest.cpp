#include <vector>

#include "src/universe.h"

#include <functional>
#include <memory>
#include <iostream>


REGISTER_ACTION(Waiting)
REGISTER_ACTION(Moving)
REGISTER_ACTION(Attacking)

#define TEST(...) std::vector<std::string> reqFields = {__VA_ARGS__} ;


int main(int argc, char *argv[])
{
    Universe universe = Universe(100, 100) ;
    universe.run() ;

    cout << BaseAction::_actionNames.size() << endl ;

    for (auto name : BaseAction::_actionNames)
    {
        cout << name << endl ;
    }

    TEST()
    for (auto name : reqFields)
    {
        cout << name << endl ;
    }

    return 0 ;
}
