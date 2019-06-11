#ifndef UNITARYTESTSSYSTEM_H
#define UNITARYTESTSSYSTEM_H

#include "systemimpl.h"

class UnitaryTestsSystem
{
public:
    UnitaryTestsSystem();
    short unitaryTestGetEnergy();
    short unitaryTestSetEnergy();
    short unitaryTestGetLabel();
    short unitaryTestSetLabel();
};

#endif // UNITARYTESTSSYSTEM_H
