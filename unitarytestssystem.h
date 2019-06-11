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

    short unitaryTestAssignmentOperator();
    short unitaryTestCopyConstructor();
};

#endif // UNITARYTESTSSYSTEM_H
