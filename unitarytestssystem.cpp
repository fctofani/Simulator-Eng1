#include "unitarytestssystem.h"
#include <cassert>
#include <cmath>

UnitaryTestsSystem::UnitaryTestsSystem()
{

}

short UnitaryTestsSystem::unitaryTestGetEnergy()
{
    SystemImpl s;
    s.energy = 100;
    assert(fabs(s.getEnergy() - 100) <= 0.0001);
    return 1;
}

short UnitaryTestsSystem::unitaryTestSetEnergy()
{
    SystemImpl s;
    s.setEnergy(100);
    assert(fabs(s.energy - 100) <= 0.0001);
    return 1;
}

short UnitaryTestsSystem::unitaryTestGetLabel()
{
    SystemImpl s;
    s.label = "Test System";
    assert(s.getLabel() == "Test System");
    return 1;
}

short UnitaryTestsSystem::unitaryTestSetLabel()
{
    SystemImpl s;
    s.setLabel("System Test");
    assert(s.label == "System Test");
    return 1;
}

short UnitaryTestsSystem::unitaryTestAssignmentOperator()
{
    SystemImpl s(300, "A");
    SystemImpl t(600, "B");
    t = s;
    assert(t.getLabel() == "A");
    assert(fabs(t.getEnergy() - 300) <= 0.0001);
    return 1;
}

short UnitaryTestsSystem::unitaryTestCopyConstructor()
{
    SystemImpl s(400, "A");
    SystemImpl t(s);
    assert(t.getLabel() == "A");
    assert(fabs(t.getEnergy() - 400) <= 0.0001);
    return 1;
}


