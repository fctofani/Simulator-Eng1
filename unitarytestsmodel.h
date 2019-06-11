#ifndef UNITARYTESTSMODEL_H
#define UNITARYTESTSMODEL_H

#include "modelimpl.h"

class UnitaryTestsModel
{
public:
    UnitaryTestsModel();

    short UnitaryTestsGetName();
    short UnitaryTestsSetName();
    short UnitaryTestsGetStart();
    short UnitaryTestsSetStart();
    short UnitaryTestsGetFinish();
    short UnitaryTestsSetFinish();
    short UnitaryTestsGetFlowContainer();
    short UnitaryTestsSetFlowContainer();
    short UnitaryTestsGetSystemContainer();
    short UnitaryTestsSetSystemContainer();
    short UnitaryTestsGetFlowContainerBegin();
    short UnitaryTestsGetFlowContainerEnd();
    short UnitaryTestsGetSystemContainerBegin();
    short UnitaryTestsGetSystemContainerEnd();

    short UnitaryTestsAddSystem();
    short UnitaryTestsAddFlow();
    short UnitaryTestsRun();
    short UnitaryTestsShowResults();

    short UnitaryTestAssignmentOperator();
    short UnitaryTestCopyConstructor();
};

#endif // UNITARYTESTSMODEL_H
