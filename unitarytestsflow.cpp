#include "unitarytestsflow.h"
#include "systemimpl.h"
#include <cassert>
#include <cmath>

class FlowTest : public FlowImpl{
public:
    FlowTest(System* s1, System*s2, string name) : FlowImpl(s1, s2, name){}
    double execute() {return getOrigin()->getEnergy() * 0.02;}
};

UnitaryTestsFlow::UnitaryTestsFlow()
{

}

short UnitaryTestsFlow::UnitaryTestGetOrigin()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl();
    f.origin = s;
    assert(f.getOrigin() == s);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetOrigin()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl();
    f.setOrigin(s);
    assert(f.origin == s);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetDestination()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl();
    f.destination = s;
    assert(f.getDestination() == s);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetDestination()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl();
    f.setDestination(s);
    assert(f.destination == s);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetCurrentEnergy()
{
    FlowTest f(nullptr, nullptr, "-");
    f.currentEnergy = 200;
    assert(fabs(f.getCurrentEnergy() - 200) <= 0.0001);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetCurrentEnergy()
{
    FlowTest f(nullptr, nullptr, "-");
    f.setCurrentEnergy(200);
    assert(fabs(f.currentEnergy - 200) <= 0.0001);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestGetName()
{
    FlowTest f(nullptr, nullptr, "-");
    f.name = "Flow Test";
    assert(f.getName() == "Flow Test");
    return 1;
}

short UnitaryTestsFlow::UnitaryTestSetName()
{
    FlowTest f(nullptr, nullptr, "-");
    f.setName("Test Flow");
    assert(f.name == "Test Flow");
    return 1;
}

short UnitaryTestsFlow::UnitaryTestConnect()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl();
    System* t = new SystemImpl();
    f.connect(s, t);
    assert(f.origin == s);
    assert(f.destination == t);
    delete static_cast<SystemImpl*>(s);
    delete static_cast<SystemImpl*>(t);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestExecute()
{
    FlowTest f(nullptr, nullptr, "-");
    System* s = new SystemImpl(100, "s");
    f.origin = s;
    assert(fabs(f.execute() - 2) <= 0.0001);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestAssignmentOperator()
{
    System* s = new SystemImpl(20, "S");
    FlowTest f(s, s, "f");
    FlowTest g(nullptr, nullptr, "g");
    g = f;
    assert(g.getName() == "f");
    assert(g.getOrigin() == s);
    assert(g.getDestination() == s);
    delete static_cast<SystemImpl*>(s);
    return 1;
}

short UnitaryTestsFlow::UnitaryTestCopyConstructor()
{
    FlowTest f(nullptr, nullptr, "f");
    Flow* g = new FlowTest(f);
    assert(g->getName() == "f");
    delete static_cast<FlowImpl*>(g);
    return 1;
}


