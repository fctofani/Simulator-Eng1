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


