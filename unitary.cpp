#include "unitary.h"
#include "unitarytestsflow.h"
#include "unitarytestssystem.h"
#include "unitarytestsmodel.h"

#include <iostream>

void systemUnitaryTests()
{
    UnitaryTestsSystem test;

    // Getters and Setters
    test.unitaryTestGetEnergy();
    test.unitaryTestSetEnergy();
    test.unitaryTestGetLabel();
    test.unitaryTestSetLabel();

    cout << "\n System tests passed!" << endl;
}

void flowUnitaryTests()
{
    UnitaryTestsFlow test;

    // Getters and Setters
    test.UnitaryTestGetOrigin();
    test.UnitaryTestSetOrigin();
    test.UnitaryTestGetDestination();
    test.UnitaryTestSetDestination();
    test.UnitaryTestGetCurrentEnergy();
    test.UnitaryTestSetCurrentEnergy();
    test.UnitaryTestGetName();
    test.UnitaryTestSetName();

    // Main Functions
    test.UnitaryTestConnect();
    test.UnitaryTestExecute();

    cout << "\n Flow tests passed!" << endl;
}

void modelUnitaryTests()
{
    UnitaryTestsModel test;

    // Getters and Setters
    test.UnitaryTestsGetName();
    test.UnitaryTestsSetName();
    test.UnitaryTestsGetStart();
    test.UnitaryTestsSetStart();
    test.UnitaryTestsGetFinish();
    test.UnitaryTestsSetFinish();
    test.UnitaryTestsGetFlowContainer();
    test.UnitaryTestsSetFlowContainer();
    test.UnitaryTestsGetSystemContainer();
    test.UnitaryTestsSetSystemContainer();
    test.UnitaryTestsGetFlowContainerBegin();
    test.UnitaryTestsGetFlowContainerEnd();
    test.UnitaryTestsGetSystemContainerBegin();
    test.UnitaryTestsGetSystemContainerEnd();

    // Main Functions
    test.UnitaryTestsAddSystem();
    test.UnitaryTestsAddFlow();

    cout << "\n Model tests passed!" << endl;
}
