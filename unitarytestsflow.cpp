#include "unitarytestsflow.h"
#include <cassert>
#include <cmath>

class FlowTest : public FlowImpl{
public:
    double execute() {return getOrigin()->getEnergy() * 0.02;}
};

UnitaryTestsFlow::UnitaryTestsFlow()
{

}

short UnitaryTestsFlow::UnitaryTestGetOrigin()
{
    FlowTest f;
    SystemImpl s;
    f.origin = &s;
    assert(f.getOrigin() == &s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetOrigin()
{
    FlowTest f;
    SystemImpl s;
    f.setOrigin(&s);
    assert(f.origin == &s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetDestination()
{
    FlowTest f;
    SystemImpl s;
    f.destination = &s;
    assert(f.getDestination() == &s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetDestination()
{
    FlowTest f;
    SystemImpl s;
    f.setDestination(&s);
    assert(f.destination == &s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetCurrentEnergy()
{
    FlowTest f;
    f.currentEnergy = 200;
    assert(fabs(f.getCurrentEnergy() - 200) <= 0.0001);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetCurrentEnergy()
{
    FlowTest f;
    f.setCurrentEnergy(200);
    assert(fabs(f.currentEnergy - 200) <= 0.0001);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetName()
{
    FlowTest f;
    f.name = "Flow Test";
    assert(f.getName() == "Flow Test");
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetName()
{
    FlowTest f;
    f.setName("Test Flow");
    assert(f.name == "Test Flow");
    return 1;
}

short UnitaryTestsFlow::UnitaryTestConnect()
{
    FlowTest f;
    SystemImpl s, t;
    f.connect(&s, &t);
    assert(f.origin == &s);
    assert(f.destination == &t);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestExecute()
{
    FlowTest f;
    SystemImpl s(100, "s");
    f.origin = &s;
    assert(fabs(f.execute() - 2) <= 0.0001);
    return 1;
}


