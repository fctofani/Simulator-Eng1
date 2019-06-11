#ifndef UNITARYTESTSFLOW_H
#define UNITARYTESTSFLOW_H

#include "flowimpl.h"

class UnitaryTestsFlow
{
public:
    UnitaryTestsFlow();
    short UnitaryTestGetOrigin();
    short UnitaryTestSetOrigin();
    short UnitaryTestGetDestination();
    short UnitaryTestSetDestination();
    short UnitaryTestGetCurrentEnergy();
    short UnitaryTestSetCurrentEnergy();
    short UnitaryTestGetName();
    short UnitaryTestSetName();

    short UnitaryTestConnect();
    short UnitaryTestExecute();

    short UnitaryTestAssignmentOperator();
    short UnitaryTestCopyConstructor();
};

#endif // UNITARYTESTSFLOW_H
